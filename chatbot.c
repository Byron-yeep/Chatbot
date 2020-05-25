
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
  //tempRead();

  sInput = (char *)malloc(sizeof(char)*64);
  sPreviousInput = (char *)malloc(sizeof(char)*64);
  int randm, index;
     
  printf("BOT >HI");
  while(1) {
    input();
    if (strcmp(sInput, "\0") == 0) {
      printf("SORRY, DID I MAKE YOU ALONE?");
      continue;
    }
	// Enter "BYE" to end the chat
    else if(strncmp(sInput, "BYE", 3) == 0) {
      printf("BYE\n");
      return 0;
    }
    
    index = findMatch(sInput);   
    if(index == -1){
	  printf("HAHA, I AM TOO YOUNG TO UNDERSTAND YOUR REAL EXPRESSIONS?");
    }
    else{  
      output(index);
	  strcpy(sPreviousInput, sInput);
    }
  }
}
  