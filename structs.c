#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 1000

__attribute__((__packed__)) struct TEmployee {
  int id;
  char fistname[64];
  char lastname[64];
  float income;
  bool is_manager;
};

int main () {
  struct TEmployee fred;
  fred.income = 1000.00;
  fred.is_manager = true;
  
  struct TEmployee employees[MAX_EMPLOYEES];

  int i = 0;
  for (i = 0; i < MAX_EMPLOYEES; i++){
    employees[i].id = i;
    employees[i].income = 0;
    employees[i].is_manager = false;
  }

  printf("%d\n", employees[10].id);
  
  return 0;
}
