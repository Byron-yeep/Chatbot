 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"

//for finding a match according to input
int findMatch(char *input) {
  int i = 0, result = -1;
  char *temp1, *temp2;
  temp1 = addSpace(input);

  for(; i < commSenNum;  i++) { 
    temp2 = addSpace(commSen[i].input);
    if(strstr(temp1,temp2) != NULL) {
      result =i; 
    }
    if(strncmp(temp2, temp1, strlen(temp1) - 1) == 0
	   && strlen(temp2) == strlen(temp1) - 1) { 
      result = i; 
      return result;
    }
  }
  return result;
}

