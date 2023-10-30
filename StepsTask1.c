#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
char delimiter[] = ",";
char line[500]; 
char steps[100];
int i=0,j=0;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
	//	open the file  
	FILE * fp ;
	fp = fopen("Fitnessdata_2023.csv","r");
	
	if (fp == NULL) {  
        printf("Error: Unable to open input file.\n");  
        return 1;
		}

//	convert data and store them in the struct array
    FITNESS_DATA file[10000];
    while (fgets(line, sizeof(line), fp) != NULL) {  
		tokeniseRecord(line, delimiter, file[i].date, file[i].time, steps);
		file[i].steps = atoi(steps);
		i++;
   }

//	output the first three lines
	for(j=0;j<3;j++){
		printf("Date: %s\n", file[j].date);
		printf("Time: %s\n", file[j].time);
		printf("Steps: %d\n", file[j].steps);
	} 
    fclose(fp);
        
	return 0;

}
