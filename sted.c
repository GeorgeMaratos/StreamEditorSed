/*this is a stream editor made by george maratos
  it takes a given stream of characters and manipulates
  the stream in a way specified by the user

  how to use:
  sted <operation> <operand> <character_of_interest>
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"

void append_stream(char *operand, char* char_int) {
  int str_len = strlen(char_int), i = 0;
  char *buf = malloc(str_len);
  while(scanf("%c",&buf[i++]) != EOF) {
    if(strlen(buf) == str_len) {
      printf("%s",buf);
      if(!strcmp(buf,char_int))
        printf("%s",operand);
      for(i=0;i<str_len;i++)
        buf[i] = '\0';
      i=0;
    }
  }
}

void string_shift(char *string, int len) {
  char *temp = malloc(len);
  int i;
  for(i=1;i<len;i++)
    temp[i-1] = string[i];
  temp[i] = '\0';
  for(i=0;i<len;i++)
    string[i] = temp[i];
}

void append_stream2(char *operand, char *char_int) {
  int str_len = strlen(char_int), i;
  char *buf = malloc(str_len);
  for(i=0;i<str_len - 1;i++) {
    scanf("%c",&buf[i]);
    printf("%c", buf[i]);
  }
  while(scanf("%c",&buf[i]) != EOF) {
    printf("%c",buf[i]);
    if(!strcmp(buf,char_int))
      printf("%s",operand);
    string_shift(buf,str_len);
  }
}

int call_arg4(char *operation, char *operand, char *char_int) {
  if(!strcmp(operation, append)) {
    append_stream2(operand, char_int);
    return 0;
  }
  return 1;
}
  

int main(int argc, char **argv) {
  switch(argc) {
  case 4: 
    if(call_arg4(argv[1], argv[2], argv[3])) {
      fprintf(stderr,"No valid operation\n");
      return 1;
    }
    break;
  default:
    break;
  }
  return 0;
}
