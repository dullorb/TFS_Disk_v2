#include <stdio.h>
#include <string.h>

#define MAX_ARGS_ALLOWED 3
#define MAX_BUFFER_LENGTH 100

int read_keyboard(char*);
void tokenize_input(char* in, char out[MAX_ARGS_ALLOWED][MAX_BUFFER_LENGTH] );


