#include "input.h"

int main(int argc, char *argv[]) {
  input_args(argc, argv);

  // while ((user_input = getopt(argc, argv, "b:ens:t:")) != -1) {
  //   switch (user_input) {
  //     case NON_EMPTY_LINE_NUMBERING_FLAG:
  //       printf("Выбран верный верный флаг b = %s.\n", optarg);
  //       break;

  //     case DOLLAR_DISPLAY_FLAG:
  //       printf("Выбран верный верный флаг e.\n");
  //       break;

  //     case LINE_NUMBERING_FLAG:
  //       if (optarg == (char *)"пипа") {
  //         printf("Выбран верный верный флаг n.\n");
  //       } else {
  //         printf("Неверный ввод!");
  //       }

  //       break;

  //     case STRING_COMPRESSION_FLAG:
  //       printf("Выбран верный верный флаг s = %s.\n", optarg);
  //       break;

  //     case TAB_REPLACEMENT_FLAG:
  //       printf("Выбран верный верный флаг t = %s.\n", optarg);
  //       break;

  //     case UNKNOWN_COMMAND_FLAG:
  //       printf("Неверный ввод!");
  //       break;
  //   }
  // }

  return 0;
}