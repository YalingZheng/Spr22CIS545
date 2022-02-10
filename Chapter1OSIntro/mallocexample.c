#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int *ptr, *ptr1, *ptr2, *ptr3, *ptr4;
    int n, i;
 
    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
	
	// Dynamically allocate memory using calloc()
    ptr1 = (int*)calloc(1, sizeof(int));
 
    // Dynamically allocate memory using calloc()
    ptr2 = (int*)calloc(n, sizeof(int));
	
	*ptr2 = 3;
	
	*(ptr2+1) = 4;
	
	ptr3 = (int*)malloc(n * n * sizeof(int));
	
	ptr4 = (int*)calloc(1, sizeof(int));
	
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL || ptr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
		printf("Storage size for int is %d int_min %d   int_max  %d \n",(int)sizeof(int), INT_MIN, INT_MAX);
		printf("Address of n (an integer): %p\n", &n);
		printf("Address of ptr (pointer to five integers): %p\n", ptr);
		printf("Address of ptr1 (pointer to one integer): %p\n", ptr1);
		printf("Address of ptr2 (pointer to five integers): %p\n", ptr2);
		printf("Address of ptr3 (pointer to 25 integers): %p\n", ptr3);
		printf("Address of ptr4 (pointer to one integer): %p\n", ptr4);
		
		printf("address %p's content = %d\n", ptr2, *ptr2);
		printf("address %p's content = %d\n", ptr2+1, *(ptr2+1));
		
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Free the memory
        free(ptr);
        printf("Malloc Memory successfully freed.\n");
 
        // Memory has been successfully allocated
        printf("\nMemory successfully allocated using calloc.\n");
 
        // Free the memory
        free(ptr1);
        printf("Calloc Memory successfully freed.\n");
    }
 
    return 0;
}