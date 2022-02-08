
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int globalcounter = 0;
int main()
{ 
    printf("Hello World\n");
    int localcounter = 0;
    printf("before fork globalcounter=%d localcounter=%d\n", globalcounter++, localcounter);
    	// make two process which run same
    // program after this instruction
    int result = fork();
  
    printf("result is %d\n", result);
    printf("End of the program\n");
    return 0;
}
