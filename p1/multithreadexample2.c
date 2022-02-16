#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

#ifndef NUM_THREADS
#define NUM_THREADS 8	
#define n 12
#endif

pthread_mutex_t lock;

struct arg_struct {
	int threadindex;
    int beginnum;
    int endnum;
};

double resultArray[NUM_THREADS] = {0};

void* computeSqrt(void* args) { // int thread_index, int beginnum, int endnum
	struct arg_struct *args1 = args;
	int threadindex = args1->threadindex;
	int beginnum = args1->beginnum;
	int endnum = args1->endnum;
	double sumresult = 0;
	for (int i=beginnum; i<=endnum;i++){
		sumresult += pow(i, 0.5);
	}	
	resultArray[threadindex] = sumresult;
	printf("Thread %d Summation of sqrt(%d) to sqrt(%d) =  %f\n", threadindex, beginnum, endnum, resultArray[threadindex]);
	
}

void printThreadStatus(int ret, void* retval){
	if (retval == PTHREAD_CANCELED){
		printf("The thread was canceled - ");
	} else {		
		printf("Returned value %d - ", ret);
	}

	switch (ret) {
		case 0:
			printf("The thread joined successfully\n");
			break;
		case EDEADLK:
			printf("Deadlock detected\n");
			break;
		case EINVAL:
			printf("The thread is not joinable\n");
			break;
		case ESRCH:
			printf("No thread with given ID is found\n");
			break;
		default:
			printf("Error occurred when joining the thread\n");
	}
}

void *doNothing(){
	
};

pthread_t joinThread(pthread_t thread1, pthread_t thread2, int thread1index, int thread2index, bool printThreadsFlag){
	void *retval1, *retval2;
	int ret1, ret2;
	ret1 = pthread_join(thread1, retval1);
	ret2 = pthread_join(thread2, retval2);
	if (printThreadsFlag==true){
		printThreadStatus(ret1, retval1);
		printThreadStatus(ret2, retval2);
	}
	// add two threads final result resultArray[thread1index] + resultArray[thread2index]
	// result saved to resultArray[thread2index]
	resultArray[thread1index] += resultArray[thread2index];
	return pthread_create(&thread1, NULL, doNothing, NULL);
}



int main(int argc, char const *argv[]) {
	
    pthread_t threads[NUM_THREADS];

	struct arg_struct* args[NUM_THREADS]; 
	
	// multiple threads running at the same time
    for (int t = 0; t < NUM_THREADS; t++) {		
		args[t] = malloc(sizeof(struct arg_struct) * 1);
		resultArray[t] = 0;		
		int beginnum = floor(t*n/NUM_THREADS) + 1;
		int endnum = floor((t+1)*n/NUM_THREADS);
		//args[t] = malloc(sizeof(struct arg_struct) * 1);
		args[t]->threadindex = t;
		args[t]->beginnum = beginnum;
		args[t]->endnum = endnum;
		//printf("call create thread %d  beginnum=%d   endnum=%d \n", t, beginnum, endnum);
        int rc = pthread_create(&threads[t], NULL, &computeSqrt, (void *)args[t]);
		
		
        if (rc) {
            printf("ERORR; return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }	
   }

	if (NUM_THREADS == 8){
		// In the first reduction step, in order to add two
		//elements in the array, thread 4 should wait for thread 0 done, thread 5 has to wait for thread 1 done, threads 6
		//needs to wait for thread 2 done, and thread 7 should wait for thread 3 done.
		threads[4] = joinThread(threads[4], threads[0], 4, 0, true);		
		threads[5] = joinThread(threads[5], threads[1], 5, 1, true);
		threads[6] = joinThread(threads[6], threads[2], 6, 2, true);		
		threads[7] = joinThread(threads[7], threads[3], 7, 3, true);	

		//In the second reduction step, thread 6
	    //waits for thread 4 finished, and thread 7 waits for thread 5 finished. In the third step, thread 7 waits for thread 6
        //done and then prints the the whole array.
		threads[6] = joinThread(threads[6], threads[4], 6, 4, false);
		threads[7] = joinThread(threads[7], threads[5], 7, 5, false);	
		
		// In the third reduction step, thread 7 waits for thread 6 instead 
		threads[7] = joinThread(threads[7], threads[6], 7, 6, false);
		
		printf("final result: %f\n", resultArray[7]);
	}
	
    pthread_exit(NULL);

}
