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
    printf("after main    ");
    forkexample();
    printf("after 1st fork    ");
    forkexample();
    printf("after 2nd fork   ");
    forkexample();
    return 0;
}
