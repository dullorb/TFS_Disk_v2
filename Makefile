all: clean go

go : main.o block.o byte_actions.o user_input.o
	cc -o go main.o block.o byte_actions.o user_input.o

main.o : main.c user_input.o block.o byte_actions.o
	cc -c main.c 

block.o : block.c block.h
	cc -c block.c

byte_actions.o : byte_actions.c byte_actions.h
	cc -c byte_actions.c

user_input.o : user_input.c user_input.h
	cc -c user_input.c
	
clean :
	rm -f *.o *_test go

byte : 
	cc test_byte_act.c byte_actions.c -o byte_test

block :
	cc test_block.c block.c byte_actions.c -o block_test

tfs :
	cc test_tfs.c TFS.c block.c byte_actions.c -o tfs_test
