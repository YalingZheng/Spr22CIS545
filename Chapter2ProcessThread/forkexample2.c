
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int globalcounter = 0;
int main()
{
    int localcounter = 0;
    printf("before fork globalcounter=%d localcounter=%d ", globalcounter++, localcounter);
    	// make two process which run same
    // program after this instruction
    int result = fork();
  
    printf("result is %d\n", result);
    printf("end of the program\n");
    return 0;
}
