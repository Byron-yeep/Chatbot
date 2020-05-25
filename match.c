 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"

//for finding a match according to input
int findMatch(char *input) {
  
  int result = -1;
  char *temp1, *temp2;
  temp1 = addSpace(input);

  int i = 0;
  for(; i < commSenNum; i ++) { 
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

//to make marches more precise
char *addSpace(char *str) {

  char *newstr = (char *)malloc(sizeof(char ) * 20);
  int i = 0;
  for(; i<strlen(str); i ++) {
    newstr[i]= str[i];
  }
  newstr[i+1]=' ';
  return newstr;
}




