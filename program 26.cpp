#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  FILE *fp;
  fp = fopen("example.txt", "w");
  if (fp == NULL) {
    printf("Error creating file.\n");
    return 1;
  }
  printf("File created successfully.\n");
  
  
  char content[] = "This is a sample text for the file.";
  int result = fprintf(fp, "%s", content);
  if (result < 0) {
    printf("Error writing to file.\n");
    return 1;
  }
  printf("Content written to file successfully.\n");
  
  
  fclose(fp);
  
  
  fp = fopen("example.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  char buffer[100];
  result = fscanf(fp, "%s", buffer);
  if (result < 0) {
    printf("Error reading from file.\n");
    return 1;
  }
  printf("Content read from file: %s\n", buffer);
  
  
  fclose(fp);
  
  
  result = remove("example.txt");
  if (result != 0) {
    printf("Error deleting file.\n");
    return 1;
  }
  printf("File deleted successfully.\n");
  
  return 0;
}

