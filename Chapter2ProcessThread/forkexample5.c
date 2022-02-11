
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forkexample()
{
    // child process because return value zero
    if (fork() == 0)
        printf("%d as Child! parent is %d\n", getpid(), getppid());
  
    // parent process because return value non-zero.
    else
        printf("%d as Parent!\n", getpid());
}
int main()
{
    printf("before 1st fork    ");
    forkexample();
    printf("before 2nd fork    ");
    forkexample();
    printf("before 3rd fork   ");
    forkexample();
    //printf("end of main\n");
    return 0;
}
