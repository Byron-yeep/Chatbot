
#define MAX 128
#define MAX_RESP 4

typedef struct {
  char *input;
  int numResp;
  char *responses[MAX_RESP];
  int lastIndex;
} record;

record *commSen;
int commSenNum;
char *sInput,*sPreviousInput,*sResponse;