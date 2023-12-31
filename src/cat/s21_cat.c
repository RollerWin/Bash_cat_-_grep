#include "s21_cat.h"

const char* cat_message = "cat: ";
const char* wrong_file_message = ": No such file or directory";
const int text_string_length = 8192;
const int file_name_length = 64;

void read_console(int first_file_position, int argc, char* argv[]) {
  char text_string[text_string_length];

  for (int i = first_file_position; i < argc; i++) {
    FILE* user_file;

    if ((user_file = fopen(argv[i], "r")) == NULL) {
      print_error_message(argv[i]);
    } else if (first_file_position == 1) {
      default_print_files(text_string, user_file);
    } else if (first_file_position == 2) {
      detect_flag(argc, argv, text_string, user_file);
    }
    fclose(user_file);
  }
}

void print_error_message(char* argv) {
  char error_message[file_name_length];
  strcat(error_message, cat_message);
  strcat(error_message, argv);
  strcat(error_message, wrong_file_message);
  fprintf(stderr, "%s\n", error_message);
}

void detect_flag(int argc, char* argv[], char* text_string, FILE* user_file) {
  char* short_options = "beEnstTv";

  struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, NON_EMPTY_LINE_NUMBERING_FLAG},
      {"number", no_argument, NULL, LINE_NUMBERING_FLAG},
      {"squeeze-blank", no_argument, NULL, STRING_COMPRESSION_FLAG}};

  switch (getopt_long(argc, argv, short_options, long_options, 0)) {
    case LINE_NUMBERING_FLAG:
      line_numbering_funtion(text_string, user_file);
      break;

    case NON_EMPTY_LINE_NUMBERING_FLAG:
      non_empty_line_numbering_funtion(text_string, user_file);
      break;

    case DOLLAR_DISPLAY_FLAG:
    case GNU_DOLLAR_DISPLAY_FLAG:
      dollar_display_function(text_string, user_file);
      break;

    case STRING_COMPRESSION_FLAG:
      string_compression_function(text_string, user_file);
      break;

    case TAB_REPLACEMENT_FLAG:
    case GNU_TAB_REPLACEMENT_FLAG:
      tab_replacement_function(text_string, user_file);
      break;
  }
}

void line_numbering_funtion(char* text_string, FILE* user_file) {
  int string_number = 1;

  while (fgets(text_string, text_string_length, user_file)) {
    printf("%6d\t%s", string_number++, text_string);
  }
}

void non_empty_line_numbering_funtion(char* text_string, FILE* user_file) {
  int string_number = 1;

  while (fgets(text_string, text_string_length, user_file)) {
    if (text_string[0] == '\n') {
      printf("\n");
    } else {
      printf("%6d\t%s", string_number++, text_string);
    }
  }
}

void dollar_display_function(char* text_string, FILE* user_file) {
  while (fgets(text_string, text_string_length, user_file)) {
    if (text_string[strlen(text_string) - 1] == '\n') {
      text_string[strlen(text_string) - 1] = '$';
      printf("%s\n", text_string);
    } else {
      printf("%s", text_string);
    }
  }
}

void string_compression_function(char* text_string, FILE* user_file) {
  int empty_string_counter;

  while (fgets(text_string, text_string_length, user_file)) {
    if (text_string[0] == '\n' && empty_string_counter == 0) {
      printf("%s", text_string);
      empty_string_counter = 1;
    } else if (text_string[0] != '\n' || empty_string_counter == 0) {
      empty_string_counter = 0;
      printf("%s", text_string);
    }
  }
}

void tab_replacement_function(char* text_string, FILE* user_file) {
  while (fgets(text_string, text_string_length, user_file)) {
    for (int j = 0; j < (int)strlen(text_string); j++) {
      if (text_string[j] != '\t') {
        printf("%c", text_string[j]);
      } else {
        printf("^I");
      }
    }
  }
}

void default_print_files(char* text_string, FILE* user_file) {
  while (fgets(text_string, text_string_length, user_file)) {
    printf("%s", text_string);
  }
}