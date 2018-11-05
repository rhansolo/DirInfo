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

void printDir(char *dir){
  DIR *d;
  d = opendir(dir);
  struct dirent *entry;
  entry = readdir(d);
  struct stat* file = malloc(sizeof(struct stat));  
  int size = 0;

  while (entry){
    size += file->st_size;
    stat(entry->d_name,file);
    if ((entry->d_type) == DT_DIR){
      printf("directory: %s \n",entry->d_name);
    }
    else{
      printf("File: %s \n",entry->d_name);
    }
    entry = readdir(d);
  }
  printf("Total size: %d\n" , size);
  closedir(d);
  
}


int main(int argc, char * argv[]){ 

  char * dir = malloc(100);
  if (argc == 1){
    printf("Put in a directory\n");
    scanf("%s",dir);
  }
  else if (argc > 2) {
      printf("Too many arguements");
      return 0;
  }
  else{
    scanf(dir,argv[1]);
  }
  printDir(dir);
  return 0;
}
