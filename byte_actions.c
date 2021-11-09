#include "byte_actions.h"
#include <stdio.h>


void write_left_byte(char value, char* destination){
	int preserve_right = destination[0] & 0xf;
	int left_side_value = value <<4;
	destination[0] = preserve_right | left_side_value;
}

void write_right_byte(char value, char* destination){
	char left_side = destination[0] & 0xf0;
	destination[0] = value | left_side;
}


void read_byte_alpha(const char b, char* destination){
	destination[0] = b;
}

void read_byte_hex(const char b, char* destination){
	read_left_bits(b, &destination[0]);
	destination[0] = int_to_hex(destination[0]);
	read_right_bits(b, &destination[1]);
	destination[1] = int_to_hex(destination[1]);
	
}

void read_left_bits(const char b, char* destination){
	destination[0]= ( b>>4) & 0xf;
}

void read_right_bits(const char b, char* destination){
	destination[0]= ( b & 0x0000000f);
}

char int_to_hex(int i){
	if(i >=0 && i<= 9){
		return i+48;
	}
	if(i >0 && i <=15){
		return i+55;
	}
	return 0;
}