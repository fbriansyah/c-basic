#include <stdio.h>

#define MAX_IDS 32

void loops(){
  int ids[MAX_IDS];
  
  int i = 0;
  for (i=0; i < MAX_IDS; i++){
    ids[i] = i*1;
    printf("%d: %d\n", i, ids[i]);
  }
  i = 0;
  while (i < MAX_IDS){

    ids[i] = i*1;
    printf("%d: %d\n", i, ids[i]);
    i++;
  }
  
  i = 0;
  do {
    ids[i] = i*1;
    printf("%d: %d\n", i, ids[i]);
    i++;
  } while(i < MAX_IDS);
}

void conditional(){
  int temp;
  printf("what temperature is it? ");
  scanf("%d", &temp);
  
  if (temp >= 70) {
    printf("hot\n");
  } else if (temp >= 30 && temp < 70) {
    printf("mild \n");
  } else {
    printf("cold \n");
  }
}

int main (){
  loops();
  return  0;
}
