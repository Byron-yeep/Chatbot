
#define MAX 128
#define MAX_RESP 100

typedef struct {
  char *input;
  int numResp;
  char *responses[MAX_RESP];
  int lastIndex;
} record;

record *commSen;
int commSenNum;

char *sInput, *sPreviousInput;

//categwords categinput, categoutput, categprev;


int WordDatasize[9];
char **points[9], *tempOut;
int a[MAX*9][MAX*9];

