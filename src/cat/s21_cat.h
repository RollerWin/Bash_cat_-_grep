#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

void read_console(int first_file_position, int argc, char* argv[]);
void detect_flag(int, char**, char*, FILE*);

void print_error_message(char*);

void line_numbering_funtion(char*, FILE*);
void non_empty_line_numbering_funtion(char*, FILE*);
void dollar_display_function(char*, FILE*);
void string_compression_function(char*, FILE*);
void tab_replacement_function(char*, FILE*);
void default_print_files(char*, FILE*);

enum Cat_flags {
  NON_EMPTY_LINE_NUMBERING_FLAG = 'b',
  DOLLAR_DISPLAY_FLAG = 'e',
  GNU_DOLLAR_DISPLAY_FLAG = 'E',
  LINE_NUMBERING_FLAG = 'n',
  STRING_COMPRESSION_FLAG = 's',
  TAB_REPLACEMENT_FLAG = 't',
  GNU_TAB_REPLACEMENT_FLAG = 'T'
};

#endif