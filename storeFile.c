 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"
#include "storeFile.h"

// Read some conversations from database
void commRead() {

  FILE *fp;  
  fp = fopen( "database.txt", "r" );

  fscanf(fp,"%d\n", &commSenNum);
  commSen= (dBase *)malloc(sizeof(dBase) * commSenNum * 1.5);

  int i,j;
  for(i = 0; i < commSenNum;i ++) {
    fscanf(fp,"%d ", &commSen[i].num );
	  
    commSen[i].input = (char *)malloc(sizeof(char) * 64);
	// Questions
    fscanf(fp,"%[^\n]s\n", commSen[i].input);
    fgetc(fp);
	// Responses
    for(j = 0; j < commSen[i].num;j ++) {
      commSen[i].responses[j] = (char *)malloc(sizeof(char) * 64);
      fscanf(fp,"%[^\n]s\n", commSen[i].responses[j]);
      fgetc(fp);
    }
  }
  fclose(fp);
}

// Write new conversations to database
void commWrite() {

  FILE *fp;
  fp = fopen("tempBase.txt","w+");

  fclose(fp);
}

// Read caches into tempBase
void tempRead() {

  FILE *fp;
  fp= fopen("tempBase.txt","r");

  fscanf(fp,"%d\n", &tempSenNum);
  tempSen= (tBase *)malloc(sizeof(tBase) * tempSenNum * 1.5);

  int i,j;
  for(i = 0; i < tempSenNum;i ++) {
    fscanf(fp,"%d ", &tempSen[i].num );
	  
    tempSen[i].input = (char *)malloc(sizeof(char) * 64);
	// Questions
    fscanf(fp,"%[^\n]s\n", tempSen[i].input);
    fgetc(fp);
	// Responses
    for(j = 0; j < tempSen[i].num;j ++) {
	  fscanf(fp,"%d", &tempSen[i].tResponses[j].times);
		
      tempSen[i].tResponses[j].responses = (char *)malloc(sizeof(char) * 64);
      fscanf(fp,"%[^\n]s\n", tempSen[i].tResponses[j].responses);
      fgetc(fp);
    }
  }
  fclose(fp);
}

// Write caches into teamBase
void tempWrite() {
	
  FILE *fp;
  fp = fopen("tempBase.txt","w+");

  fclose(fp);
}

// Concentrate on freeing commSen and temSen
void freeAll() {

  int i,j;
  for(i = 0; i< commSenNum;i++) {
    for(j = 0; j < commSen[i].num;j ++) {
	  free(commSen[i].responses[j]);
	}
    free(commSen[i].input);
  }
  free(commSen);

  for(i = 0; i< tempSenNum;i++) {
    for(j = 0; j < tempSen[i].num;j ++) {
	  free(tempSen[i].tResponses[j].responses);
	}
    free(tempSen[i].input);
  }
  free(tempSen);
}