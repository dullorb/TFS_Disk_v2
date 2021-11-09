#include "user_input.h"

int read_keyboard(char* input){
	char incoming;
	int i =0;

	do{
		incoming = fgetc(stdin);
		input[i] = incoming;
		
		if(incoming == 10){
			input[i] = '\0';
			return 0;
		}
		i++;
	}while( i<MAX_BUFFER_LENGTH );

	strcpy(input, "buffer exceeded");
	return -1;
}

void tokenize_input(char* in, char out[MAX_ARGS_ALLOWED][MAX_BUFFER_LENGTH]){
	char* arg;
	int counter=0;

	out[1][0] = '\0';
	out[2][0] = '\0';

	arg = strtok(in, " ");
	while(counter< MAX_ARGS_ALLOWED && arg != NULL){
		strcpy(out[counter],arg);
		//printf("arg#%d = %s\n", counter, arg);
		counter++;
		arg = strtok(NULL, " ");
	}
}