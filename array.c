#include <stdio.h>

#define MAX_IDS 32

int main() {
  
  // array of int
  /* int my_ids[32]; */
  int my_ids[MAX_IDS] = {0,1,2};
  
  printf("%d\n", my_ids[1]);
  
  my_ids[3] = 0x41;
  printf("%d\n", my_ids[3]);
  
  return 0;
}
