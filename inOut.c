 
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
  printf("\nBOT >");
  upper(sInput);
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
    commSen[index].lastIndex = choice;
    printf("%s", commSen[index].responses[choice]);
  }
  return 0;
}