#include "input.h"

#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {

//------------------------------------
  // struct timespec mt1, mt2;
  // long int tt;
  // clock_gettime(CLOCK_REALTIME, &mt1);

  // printf("Секунды : %ld\n", mt1.tv_sec);
  // printf("Наносекунды : %ld\n", mt1.tv_nsec);
//------------------------------------

  int min_elements_numbers_with_flag = 2;
  int flag_position = 1;
  size_t flag_length = 2;

  int first_file_position;

  if(argc > min_elements_numbers_with_flag && strlen(argv[flag_position]) == flag_length) {
    first_file_position = 2;
  }
  else {
    first_file_position = 1;
  }

  read_console(first_file_position, argc, argv);

//------------------------------------
  // clock_gettime(CLOCK_REALTIME, &mt2);
  // tt = 1000000000 * (mt2.tv_sec - mt1.tv_sec) + (mt2.tv_nsec - mt1.tv_nsec);
  // printf("Затрачено время : %ld нс\n", tt);  
//------------------------------------

return 0;
}