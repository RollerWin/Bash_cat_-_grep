#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int min_elements_numbers_with_flag = 2;
  int flag_position = 1;
  int dash_position = 0;
  char dash_symbol = '-';

  int first_file_position;

  if (argc >= min_elements_numbers_with_flag &&
      argv[flag_position][dash_position] == dash_symbol) {
    first_file_position = 2;
  } else {
    first_file_position = 1;
  }

  read_console(first_file_position, argc, argv);

  return 0;
}