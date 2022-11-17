#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "queue.h"
#include "stack.h"


#define MAX_STR_LEN 256

int get_user_str(char* dest, int n) {
  printf("\nEnter a string, and we'll check whether it's a palindrome:\n");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  char* in = malloc(MAX_STR_LEN * sizeof(char));
  struct stack* s;
  struct queue* q;
  while (get_user_str(in, MAX_STR_LEN)) {

int numofstring = strlen(in);
  s = stack_create();
  q = queue_create();                  
  int palindrome = 0;
  char* dummy;
  char* dummy1;                       
  for (int i = 0; i < strlen(in); i++) {
    if (isalpha(in[i])){                
      in[i] = tolower(in[i]);
      stack_push(s, &in[i]);            
      queue_enqueue(q, &in[i]);
    }
    else{
      numofstring--;                  
    }
  }
  for (int y = 0; y < numofstring; y++){
    dummy = stack_pop(s);
    dummy1 = queue_dequeue(q);            
    if (*dummy != *dummy1){
      printf("This string is not a palindrome! \n");                 
      palindrome = 0;
      break;
    }
    else{
      palindrome = 1;
    }
  }
  if (palindrome == 1){
    printf("This string is a palindrome! \n");
  }
  stack_free(s);                        //free the memeory
  queue_free(q);
  }
  free(in);
  return 0;
}
