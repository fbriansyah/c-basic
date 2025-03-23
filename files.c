#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct database_header_t {
    unsigned short version;
    unsigned short employees;
    unsigned int filelength;
};

void write_example(int fd){
  // Write to file
  char *thedata = "Hello this is file db!\n";
  write(fd, thedata, strlen(thedata));
}

int main (int argc, char *argv[]) {
  struct database_header_t head = {0};
  struct stat fileHeader = {0};
  
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }
  
  // Open file
  int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1){
    perror("open");
    return -1;
  }

  // Read file header
  if (read(fd, &head, sizeof(head)) != sizeof(head)) {
    perror("read");
    close(fd);
    return -1;
  }
  printf("Database Version %d\n", head.version);
  printf("Number of employees %d\n", head.employees);
  printf("Data base length %d\n", head.filelength);

  // read file header
  if( fstat(fd, &fileHeader) == -1 ) {
    perror("read");
    close(fd);
    return -1;
  }

  if (fileHeader.st_size != head.filelength) {
    printf("HACKER DETECTED!\n");
    close(fd);
    return -1;
  }
  
  // Close file
  close(fd);
  
  return 0;
}
