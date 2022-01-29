#include <stdio.h>
#include <stdlib.h>

int x;          

int main(void) 
{
    int y;   
    char *str; 

    y = 4;
    printf("stack memory: %d\n", y);

    str = malloc(100*sizeof(char)); 
    str[0] = 'm';
    printf("heap memory: %c\n", str[0]); 
    free(str);         
    return 0;
}