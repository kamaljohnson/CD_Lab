#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* readFile(char* filename);	//reads the file and returns the string in the file
void extractTokens(char* tokens[], char* str);	//read the string and extracts the tokens from the string

void main() {
	char* str = readFile("file.text");

	printf("data in the file: %s\n", str);
}

char* readFile(char* filename) {
	printf("\n----------------------------/reading from %s/\n", filename);
	char* str;
	
	/* declare a file pointer */
	FILE    *file;
	long    numbytes;
	
	/* open an existing file for reading */
	file = fopen(filename, "r");

	/* quit if the file does not exist */
	if(file == NULL){
		printf("the file does not exist\n");
		return 0;
	}
	
	/* Get the number of bytes */
	fseek(file, 0L, SEEK_END);
	numbytes = ftell(file);
	printf("number of bytes : %ld\n", numbytes);
	
	/* reset the file position indicator to 
	the beginning of the file */
	fseek(file, 0L, SEEK_SET);	
	
	str = (char*)calloc(numbytes, sizeof(char));
	fread(str, sizeof(char), numbytes, file);
	fclose(file);
	printf("----------------------------/reading completed/\n");
	return str;
}

void extractTokens(char* tokens[], char* str){

}