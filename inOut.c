 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "inOut.h"
#include "storeFile.h"
 
void input() { 
  printf("\nUSER >");
  //to avoid input is greater than the length of sInput
  fgets(sInput, 30, stdin);
  trim(sInput);
  printf("\nBOT >");
  upper(sInput);
}

//to delete space to gain valid words
char *trim(char *str) {
  int beg = 0, end = strlen(str)-1;
  //begin spaces
  while(1){
    if(str[0] == ' '){
      str[0] = '\0';
      str = &str[1];
    }
    else break;
  }
  //end spaces
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

//convert all input into upper case to easily control
void upper(char *str) {
  int i = 0;
  for(; i < strlen(str); i ++ ) {
    if ( str[i] >= 'a' && str[i] <= 'z' ) {
      //UPPER
      str[i] -= 'a' - 'A';
    }
  }
}

//fix the first few numbers at spicific inputs like sign on and no inputs to make it easier to handle
int output(int index) {
  int choice, prevchoice;
  if(strcmp(sPreviousInput, sInput) == 0) {
    printf("YOU'RE REPREATINING YOURSELF");
  }
  else if (index == -1) {
    printf("I DON'T UNDERSTAND");
  }
  else {
    choice = rand() % commSen[index].numResp;
    if(commSen[index].numResp > 1 && choice ==  commSen[index].lastIndex) {
        choice = (choice + 1) % MAX_RESP;
    }
    printf("%s", commSen[index].responses[choice]);
  }
  return 0;
}