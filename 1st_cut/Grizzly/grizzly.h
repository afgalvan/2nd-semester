#ifndef _GRIZZLY
#define _GRIZZLY

#include <stdio.h> // The C standard library for in and out
#include <string.h> // C library for strings managament
#include <stdbool.h> // C library for boolean operations
#include <stdlib.h> // C standard library for main functions 
#include <ctype.h> //
#include "grizzly.c"

int title_align();
void gotoxy(int x, int y);
void center_print(char text[], int centered);
void repeat_program(int main_function(), int Y);
void error_identifier(char errorID[], int X, int Y);
void error_msg(char error_text[], int Y);
bool only_numbers(char input[], char numbers_range);
bool only_letters(char input[]);

#endif // !_GRIZZLY
