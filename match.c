 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"

int find_match(char *input) {
//for finding a match in the strings of the most frequent stements passed
  int i = 0, result=-1;
  char * temp1, *temp2, *temp3;
  temp1 = (char *)malloc(sizeof(char)*300);
  temp2 = input;

  for(; i < commSenNum;  i++) { 
    temp3 = commSen[i].input;
    if(strstr(temp2,temp3) != NULL){
      if(strlen(temp3) > strlen(temp1)){
        strcpy(temp1,temp3);
        result =i; 
      }
    }
    if(strncmp(commSen[i].input,input,strlen(input)-1) == 0
	   && strlen(commSen[i].input) == strlen(input)-1) { 
      result = i; 
      return result;
    }
  }
  return result;
}

