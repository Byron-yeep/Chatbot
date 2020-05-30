
// Contain all struct and global variables

#define MAX 999
#define MAX_RESP 50

// Data structure 
typedef struct {
  // Number of total questions
  int num;
  // Conversation
  char *input;
  char *responses[MAX_RESP];
} dBase;

// Record responses and their times
typedef struct {
  int times;
  char *responses;
} tempResp;

// Temp structure 
typedef struct {
  // Number of total questions
  int num;
  // Conversation
  char *input;
  tempResp *tResponses;
} tBase;

// database
dBase *commSen;
int commSenNum;

// tempbase
tBase *tempSen;
int tempSenNum;

char *userInput, *preUserInput;


