
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#include "converse.h"
#include "match.h"
#include "storeFile.h"

int main(char *argv[]) {

  // Clear terminal
  system("clear");
  commRead();
  tempRead();

  userInput = (char *)malloc(sizeof(char)*64);
  preUserInput = (char *)malloc(sizeof(char)*64);
  
  int index;
  printf("(ENTER \"BYE\" TO END THE CONVERSATION)\n\nBOT >HI");
  input();

  while(1) {
    if (strcmp(userInput, "\0") == 0) {
      printf("SORRY, DID I MAKE YOU ALONE?");
      continue;
    }
	// Enter "BYE" to end the chat
    else if(strncmp(userInput, "BYE", 3) == 0) {
      printf("BYE\n");

      tempWrite();
      commWrite();

	  //freeAll();
      return 0;
    }
    int choice;
    index = commMatch(userInput);   
    if(index == -1){
	  printf("HAHA, I AM TOO YOUNG TO UNDERSTAND YOUR REAL EXPRESSIONS\n     ASK ME SOMETHING SIMPLE :)");
    }
    else{
      choice = output(index);
	  strcpy(preUserInput, userInput);
    }

    input();
    // keep the conversation of this round
    if(index != -1) {	  
      keepCache(index, choice);
	}
  }
  
}
  