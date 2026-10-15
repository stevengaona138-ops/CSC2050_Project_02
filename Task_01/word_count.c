#include <stdio.h>

//Function call: Counts the characters, words, and lines from an input steam.
void wordC_fun(FILE *fp, int *characters, int *words, int *lines){
	int ch; 
	int position = 0; //0 is reading words 1 is not reading words

	//Reads characters until the End Of File (EOF) is reached.
 	for(;(ch = fgetc(fp)) != EOF;){
                //Counts each character read
		(*characters)++;
		
		//Counts newline characters 
                if(ch == '\n'){
                (*lines)++;
        }
	//Checks if we are reading words or not
        if(ch == ' ' || ch == '\n'){
                position = 0;
        }
        else{
		//Counts a word with process of reading words starts again
                if(position == 0){
                (*words)++;
                position = 1;
                }
	}
	}
}
//Main: Checks argument inputs, calls function, and prints results.
int main(int argc, char *argv[]){
	FILE *fp;
	int characters = 0;
	int words = 0;
	int lines = 0; 
	
	//Checks command line argument count
	if(argc > 2){
	printf("Too many arguments/n");
	return 1;
	}
	
	//Opens the file for reading only if there are two arguments 
	if(argc == 2){
	fp = fopen(argv[1], "r");
		
		//Checks if the file was open correctly 
		if (fp == NULL){
		printf("Error opening file\n");
		return 1;
		}		
	}
	else{
	//Uses std input when no filename is given
	fp = stdin;
	}
	//Counts characters, words, and lines
	wordC_fun(fp, &characters, &words, &lines);
	
	//Displays the results
	printf("  %d  %d %d %s\n", lines, words, characters, argv[1]);

	//Close the file
	fclose(fp);
	

	return 0;
}

