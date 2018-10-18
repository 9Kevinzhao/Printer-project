#ifndef COPYJOB
#define COPYJOB

//Define a user
typedef struct{
  char* name;
  int pages;
  int quantity;
  char content[512];
} CopyJob;

#endif //COPYJOB
