#include <stdio.h>

#include "TFS.h"


int TFS_fb_count_free_blocks(TFS tfs){
	int counter=0;
	return 0;
}

int TFS_fb_next_free_block(int index, TFS tfs){
	
}

void TFS_init(char* source, TFS* tfs){
	if(source == NULL){
		printf("Initializing\n");
	}
	for(int i =0; i<16; i++){
		wipe_block(&(tfs->entry[i]));
		a_set_next_block_ptr(i+1, &(tfs->entry[i]));
	}
	a_set_next_block_ptr(0xff, &(tfs->entry[15]));

}

void TFS_to_hex_array(TFS tfs, char* output){
	char block_hex[512];
	for(int i = 0; i<16; i++){
		block_to_hex(tfs.entry[i], block_hex);
		for(int j=0; j<32;j++){
			output[j + (i*32)] = block_hex[j];
		}
	}
}