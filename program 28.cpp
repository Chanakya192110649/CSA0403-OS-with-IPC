#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <pattern> <file1> [<file2> [...]]\n", argv[0]);
    exit(1);
  }

  char *pattern = argv[1];
  int i;
  for (i = 2; i < argc; i++) {
    char *filename = argv[i];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
      printf("grep: %s: No such file or directory\n", filename);
      continue;
    }

    char line[1024];
    int line_number = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
      line_number++;
      if (strstr(line, pattern) != NULL) {
        printf("%s:%d:%s", filename, line_number, line);
      }
    }

    fclose(fp);
  }

  return 0;
}

