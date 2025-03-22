#include <stdio.h>
#include <stdbool.h>

struct employee_t {
  int id;
  int income;
  bool is_manager;
};

void init_employee(struct employee_t *e) {
  e->id = 0;
  e->income = 0;
  e->is_manager = false;

  return ;
}

int main (){
  struct employee_t feb;

  init_employee(&feb);
  
  printf("%d\n", feb.id);
  printf("%d\n", feb.income);
  
  int n = 3;
  struct employee_t *employees = malloc(sizeof(struct employee_t) * n);
  if  (employees == NUUL){
    printf("the allocator failed\n");
    return -1;
  }
  init_employee(employees[0]);
  return 0;
}










