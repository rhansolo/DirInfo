#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char * argv[]){ 
  DIR *d;
  char * dir;
  d = opendir(argv[1]);
  if (argc == 0){
    printf("Put in a directory\n");
    fgets(
  }
  struct dirent *entry;
  entry = readdir(d);
  char * file_name;
  struct stat *st;
  int size = 0;
  char *loc = ".";
  stat(loc,st);
  while (entry != NULL){
    size += st->st_size;
    file_name = entry->d_name;
    if ((entry->d_type) == DT_DIR){
      printf("directory: %s \n",file_name);
    }
    else{
      printf("File: %s \n",file_name);
    }
    entry = readdir(d);
  }
  printf("Total size: %d\n" , size);
  closedir(d);
}
