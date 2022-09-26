#include "utils.h"

void Swap(int &a, int &b){
  int c = a; a = b; b = c;
};

void string_copy(char *d, char *s){
  int n = strlen(s);
  char *pd = d;
  for (char *ps = s; ps - s < n; *ps++){
    *pd = *ps;
    pd++;
  }
}