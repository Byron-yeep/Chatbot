 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"

//for finding a match according to input from commSen
int commMatch(char *input) {
  
  int result = -1;
  char *temp1, *temp2;
  temp1 = addSpace(input);

  int i = 0;
  for(; i < commSenNum; i ++) { 
    temp2 = addSpace(commSen[i].input);
    result = compare(i, temp1, temp2, result);
  }
  return result;
}

int compare(int i, char *temp1, char *temp2, int result) {
  
  // Whether temp1 contains temp2 
  if(strstr(temp1,temp2) != NULL) {
    result =i; 
  }
  // Whether temp1 equals to temp2 
  if(strncmp(temp2, temp1, strlen(temp1) - 1) == 0
	 && strlen(temp2) == strlen(temp1) - 1) { 
    result = i; 
    return result;
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

//for finding a match according to input from tempSen
void tempMatch(char *bot, char *user, int result[]) {
  
  char *temp1, *temp2;
  temp1 = addSpace(bot);

  int i = 0;
  for(; i < tempSenNum; i ++) { 
    temp2 = addSpace(tempSen[i].input);
    result[0] = compare(i, temp1, temp2, result[0]);
  }
  if(result[0] != -1) {
    temp1 = addSpace(user);
    for(i = 0; i < tempSen[result[0]].num; i ++) { 
      temp2 = addSpace(tempSen[result[0]].tResponses[i].responses);
      result[1] = compare(i, temp1, temp2, result[1]);
    }
  }
  return;
}

// Keep conversations in tempSen
void keepCache(int index, int choice) {

  int result[2] = {-1, -1};
  tempMatch(commSen[index].responses[choice], userInput, result);

  if(result[0] == -1) {
	tempSen[tempSenNum].input = (char *)malloc(sizeof(char) * 64);
	tempSen[tempSenNum].input = commSen[index].responses[choice];

	tempResp *t = &tempSen[tempSenNum].tResponses[0];
	t = (tempResp *)malloc(sizeof(tempResp));
    t->responses = (char *)malloc(sizeof(char) * 64);
    t->responses = userInput;
	t->times = 0;
    tempSenNum ++;
  }
  else {
	if(result[1] = -1) {
      tBase *t = &tempSen[result[0]];
	  t = (tBase *)realloc(t, sizeof(tBase) * tempSenNum);
	  t->tResponses = (tempResp *)realloc(t->tResponses, t->num * sizeof(tempResp));
	  //t->tResponses[t->num].responses = (char *)malloc(sizeof(char) * 64);
      /*t->tResponses[t->num].responses = userInput;
	  t->tResponses[t->num].times = 0;
	  t->num ++;*/
	}
	else {
	  tempSen[result[0]].tResponses[result[1]].times ++;
	}
  }
}






