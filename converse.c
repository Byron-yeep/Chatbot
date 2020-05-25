 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "converse.h"
#include "storeFile.h"
 
// Get user's sentences
void input() {
  printf("\nUSER >");
  // Avoid input is greater than the length of sInput
  fgets(sInput, 30, stdin);
  trim(sInput);
  printf("\nBOT >");
  upper(sInput);
}

// Delete space to gain valid words
char *trim(char *str) {
  int beg = 0, end = strlen(str)-1;
  // Begin spaces
  while(1){
    if(str[0] == ' '){
      str[0] = '\0';
      str = &str[1];
    }
    else break;
  }
  // End spaces
  if(str[end] == '\n') {
    str[end] = '\0';
    end --;
  }
  while(1){
    if(str[end] == ' '){
      str[end] = '\0';
      end --;     
    }
    else break;
  }
  return str;
}

// Convert all input into upper case to easily control
void upper(char *str) {
  int i = 0;
  for(; i < strlen(str); i ++ ) {
    if ( str[i] >= 'a' && str[i] <= 'z' ) {
      //UPPER
      str[i] -= 'a' - 'A';
    }
  }
}

// Accord to judgement to print some responces from database
void output(int index) {
  int choice;
  if(strcmp(sPreviousInput, sInput) == 0) {
    printf("YOU'RE REPREATINING YOURSELF, COULD WE TALK SOMETHING ELSE : )");
  }
  else if (index == -1) {
    printf("I DON'T UNDERSTAND");
  }
  else {
    choice = random() % commSen[index].numResp;
    printf("%s", commSen[index].responses[choice]);
  }
}
