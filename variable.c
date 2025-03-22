#include <stdio.h>

// Global Scope
// int g_NumPersons = 0;

// Preprocessor
// define create variable as constant
#define MAX_PERSONS 1024
/* #define DEBUG */

int main ()
{
  int personID = 0;   
  personID += 1;
  {
    // sub scope
    // this will not affect the other personID
    int personID = 0;
  }
  
  // active debug by define preprocessor or
  // gcc variables variable.c -DDEBUG
  #ifdef DEBUG
  printf("we are in debug mode: %s:%d", __FILE__, 22);
  #endif
  return 0;
}
