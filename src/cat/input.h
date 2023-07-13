#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

void read_console(int first_file_position, int argc, char* argv[]);
void detect_flag(int, char**, char*, FILE* );

void choose_error_stream(int, char* );
char* build_error_message(char*, char*);
void print_default_error_message(char* error_message);
void print_flag_error_message(char* error_message);

void line_numbering_funtion(char*, FILE*);
void non_empty_line_numbering_funtion(char*, FILE*);
void dollar_display_function(char*, FILE*);
void string_compression_function(char*, FILE*);
void tab_replacement_function(char*, FILE*);
void default_print_files(char*, FILE*);

enum Cat_flags {
  NON_EMPTY_LINE_NUMBERING_FLAG = 'b',
  DOLLAR_DISPLAY_FLAG = 'e',
  LINE_NUMBERING_FLAG = 'n',
  STRING_COMPRESSION_FLAG = 's',
  TAB_REPLACEMENT_FLAG = 't',
};




#endif
