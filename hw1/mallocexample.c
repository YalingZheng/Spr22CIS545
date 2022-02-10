#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int *ptr, *ptr1, *ptr2;
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
	
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL || ptr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
		printf("Address of n (an integer): %p\n", &n);
		printf("Address of ptr (pointer to five integers): %p\n", ptr);
		printf("Address of ptr1 (pointer to one integer): %p\n", ptr1);
		printf("Address of ptr2: %p\n", ptr2);
	
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