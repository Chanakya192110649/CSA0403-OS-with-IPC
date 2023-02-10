#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

void list_dir(const char *path) {
  DIR *d;
  struct dirent *dir;
  d = opendir(path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    list_dir(".");
  } else {
    for (int i = 1; i < argc; i++) {
      list_dir(argv[i]);
    }
  }
  return 0;
}
