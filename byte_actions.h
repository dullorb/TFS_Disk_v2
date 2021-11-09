#ifndef BYTE_ACTIONS_H
#define BYTE_ACTIONS_H


void write_left_byte(char value, char* destination);
void write_right_byte(char value, char* destination);

void read_byte_alpha(const char b, char* destination);
void read_byte_hex(const char b, char* destination);
void read_left_bits(const char b, char* destination);
void read_right_bits(const char b, char* destination);

char int_to_hex(int i);

#endif