#include <stdio.h>
#include "byte_actions.h"


int main(){
	char source = 'A';
	char target;
	char hex_pair[2];

	printf("Testing read byte alpha: %c\n", source);
	read_byte_alpha(source, &target);
	printf("-Result read byte alphe: %c\n\n", target);

	int val = 0xaa;
	source = val;
	printf("Testing read left bits: %d <=[ (10 * 2^4) + (10 * 2^0)]\n", val);
	read_left_bits(source, &target);
	printf("-Result read left bits: %d\n\n", target);

	printf("Testing read right bits: %d <=[ (10 * 2^4) + (10 * 2^0)]\n", val);
	read_right_bits(source, &target);
	printf("-Result read right bits: %d\n\n", target);

	
	int lvals[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	printf("Testing int to hex\n");
	for(int i =0; i<16;i++){
		printf("%d => %c, \t", lvals[i], int_to_hex(lvals[i]));
		if(!((i+1)%4)){ putchar('\n');}
	}
	printf("end\n");


	printf("Testing --byte to hex: %d <=[ (10 * 2^4) + (10 * 2^0)]\n", val);
	read_byte_hex(source, hex_pair);
	printf("Result %c%c\n\n", hex_pair[0], hex_pair[1]);
	
	printf("Test writing left and right\n");
	target = 0;
	
	for(int i = 0; i<16; i++){
		write_left_byte(i,&target);
		read_left_bits(target, &source);
		printf("leftbits %c\n", int_to_hex(source));
	}
	
}