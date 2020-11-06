#ifndef _GRIZZLY
#define _GRIZZLY

#include "grizzly.c"

int title_align();
void set_window();
void paint_window();
void gotoxy(int x, int y);
int center_this(char content[]);
void center_print(char text[], int Y);
void repeat_program(int main_function(), char message[], int Y);
void error_identifier(char errorID[], int X, int Y);
void error_msg(char error_text[], int Y);
bool only_numbers(char input[], char numbers_range);
bool only_letters(char input[]);

#endif // !_GRIZZLY
