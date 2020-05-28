 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"

// Find a match according to input from commSen
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

// Judge two strings' relevance
int compare(int i, char *temp1, char *temp2, int result) {
  
  // Whether temp1 contains temp2 
  if(strstr(temp1,temp2) != NULL) {
    result =i; 
  }
  // Whether temp1 equals to temp2 
  if(strncmp(temp2, temp1, strlen(temp1)) == 0
	 && strlen(temp2) == strlen(temp1)) { 
    result = i; 
    return result;
  }
  return result;
}

// Make marches more precise
char *addSpace(char *str) {

  char *newstr = (char *)malloc(sizeof(char ) * 64);
  int i = 0;
  for(; i < strlen(str); i ++) {
    newstr[i]= str[i];
  }
  newstr[i+1]=' ';
  return newstr;
}

// Find a match according to input from tempSen
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
      result[1] = compare(i, temp2, temp1, result[1]);
    }
  }
  return;
}

// Keep conversations in tempSen
void keepCache(int index, int choice) {

  int result[2] = {-1, -1};
  tempMatch(commSen[index].responses[choice], userInput, result);

  if(result[0] == -1) {
    tempSen = (tBase *)realloc(tempSen, sizeof(tBase) * (tempSenNum + 1));
	tempSen[tempSenNum].input = (char *)malloc(sizeof(char) * 64);
	tempSen[tempSenNum].input = addSpace(commSen[index].responses[choice]);
    tempSen[tempSenNum].num ++;
	
	tempSen[tempSenNum].tResponses = (tempResp *)malloc(sizeof(tempResp));
	tempSen[tempSenNum].tResponses[0].times = 1;

    tempSen[tempSenNum].tResponses[0].responses = (char *)malloc(sizeof(char) * 64);
    tempSen[tempSenNum].tResponses[0].responses = addSpace(userInput);
	
    tempSenNum ++;
  }
  else {
	if(result[1] == -1) {
      int num = tempSen[result[0]].num;
	  tempSen[result[0]].tResponses = (tempResp *)realloc(tempSen[result[0]].tResponses, num * sizeof(tempResp));
	  tempSen[result[0]].tResponses[num].responses = (char *)malloc(sizeof(char) * 64);
      tempSen[result[0]].tResponses[num].responses = addSpace(userInput);
	  tempSen[result[0]].tResponses[num].times = 1;
	  tempSen[result[0]].num ++;
	}
	else {
	  tempSen[result[0]].tResponses[result[1]].times ++;
	  if(tempSen[result[0]].tResponses[result[1]].times > 5) {
	    addTemp(result);
	  }
	}
  }
}

// Add normal conversations into commSen
void addTemp(int index[]) {
  int result = commMatch(tempSen[index[0]].input);
  if(result == -1) {
    commSen = (dBase *)realloc(commSen, sizeof(dBase) * (commSenNum + 1));
	commSen[commSenNum].input = (char *)malloc(sizeof(char) * 64);
	commSen[commSenNum].input = addSpace(tempSen[index[0]].input);
    commSen[commSenNum].num ++;
	
	commSen[commSenNum].responses[0] = (char *)malloc(sizeof(char) * 64);
    commSen[commSenNum].responses[0] = addSpace(tempSen[index[0]].tResponses[index[1]].responses);
  }
  else {
	if(commSen[result].num <= MAX_RESP) {
	  commSen[result].responses[commSen[result].num] = (char *)malloc(sizeof(char) * 64);
	  commSen[result].responses[commSen[result].num] = addSpace(tempSen[index[0]].tResponses[index[1]].responses);
	}
  }
}




