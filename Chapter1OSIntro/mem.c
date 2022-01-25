#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
// #include "common.h"

/*
* Constantly check time and repeatedly check the time
* and returns once it has run for a second
*/
void Spin(){
   time_t begin = time(NULL);
   
   while (1) {
	   time_t end = time(NULL);
	   if (end-begin >= 1){
		   break;
	   }	  
   }
	
   return;
}

int main(int argc, char *argv[]) {
	int *p = malloc(sizeof(int)); // a1
	assert(p != NULL);
	printf("(%d) address pointed to by p: %p\n",
	getpid(), p); // a2
	*p = 0; // a3
	while (1) {
		Spin(1);
		*p = *p + 1;
		printf("(%d) p: %d\n", getpid(), *p); // a4
	}
	return 0;
 }