#include <stdio.h>
int main () { 
	FILE *fptr;
	int c;
	fptr = fopen("file.dat", "rw+");
	if(fptr == NULL) //if file does not exist, create it
	{
		fptr = fopen("file.dat", "w+");
	}
  
	fputs("This is operating system class code\n", fptr);
	// We are using fseek() to shift the file pointer to the 7th position.
	fseek( fptr, 7, SEEK_SET );

	//Now we overwrite C programming in the 7th position
	fputs(" C Programming", fptr);

	//Now we print the current position of the file pointer using ftell()
	printf("The current position of the file pointer is: %ld\n", ftell(fptr));
	//We take the file pointer to the beginning of the file.
	rewind(fptr);

	//Now we verify if rewind() worked using ftell().
	printf("The current position of the file pointer is: %ld\n", ftell(fptr));
	while(1) { 
		c = fgetc(fptr);
		if( feof(fptr) ) { 
			break;
		}
		printf("%c", c);
	}
	fclose(fptr);
	return(0);
}
