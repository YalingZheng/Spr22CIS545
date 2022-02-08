
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
    printf("before fork ");
    	// make two process which run same
    // program after this instruction
    fork();
  
    printf("Hello world!\n\n");
    return 0;
}
