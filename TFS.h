#ifndef TFS_H
#define TFS_H

#include "block.h"


typedef struct TFS {
	FSblock entry[16];
} TFS;

void test(char* r_val);

void TFS_init(char* source, TFS* tfs);
void TFS_to_hex_array(TFS tfs, char* output);

int TFS_fb_count_free_blocks(TFS tfs);

#endif