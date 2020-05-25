 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"
#include "storeFile.h"

// Read some conversations from database.txt
void commRead() {

  FILE *fp;  
  fp = fopen( "database.txt" , "r" );

  int i,j;
  fscanf(fp,"%d\n",&commSenNum);
  commSen= (record *)malloc(sizeof(record) * commSenNum);
	
  for(i = 0; i< commSenNum;i++){
    fscanf(fp,"%d ",&commSen[i].numResp );
	commSen[i].lastIndex = commSen[i].numResp;
	  
    commSen[i].input= (char *)malloc(sizeof(char) * 64);
	// Questions
    fscanf(fp,"%[^\n]s\n",commSen[i].input);
    fgetc(fp);
	// Responses
    for(j=0; j<commSen[i].numResp;j++){
      commSen[i].responses[j]= (char *)malloc(sizeof(char) * 64);
      fscanf(fp,"%[^\n]s\n",commSen[i].responses[j]);
      fgetc(fp);
    }
  }
  fclose(fp);
}

void tempWrite() {
}

void tempRead() {
}
