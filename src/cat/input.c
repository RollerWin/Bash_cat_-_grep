#include "input.h"
#include <stdio.h>
#include <string.h>
#include <getopt.h>

enum Cat_flags {
  // NON_EMPTY_LINE_NUMBERING_FLAG = 'b',
  // DOLLAR_DISPLAY_FLAG = 'e',
  LINE_NUMBERING_FLAG = 'n',
  // STRING_COMPRESSION_FLAG = 's',
  // TAB_REPLACEMENT_FLAG = 't',
  UNKNOWN_COMMAND_FLAG = '?'
};

void input_args(int argc, char *argv[]) 
{
  int user_input;

  //while ((user_input = getopt(argc, argv, "b:ens:t:")) != -1) {
  for (int i = 1; i < argc && ((user_input = getopt(argc, argv, "b:e:n:s:t:")) != -1); i++) 
  {
    switch (user_input)
    {
    case LINE_NUMBERING_FLAG:
      output_files(argv[i+1]); 
      i++;
      break;
    
    case UNKNOWN_COMMAND_FLAG:
      printf("мдаааа");   
      break;
    }
  }
}

void output_files(char* argv) {
  const char* error_message = "No such file or directory";
  const char* cat_message = "cat";
  const int text_string_length = 2048;
  const int file_name_length = 80;
  
  char file_name[file_name_length];
  char text_string[text_string_length];

  FILE* user_file;
  
  strcpy(file_name, argv);

    if ((user_file = fopen(file_name, "r")) == NULL) 
    {
      printf("%s: %s: %s\n", cat_message, file_name, error_message);
    } 
    else 
    {
      int string_number = 1;

      while (fgets(text_string, text_string_length, user_file)) 
      {
        printf("%6d  %s", string_number, text_string);
        string_number++;
      }
    }

    fclose(user_file);
}