#include <stdio.h>

#include "s21_grep.h"

const char* cat_message = "grep: ";
const char* wrong_file_message = ": No such file or directory";
const int template_length = 10240;
const int file_name_length = 64;

int main(int argc, char* argv[]) {
  flags input_flags = {0};
  char template_words[template_length];
  input_flags = detect_flags(argc, argv, template_words, input_flags);
  edit_templates(&optind, argv, template_words, input_flags);
  print_strings(optind, argc, argv, template_words, input_flags);
  return 0;
}

void choose_error_stream(int first_file_position, char* argv) {
  char error_message[file_name_length];
  build_error_message(argv, error_message);

  if (first_file_position == 1) {
    print_default_error_message(error_message);
  } else if (first_file_position == 2) {
    print_flag_error_message(error_message);
  }
}

void print_default_error_message(char* error_message) { perror(error_message); }
void print_flag_error_message(char* error_message) { perror(error_message); }

char* build_error_message(char* file_name, char* error_message) {
  strcat(error_message, cat_message);
  strcat(error_message, file_name);
  return error_message;
}