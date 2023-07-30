#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

// void read_console(int first_file_position, int argc, char* argv[]);
// void detect_flag(int, char**, char*, FILE* );

// void choose_error_stream(int, char* );
// char* build_error_message(char*, char*);
// void print_default_error_message(char* error_message);
// void print_flag_error_message(char* error_message);

// void line_numbering_funtion(char*, FILE*);
// void non_empty_line_numbering_funtion(char*, FILE*);
// void dollar_display_function(char*, FILE*);
// void string_compression_function(char*, FILE*);
// void tab_replacement_function(char*, FILE*);
// void default_print_files(char*, FILE*);

typedef struct{
    int template_flag_e;
    int case_insensitive_flag_i;
    int inverted_search_flag_v;
    int match_counter_flag_c;
    int matching_files_flag_l;
    int line_numbering_flag_n;
    int file_ignore_flag_h;
    int error_ignore_flag_s;
    int regex_file_flag_f;
    int matching_sequence_flag_o;
}flags;

enum flag_names {
    TEMPLATE_FLAG = 'e',
    CASE_INSENSITIVE_FLAG = 'i',
    INVERTED_SEARCH_FLAG = 'v',
    MATCH_COUNTER_FLAG = 'c',
    MATCHING_FILES_FLAG = 'l',
    LINE_NUMBERING_FLAG = 'n',
    FILE_IGNORE_FLAG = 'h',
    ERROR_IGNORE_FLAG = 's',
    REGEX_FILE_FLAG = 'f',
    MATCHING_SEQUENCE_FLAG = 'o'
};

#endif