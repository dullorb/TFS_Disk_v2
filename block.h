#ifndef BLOCK_ACTIONS_H
#define BLOCK_ACTIONS_H

#include "byte_actions.h"

typedef struct FSblock {
	char byte[16];
} FSblock;

/*
function naming conventions:
"a_" indicates function for FREE (available) blocks
"d_" -> DIRECTORY
"f_" -> FILE
*/

void a_set_next_block_ptr(const int index, FSblock* fb);
int a_get_next_free_block(FSblock fb);

int d_add_subdir_label(const char label, FSblock* fb);
int d_locate_subdir_label(const char label, FSblock fb);
int d_find_empty_subdir_slot(FSblock fb);
int d_add_subdir_address(int address, int index, FSblock* fb);
void d_set_parent_address(int address, FSblock* fb);
void d_set_self_address(int address, FSblock* fb);
int d_get_subdir_address(const char label, FSblock fb);
int d_resolve_subdir_address(const int index, FSblock fb);
int d_get_parent_address(FSblock fb);

void block_to_hex(FSblock fb, char a[32]);
void wipe_block(FSblock*);

void write_byte(const char source, const int index, FSblock* fb);

#endif