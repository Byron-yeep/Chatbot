
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#include "inOut.h"
#include "match.h"
#include "storeFile.h"

int main(char *argv[]) {
  //clear terminal
  system("clear");
  commRead();

  sInput=(char *)malloc(sizeof(char)*64);
  sPreviousInput= (char *)malloc(sizeof(char)*64);
  int randm, index;
     
  printf("BOT >HI");
  while(1){
    input();
    if (strcmp(sInput, "\0") == 0) {
      printf("SORRY, DID I MAKE YOU ALONE?");
      continue;
    }
    else if(strncmp(sInput, "BYE", 3) == 0) {
      printf("BYE\n");
      return 0;
    }   
    index = find_match(sInput);   
	if(index == -1){
      inputanalyze();  
	}
	else {
      output(index);
	  strcpy(sPreviousInput, sInput);
	}
  }
}