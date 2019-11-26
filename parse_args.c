#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

char ** parse_args( char * line ){
  char ** args = malloc(6 * sizeof(char *));
  int c = 0;
  char * token;
  while (line != NULL){
    token = strsep(&line, " ");
    args[c] = token;
    c++;
  }
  for (;c <= 5; c++){
    args[c] = NULL;
  }
  return args;
}

int main(){
  printf("Testing parse_args:\n");
  printf("Parsing \"ls -a -l\"\n");
  char line[100] = "ls -a -l";
  char *s1 = line;
  char ** args = parse_args(s1);
  int c;
  printf("[");
  for (c = 0; c < 5; c++){
    printf("%s ", args[c]);
  }
  printf("]\n");
  printf("Testing execvp:\n");
  execvp(args[0], args);
  free(args);
  return 0;
}
