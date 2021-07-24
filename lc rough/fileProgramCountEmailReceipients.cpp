#include <stdio.h> 
#include <stdlib.h> // For exit() 

int main() 
{ 
	FILE *fptr; 

	char filename[100], c; 

	printf("Enter the filename to open \n"); 
	scanf("%s", filename); 

	// Open file 
	fptr = fopen(filename, "r"); 
	if (fptr == NULL) 
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	} 
	int count = 1;
	// Read contents from file 
	c = fgetc(fptr);
	 
	while (c != EOF) 
	{ 
		if(c==','){
			count++;
		}
		c = fgetc(fptr); 
	} 

	fclose(fptr); 
	printf("%d",count);
	return 0; 
}

