#include "block.h"
#include <stdio.h>


/*
function naming conventions:
"a_" indicates function for FREE (available) blocks
"d_" -> DIRECTORY
"f_" -> FILE
*/


void a_set_next_block_ptr(const int index, FSblock* fb){
	read_byte_alpha(index,&(fb->byte[0]));
}

int a_get_next_free_block(FSblock fb){
	char address;
	return address;
}

int d_get_parent_address(FSblock fb){
	char parent_address;
	read_left_bits(fb.byte[0], &parent_address);
	return parent_address;
}


int d_get_subdir_address(const char label, FSblock fb){
	int index = d_locate_subdir_label(label, fb);
	char address;
	if(index < 0){
		return -1;
	}
	
	address = d_resolve_subdir_address(0, fb);
	return address;
}

int d_resolve_subdir_address(const int index, FSblock fb){
	char address;
	int adjusted_index = (index/2) + 11;
	int right_side = index%2;

	if(right_side){
		read_right_bits(fb.byte[adjusted_index], &address);
	} else {
		read_left_bits(fb.byte[adjusted_index], &address);
	}
	
	return address;
}


void d_set_parent_address(int address, FSblock* fb){
	write_left_byte(address, &(fb->byte[0]));
}

void d_set_self_address(int address, FSblock* fb){
	write_right_byte(address, &(fb->byte[0]));
}

int d_add_subdir_address(int address, int index, FSblock* fb){
	int right_side = index%2;
	int adjusted_index = index /2 + 11;
		if(right_side){
		write_right_byte(address, &(fb->byte[adjusted_index]));
	} else {
		write_left_byte(address, &(fb->byte[adjusted_index]));
	}

	return 0;
}

int d_add_subdir_label(const char label, FSblock* fb){
	if(d_locate_subdir_label(label, *fb) >= 0){
		return -2;	
	}
	int slot = d_find_empty_subdir_slot(*fb);
	if(slot < 0){
		return slot;
	}
	write_byte(label, slot+1, fb);
	return 0;
}

int d_locate_subdir_label(const char label, FSblock fb){
	int index =-1;
	for(int i=1; i<11; i++){
		if(fb.byte[i]==label){
			return i-1; //adjust index to 0 index
		}
	}
	return index;
}

int d_find_empty_subdir_slot(FSblock fb){
	for( int i =1; i<11; i++){
		if(fb.byte[i] == 0){
			return i-1; //adjust index to 0 index
		}
	}
	return -1;
}

void block_to_hex(FSblock fb, char a[32]){
	for(int i=0; i<=16; i++){
		read_byte_hex(fb.byte[i], &a[i*2]);
	}
}

void wipe_block(FSblock* fb){
	for(int i =0; i<16; i++){
		fb->byte[i]=0;
		read_byte_alpha(0, &(fb->byte[i]));
	}
}

void write_byte(const char source, const int index, FSblock* fb){
	read_byte_alpha(source, &(fb->byte[index]));
}

