#include "s21_grep.h"

const int template_length = 8192;

int main(int argc, char* argv[]) {
  flags input_flags = {0};
  char template_words[template_length];
  input_flags = detect_flags(argc, argv, template_words, input_flags);
  edit_templates(&optind, argv, template_words, input_flags);
  print_strings(optind, argc, argv, template_words, input_flags);
  return 0;
}
