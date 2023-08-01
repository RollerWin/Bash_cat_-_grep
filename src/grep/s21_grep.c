#include "s21_grep.h"

#include <string.h>

const int text_string_length = 10240;

flags detect_flags(int argc, char* argv[], char* template_words,
                   flags input_flags) {
  int flag;
  strcpy(template_words, "");
  while ((flag = getopt_long(argc, argv, "e:f:ivclnhso", NULL, 0)) != -1) {
    indicate_each_flag(flag, template_words, &input_flags);
  }
  return input_flags;
}

void indicate_each_flag(int flag, char* template_words, flags* input_flags) {
  switch (flag) {
    case TEMPLATE_FLAG:
      input_flags->template_flag_e = 1;
      strcat(template_words, optarg);
      strcat(template_words, "|");
      break;

    case CASE_INSENSITIVE_FLAG:
      input_flags->case_insensitive_flag_i = 1;
      break;

    case INVERTED_SEARCH_FLAG:
      input_flags->inverted_search_flag_v = 1;
      break;

    case MATCH_COUNTER_FLAG:
      input_flags->match_counter_flag_c = 1;
      break;

    case MATCHING_FILES_FLAG:
      input_flags->matching_files_flag_l = 1;
      break;

    case LINE_NUMBERING_FLAG:
      input_flags->line_numbering_flag_n = 1;
      break;

    case FILE_IGNORE_FLAG:
      input_flags->file_ignore_flag_h = 1;
      break;

    case ERROR_IGNORE_FLAG:
      input_flags->error_ignore_flag_s = 1;
      break;

    case REGEX_FILE_FLAG:
      input_flags->regex_file_flag_f = 1;
      open_reg_file(optarg, template_words, *input_flags);
      break;

    case MATCHING_SEQUENCE_FLAG:
      input_flags->matching_sequence_flag_o = 1;
      break;
  }
}

void open_reg_file(char* optarg, char* template_words, flags input_flags) {
  FILE* reg_file;

  if ((reg_file = fopen(optarg, "r")) == NULL) {
    if (!input_flags.error_ignore_flag_s) {
      choose_error_stream(1, optarg);
    }
  } else {
    char text_string[text_string_length];
    strcat(template_words, fgets(text_string, text_string_length, reg_file));
    strcat(template_words, "|");
  }
}

void edit_templates(int* optind, char* argv[], char* template_words,
                    flags input_flags) {
  if (!(input_flags.template_flag_e || input_flags.regex_file_flag_f)) {
    strcpy(template_words, argv[*optind]);
    *optind += 1;
  } else if (input_flags.template_flag_e || input_flags.regex_file_flag_f) {
    template_words[strlen(template_words) - 1] = '\0';
  }
}

void print_strings(int optind, int argc, char* argv[], char* template_words,
                   flags input_flags) {
  // char text_string[text_string_length]; //---

  FILE* user_file;
  regex_t reg;
  // regmatch_t start; //---

  int regex_settings = REG_EXTENDED;
  int is_multifile = 0;
  // int no_matches; //---
  int counter; //---
  // int l_match = 1; //---
  // int string_number = 1; //---
  detect_multifile(argc, optind, &is_multifile);
  detect_insensitive_flag(input_flags, &regex_settings);

  for (int i = optind; i < argc; i++) {
    regcomp(&reg, template_words, regex_settings);

    if ((user_file = fopen(argv[i], "r")) == NULL) {
      if (!input_flags.error_ignore_flag_s) {
        choose_error_stream(1, argv[i]);
      }
    } else {
      counter = 0;
      // while (fgets(text_string, text_string_length, user_file) && l_match) {
      //   no_matches = regexec(&reg, text_string, 1, &start, 0);
      //   detect_invert_flag(input_flags, &no_matches);

      //   if (!no_matches) {
      //     if (!(input_flags.match_counter_flag_c ||
      //           input_flags.matching_files_flag_l)) {
      //       print_file_name(i, is_multifile, input_flags, argv);

      //       if (input_flags.line_numbering_flag_n) {
      //         printf("%d:", string_number);
      //       }

      //       printf("%s", text_string);
      //     }
      //     if (input_flags.match_counter_flag_c) {
      //       counter++;
      //     }
      //     if (input_flags.matching_files_flag_l) {
      //       l_match = 0;
      //     }
      //   }

      //   string_number++;
      // }
      read_and_print_strings(i, is_multifile, &counter, argv,
                            user_file, reg, input_flags);
      if (input_flags.match_counter_flag_c) {
        print_file_name(i, is_multifile, input_flags, argv);
        printf("%d\n", counter);
      }

      if (input_flags.matching_files_flag_l) {
        printf("%s\n", argv[i]);
      }

      fclose(user_file);
    }

    // string_number = 1;
    // l_match = 1;
    regfree(&reg);
  }
}

void detect_multifile(int argc, int optind, int* is_multifile) {
  if ((optind + 1) != argc) {
    *is_multifile = 1;
  }
}

void detect_insensitive_flag(flags input_flags, int* regex_settings) {
  if (input_flags.case_insensitive_flag_i) {
    *regex_settings = REG_EXTENDED | REG_ICASE;
  }
}

void detect_invert_flag(flags input_flags, int* no_matches) {
  if (input_flags.inverted_search_flag_v) {
    *no_matches = !*no_matches;
  }
}

void print_file_name(int i, int is_multifile, flags input_flags, char* argv[]) {
  if (is_multifile && !input_flags.file_ignore_flag_h) {
    printf("%s:", argv[i]);
  }
}

void read_and_print_strings(int i, int is_multifile, int* counter, char* argv[],
                            FILE* user_file, regex_t reg, flags input_flags) {
  char text_string[text_string_length];  //---
  regmatch_t start;                      //---
  int no_matches;                        //---
  int l_match = 1;                       //---
  int string_number = 1;                 //---

  *counter = 0;

  while (fgets(text_string, text_string_length, user_file) && l_match) {
    no_matches = regexec(&reg, text_string, 1, &start, 0);
    detect_invert_flag(input_flags, &no_matches);

    if (!no_matches) {
      if (!(input_flags.match_counter_flag_c ||
            input_flags.matching_files_flag_l)) {
        print_file_name(i, is_multifile, input_flags, argv);

        if (input_flags.line_numbering_flag_n) {
          printf("%d:", string_number);
        }

        printf("%s", text_string);
      }
      if (input_flags.match_counter_flag_c) {
        *counter+=1;
      }
      if (input_flags.matching_files_flag_l) {
        l_match = 0;
      }
    }

    string_number++;
  }
}