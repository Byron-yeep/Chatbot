 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "match.h"
#include "storeFile.h"
 
void commRead() {
// for storing common sentences used in conversations that are very repetetive to give a high degree of accuracy and faster response time
  FILE *fp;  
  fp = fopen( "file.txt" , "r" );
  int i,j;
  fscanf(fp,"%d\n",&commSenNum);
  commSen= (record *)malloc(sizeof(record) * commSenNum);
	
  for(i = 0; i< commSenNum;i++ ){
    fscanf(fp,"%d ",&commSen[i].numResp );
	commSen[i].lastindex = commSen[i].numResp;
	  
    commSen[i].input= (char *)malloc(sizeof(char) * 64);
	//read common questions
    fscanf(fp,"%[^\n]s\n",commSen[i].input);
    fgetc(fp);
	//read common responses
    for(j=0; j<commSen[i].numResp;j++){
      commSen[i].responses[j]= (char *)malloc(sizeof(char) * 64);
      fscanf(fp,"%[^\n]s\n",commSen[i].responses[j]);
      fgetc(fp);
    }
  }
  fclose(fp);
}