#include <stdio.h>
#include "s21_grep.h"

int main(int argc, char* argv[]) {
    int flag;
    flags input_flags = {0};

    char template_words[10000];

    while ((flag = getopt_long(argc, argv, "e:f:ivclnhso", NULL, 0)) != -1)
    {
        switch(flag) {
            case TEMPLATE_FLAG:
            input_flags.template_flag_e = 1;
            break;

            case CASE_INSENSITIVE_FLAG:
            input_flags.case_insensitive_flag_i = 1;
            break;

            case INVERTED_SEARCH_FLAG:
            input_flags.inverted_search_flag_v = 1;
            break;
            
            case MATCH_COUNTER_FLAG:
            input_flags.match_counter_flag_c = 1;
            break;

            case MATCHING_FILES_FLAG:
            input_flags.matching_files_flag_l = 1;
            break;

            case LINE_NUMBERING_FLAG:
            input_flags.line_numbering_flag_n = 1;
            break;

            case FILE_IGNORE_FLAG:
            input_flags.file_ignore_flag_h = 1;
            break;

            case ERROR_IGNORE_FLAG:
            input_flags.error_ignore_flag_s = 1;
            break;

            case REGEX_FILE_FLAG:
            input_flags.regex_file_flag_f = 1;
            break;

            case MATCHING_SEQUENCE_FLAG:
            input_flags.matching_sequence_flag_o = 1;
            break;
        }
    }
    
    return 0;
}
