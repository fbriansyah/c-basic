#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for malloc

struct employee_t {
  int id;
  int income;
  bool is_manager;
};

typedef enum { 
  STATUS_GOOD,
  STATUS_BAD,
} status_t;

status_t allocate_employees(struct employee_t **employees, int len) {
  struct employee_t *temp = NULL;
  temp = realloc(*employees, len);
  
  if(temp == NULL) {
    *employees == NULL;
    return STATUS_BAD;
  }
  
  *employees = temp;
  return STATUS_GOOD;
}

int init_employee(struct employee_t *e) {
  // static will create global variable but only we can access it
  // it call data hidding
  static int sNumEmployees = 0;
  sNumEmployees++;
  
  e->id = sNumEmployees;
  e->income = 0;
  e->is_manager = false;

  return sNumEmployees ;
}

void double_pointer() {
  int n = 3;
  struct employee_t *employees = malloc(sizeof(struct employee_t) * n);
  if (STATUS_BAD == allocate_employees(&employees, 10)) {
    printf("Failed to re-allocate employees\n");
  }

  printf("Success to re-allocate employees\n");
  
  free(employees);
  employees = NULL;
}

int dynamic_allocator(){
  // setup dynamic allocator
  int n = 3;
  struct employee_t *employees = malloc(sizeof(struct employee_t) * n);
  if  (employees == NULL){
    printf("the allocator failed\n");
    return -1;
  }
  
  int i = 0;
  for(i = 0; i < n; i++) {
    int id = init_employee(&employees[i]);
    printf("Initialize new employee with ID: %d\n", id);
  }

  free(employees);
  employees = NULL;
  // end setup dynamic allocator
  return 0;
}

int main (){
  
  double_pointer();
  return dynamic_allocator();;
}








