#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "cpeglib.h"

//範囲で入れる
void cs_range(cpeg_charset_t set, char ch1, char ch2){
  int c1 = ch1;
  int c2 = ch2;
  int i;
  for(i = c1; i <= c2; i++){
    set[i] = 1;
  }
  return;
}

//１文字入れる
void cs_simple(cpeg_charset_t set, char ch){
  int c = ch;
  set[c] = 1;
  return;
}
//補集合
void cs_complement(cpeg_charset_t set){
  int i;
  for(i = 0; i < CPEG_CHARSET_SIZE; i++){
    set[i] = !set[i];
  }
}
//和集合
void cs_union(cpeg_charset_t set1, cpeg_charset_t set2){
  int i;
  for(i = 0; i < CPEG_CHARSET_SIZE; i++){
    if(set2[i] == 1)
      set1[i] = 1;
  }
  return;
}

void cpeg_error(char *funcname, char *path) {
  fprintf(stderr, "In %s: ", funcname);
  perror(path);
  exit(1);
}

off_t cpeg_get_file_size(char *filepath) {
  struct stat s;
  if (stat(filepath, &s) < 0) {
    cpeg_error("stat", filepath);
  }
  return s.st_size;
}

char* cpeg_get_file_mmap(char *filepath) {
  off_t fsize = cpeg_get_file_size(filepath);
  long psize = sysconf(_SC_PAGESIZE);
  char *mp;
  int fd = open(filepath, O_RDONLY);
  if (fd < 0) {
    cpeg_error("open", filepath);
  }
  size_t msize = (fsize + 1 + psize - 1) / psize * psize; // + 1 for '\0'
  mp = (char*) mmap(0, msize, PROT_READ|PROT_WRITE, MAP_FILE|MAP_PRIVATE, fd, 0);
  if ((int)mp < 0) {
    cpeg_error("mmap", filepath);
  }
  mp[fsize] = '\0';
  close(fd);
  return (mp);
}

char *cpeg_get_file_read(char *filepath) {
  off_t size = cpeg_get_file_size(filepath);
  char *mp = malloc(size + 1);  // +1 for '\0'
  if (mp == NULL) {
    cpeg_error("malloc", "");
  }
  int fd = open(filepath, O_RDONLY);
  if (fd < 0) {
    cpeg_error("open", filepath);
  }
  if (read(fd, mp, size) < size) {
    cpeg_error("read", filepath);
  }
  mp[size] = '\0';
  close(fd);
  return mp;
}

cpeg_pos_t pos;
bool failed;

char *input;
