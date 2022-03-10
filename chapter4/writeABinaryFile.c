#include <stdio.h>
#include <stdlib.h>
/* Our structure */
struct rec
{
	int x,y,z;
};
	
int main () { 
	FILE *fptr;
	int result = 0;
	// refer https://pubs.opengroup.org/onlinepubs/007904975/functions/fopen.html
	fptr = fopen("file.bin", "rb+");
	if(fptr == NULL) //if file does not exist, create it
	{
		fptr = fopen("file.bin", "wb+");
	}
	
	char str[] = "\nThis is a binary file example\n";
	size_t element_size = sizeof *str;

	/* Writes str (_including_ the NUL-terminator) to the binary file. */
	size_t elements_written = fwrite(str, element_size, sizeof(str), fptr); 
	struct rec my_record;
	for (int i=1; i<100; i++){
		my_record.x = i;
		fwrite(&my_record,sizeof(struct rec),1,fptr);
	}
	elements_written = fwrite(str, element_size, sizeof(str), fptr); 
	fclose(fptr);
	return result;
	
	
}
