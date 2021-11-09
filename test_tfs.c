#include <stdio.h>
#include "TFS.h"



void print_tfs(char*);

int main(){
	TFS tfs;
	char hex[512];
	TFS_init(NULL, &tfs);

 	TFS_to_hex_array(tfs, hex);
	print_tfs(hex);
}


void print_tfs(char* a){
	int index = 0;
	for(int i =0; i<16; i++){
		for(int j=0; j<32; j +=2){
			index = j + (i*32);
			printf("%c%c ", a[index], a[index+1]);
		}
		putchar('\n');
	}
}