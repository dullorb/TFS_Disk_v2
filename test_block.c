#include <stdio.h>

#include "block.h"
#include "byte_actions.h"

void px_block(char a[32]);

int main(){

	printf("Creating block:\n");
	FSblock fb;

	char output[32];
	block_to_hex(fb, output);
	printf("Unintialized block to hex: \n\t");
	px_block(output);

	printf("Clearing block: \n");
	wipe_block(&fb);
	block_to_hex(fb, output);
	px_block(output);

	char val = 'W';
	printf("Setting byte 1 to value 'W' %d aka 0x57: %x\n", val, val);
	write_byte(val, 1, &fb);
	block_to_hex(fb, output);
	px_block(output);

	int index;
	printf("Finding empty label slot, should be index '1':");
	index = d_find_empty_subdir_slot(fb);
	printf("slot index: %d\n", index);

	printf("Search for existing directory W at index 0: ");
	index = d_locate_subdir_label(val, fb);
	printf(" found at index %d\n", index);

	val ='X';
	printf("Fail to find directory X : ");
	index = d_locate_subdir_label(val, fb);
	printf(" found at index %d\n", index);
	printf("Now find X at index 1: ");
	write_byte(val, 2, &fb);
	index = d_locate_subdir_label(val, fb);
	block_to_hex(fb, output);
	px_block(output);
	printf(" found at index %d\n", index);


	printf("Refuse to add X a second time: ");
	index = d_add_subdir_label(val, &fb);
	printf(" status should be -2: %d\n", index);

	printf("Fill other 8 slots\n");
	d_add_subdir_label('A', &fb);
	d_add_subdir_label('B', &fb);
	d_add_subdir_label('C', &fb);
	d_add_subdir_label('D', &fb);
	d_add_subdir_label('E', &fb);
	d_add_subdir_label('F', &fb);
	d_add_subdir_label('G', &fb);
	d_add_subdir_label('H', &fb);
	block_to_hex(fb, output);
	px_block(output);
	
	printf("Fail to add to full directory: ");
	index = d_add_subdir_label('K', &fb);
	printf("status %d\n", index);

	printf("Writing arbitrary addresses\n");
	d_add_subdir_address(15, 0, &fb);
	d_add_subdir_address(14, 1, &fb);
	d_add_subdir_address(13, 2, &fb);
	d_add_subdir_address(12, 3, &fb);
	d_add_subdir_address(11, 4, &fb);
	d_add_subdir_address(10, 5, &fb);
	d_add_subdir_address(9, 6, &fb);
	d_add_subdir_address(8, 7, &fb);
	d_add_subdir_address(7, 8, &fb);
	d_add_subdir_address(6, 9, &fb);
	d_add_subdir_address(5, 10, &fb);
	block_to_hex(fb, output);
	px_block(output);

	printf("Setting first block addresses\n");
	d_set_parent_address(6, &fb);
	d_set_self_address(14, &fb);
	block_to_hex(fb, output);
	px_block(output);

	printf("Check sub directory addresses\n");
	for(int i =0; i<10;i++){
		val = d_resolve_subdir_address(i, fb);
		printf("[%d,%d] ", i, val);
		if(!((i+1)%5)){printf("\n");}
	}

	printf("Find folder 'W'\n");
	val = d_get_subdir_address('W', fb);
	printf("adress of W = %d\n", val);


	val = d_get_parent_address(fb);
	printf("adress of parent = %d", val);


	printf("\n--------------------------------------------------\n");
	printf("----------END DIRECTORY FUNCTION TESTING----------\n");
	printf("--------------------------------------------------\n\n\n");
	printf("--------------------------------------------------\n");
	printf("------------START FILE FUNCTION TESTING-----------\n");
	printf("--------------------------------------------------\n");


	wipe_block(&fb);
	block_to_hex(fb, output);
	px_block(output);

	a_set_next_block_ptr(12,&fb);
	block_to_hex(fb, output);
	px_block(output);

}















void px_block(char a[32]){
	//output in pure hex
	for(int i =0; i<32; i+=2){
		printf("%c%c ", a[i], a[i+1]);
	}
	putchar('\n');
}
