 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"
#include "storeFile.h"

/*
 *Target：All functions about files which will be read and written
 *
 *Author：Dou Bowen
 *
 *Date：2020/5/31
*/

// Read some conversations from database
void commRead() {

  FILE *fp;  
  fp = fopen( "database.txt", "r" );

  fscanf(fp,"%d\n", &commSenNum);
  commSen= (dBase *)malloc(sizeof(dBase) * commSenNum);

  int i,j;
  for(i = 0; i < commSenNum; i ++) {
    fscanf(fp,"%d ", &commSen[i].num );
	// Questions  
    commSen[i].input = (char *)malloc(sizeof(char) * 64);
    fscanf(fp,"%[^\n]s\n", commSen[i].input);
    fgetc(fp);
	// Responses
    for(j = 0; j < commSen[i].num; j ++) {
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
  fp = fopen("database.txt","w+");

  fprintf(fp, "%d\n", commSenNum);
  int i = 0;
  for(; i < commSenNum; i ++) {
    fprintf(fp, "%d ", commSen[i].num);
    fprintf(fp, "%s\n", commSen[i].input);
	int j = 0;
	for(; j < commSen[i].num; j ++) {
	  fprintf(fp, "%s\n", commSen[i].responses[j]);
	}
  }
  fclose(fp);
}

// Read caches into temp data
void tempRead() {

  FILE *fp;
  fp= fopen("tempBase.txt","r");

  fscanf(fp,"%d\n", &tempSenNum);
  tempSen= (tBase *)malloc(sizeof(tBase) * tempSenNum);

  int i,j;
  for(i = 0; i < tempSenNum; i ++) {
    fscanf(fp,"%d ", &tempSen[i].num );
	// Questions
    tempSen[i].input = (char *)malloc(sizeof(char) * 64);
    fscanf(fp,"%[^\n]s\n", tempSen[i].input);

	// Responses
	tempSen[i].tResponses = (tempResp *)malloc(tempSen[i].num * sizeof(tempResp));
    for(j = 0; j < tempSen[i].num; j ++) {
	  fscanf(fp,"%d  ", &tempSen[i].tResponses[j].times);
      tempSen[i].tResponses[j].responses = (char *)malloc(sizeof(char) * 64);
      fscanf(fp,"%[^\n]s\n", tempSen[i].tResponses[j].responses);
    }
  }
  fclose(fp);
}

// Write caches into temp data
void tempWrite() {
	
  FILE *fp;
  fp = fopen("tempBase.txt","w+");

  fprintf(fp, "%d\n", tempSenNum);
  int i = 0;
  for(; i < tempSenNum; i ++) {
    fprintf(fp, "%d ", tempSen[i].num);
    fprintf(fp, "%s\n", tempSen[i].input);
	int j = 0;
	for(; j < tempSen[i].num; j ++) {
	  fprintf(fp, "%d  ", tempSen[i].tResponses[j].times);
	  fprintf(fp, "%s\n", tempSen[i].tResponses[j].responses);
	}
  }
  fclose(fp);
}

// Free all malloc memories
void freeAll() {

  free(userInput);
  free(preUserInput);

  free(commSen);
  commSen = NULL;

  free(tempSen);
  tempSen = NULL;
  
}