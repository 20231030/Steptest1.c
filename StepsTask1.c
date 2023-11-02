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
char line[500]; 
int i=0,j=0;
char steps[6];

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
    // Open the file  
    FILE* fp = fopen("FitnessData_2023.csv", "r");
    if (fp  == NULL) {  
        printf("Error: Unable to open input file.\n");  
        return 1;  
    }
    // Convert data and store them in the struct array  
    FITNESS_DATA file[5000];  
    while (fgets(line, sizeof(line), fp ) != NULL) {  
        // Parse the line  
        tokeniseRecord(line, ",", file[i].date, file[i].time, steps);  
        file[i].steps = atoi(steps);  
        i++;  
    }
    // Output the first three lines  
    for (j = 0; j < 3; j++) {  
        printf("%s/%s/%d", file[j].date, file[j].time, file[j].steps);  
        printf("\n");  
    }
    // Close the file  
    fclose(fp);
    return 0;  

}
