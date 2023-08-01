#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <regex.h>

void choose_error_stream(int first_file_position, char* argv);
void print_default_error_message(char* error_message);
void print_flag_error_message(char* error_message);
char* build_error_message(char* file_name, char* error_message);


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

flags detect_flags(int, char**, char*, flags);
void indicate_each_flag(int, char*, flags*);
void edit_templates(int*, char**, char*, flags);
void print_strings(int, int, char**, char*, flags);
void open_reg_file(char*, char*, flags);

void detect_multifile(int, int, int*);
void detect_insensitive_flag(flags, int*);
void detect_invert_flag(flags, int*);
void print_file_name(int, int, flags, char**);
void read_and_print_strings(int i, int is_multifile, int* counter, char*argv[], FILE* user_file, regex_t reg, flags input_flags);


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