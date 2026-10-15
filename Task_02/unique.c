#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

//Function_call: Reads input line by line and prints
//only the first occurrence of consecutive identical lines.
void uniq_fun(FILE *fp){
	char *prev = NULL;
        char *curr = NULL;
        size_t prev_cap = 0;
        size_t curr_cap = 0;
        ssize_t byte_read =0;
	
	//Reads the first line from the input stream
        byte_read = getline(&prev, &prev_cap, fp);
        
	if (byte_read != -1){
		
		//Prints the first line since there is nothing to compare
		fprintf(stdout, "%s", prev);
        
	//Reads each remaining line until EOF or a read error
	while(getline(&curr, &curr_cap, fp) != -1){
		
		//Checks if the current line is different then the previous line
                if(strcmp(prev, curr) != 0){
			//Prints the line if its not a duplicate
			fprintf(stdout, "%s", curr);
			
			//Swaps the pointers to set current to previous 
			char *temp = prev;
			prev = curr;
			curr = temp;

                	//Swaping the capacities to set current to previous
                	size_t temp_cap = prev_cap;
                	prev_cap = curr_cap;
                	curr_cap = temp_cap;
                	}
        	}
	}
	//Release the kraken.... oh I mean buffers
        free(prev);
        free(curr);

}	
//Main: Checks command line arguments, selects the input stream, runs uniq_fun, 
//and closes the input file
int main (int argc, char *argv[]){
	FILE *fp;
	//Rejects more then two arguments
	if(argc > 2){
                printf("To many arguments entered");
                return 1;
        }
	//Reads from std input if no file is provided 
	if (argc == 1) {
		fp = stdin;
	}
	else{
	//Opens the file for reading only
	fp = fopen(argv[1], "r");

		//Exits if the file could not be opened.	
		if (fp == NULL){
        	printf("error opening flle\n");
        	return 1;
        	}
	}
         	//Takes in the file and removes consecutive duplicate lines
		uniq_fun(fp);
	//Closes the file.
	fclose(fp);

return 0;
}
