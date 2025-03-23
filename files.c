#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }
  
  int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1){
    perror("open");
    return -1;
  }
  
  char *thedata = "Hello this is file db!\n";
  write(fd, thedata, strlen(thedata));
  
  close(fd);
  
  return 0;
}
