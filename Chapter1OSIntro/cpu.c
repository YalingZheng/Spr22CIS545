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
	   if (end-begin >= 1000){
		   break;
	   }	  
   }
	
   return;
}

 int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: cpu <string>\n");
		exit(1);
	}
	char *str = argv[1];
	while (1) {
		Spin(1);
		printf("%s\n", str);
	}
	return 0;
 }
