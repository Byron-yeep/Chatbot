 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "inOut.h"
#include "storeFile.h"
 
void input() {
//function responsible for the input of a file
//trimming the input of excessive initial or terminal spaces
//converting input into upper case to generalize operations on it 
  printf("\nUSER >");
  //to avoid input is greater than the length of sInput
  fgets(sInput, 30, stdin);
  printf("\nBOT >");
  upper(sInput);
}

void upper(char *str) {
//convert all input into upper case to easily control
  int i = 0;
  for(; i < strlen(str); i ++ ) {
    if ( str[i] >= 'a' && str[i] <= 'z' ) {
      //UPPER
      str[i] -= 'a' - 'A';
    }
  }
}

int output(int comIndex) {
//fix the first few numbers at spicific inputs like sign on and no inputs to make it easier to handle
  char *temp;
  if(strncmp(sPreviousInput, sInput,strlen(sInput)-1) == 0) {
    printf("YOU'RE REPREATINING YOURSELF");
    return 0;
  }
  else if (comIndex == -1) {
    printf("I DON'T UNDERSTAND");
    return 0;
  }
  else {
  if(commSen[comIndex].numResp < 1 || commSen[comIndex].numResp > 4)
    commRead();
    nselection = rand() % commSen[comIndex].numResp;
    if(commSen[comIndex].numResp > 1) {
      if(nselection ==  commSen[comIndex].lastindex) 
        nselection = (nselection + 1) % MAX_RESP;
    }
    commSen[comIndex].lastindex = nselection;
    printf("%s", commSen[comIndex].responses[nselection]);
    strcpy(sPreviousInput, sInput);
    return 0;
  }
}