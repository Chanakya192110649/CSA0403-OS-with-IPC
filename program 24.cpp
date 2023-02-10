#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  int fd, n;
  char buf[MAX_BUF];
  
  
  fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }
  
  
  n = write(fd, "Hello, world!\n", 14);
  if (n == -1) {
    perror("Error writing to file");
    return 1;
  }
  
  
  if (close(fd) == -1) {
    perror("Error closing file");
    return 1;
  }
  
  
  fd = open("test.txt", O_RDONLY);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }
  

  n = read(fd, buf, MAX_BUF);
  if (n == -1) {
    perror("Error reading from file");
    return 1;
  }
  
  
  write(1, buf, n);
  
  
  if (close(fd) == -1) {
    perror("Error closing file");
    return 1;
  }
  
  return 0;
}

