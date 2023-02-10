#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
  int fd;
  struct stat file_stat;
  DIR *dir;
  struct dirent *entry;
  
  // open a file using the open system call
  fd = open("test.txt", O_RDONLY);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }
  
  // retrieve information about the file using the fstat system call
  if (fstat(fd, &file_stat) == -1) {
    perror("Error retrieving file information");
    return 1;
  }
  
  // display the size of the file
  printf("File size: %ld\n", file_stat.st_size);
  
  // change the current position within the file using the lseek system call
  if (lseek(fd, 10, SEEK_SET) == -1) {
    perror("Error changing position in file");
    return 1;
  }
  
  // read from the file using the read system call
  char buf[100];
  int n = read(fd, buf, 100);
  if (n == -1) {
    perror("Error reading from file");
    return 1;
  }
  
  // write the contents of the buffer to standard output
  write(1, buf, n);
  
  // close the file using the close system call
  if (close(fd) == -1) {
    perror("Error closing file");
    return 1;
  }
  
  // open a directory using the opendir system call
  dir = opendir(".");
  if (!dir) {
    perror("Error opening directory");
    return 1;
  }
  
  // read the entries in the directory using the readdir system call
  while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
  }
  
  
  if (closedir(dir) == -1) {
    perror("Error closing directory");
    return 1;
  }
  
  return 0;
}

