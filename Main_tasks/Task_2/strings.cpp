#include <iostream>
#include <cstring>
#include "utils.cpp"

using namespace std; 

int len(char *s); 
int compare(char *s, char *t);

int len(char *s){
  int count = 0;
  char *p = s;
  while(*p != '\0'){
    count++; p++;
  }
  return count;
}

int compare(char *s, char *t){
  int n = len(s);
  int m = len(t);
  return n - m;
}

int main(){

  char str[] = "Hello!";
  cout << "strlen(str): " << strlen(str) << " | sizeof(str): " << sizeof(str) << endl;

  char t[32];
  string_copy(t, str);

  cout << "original: " << str << " | copy: " << t << endl;
  cout << "Length of string: " << len(str) << endl;

  char str_1[] = "aaa";
  char str_2[] = "bb";
  char str_3[] = "ccc";
  char str_4[] = "dddd";
  
  cout << compare(str_1, str_2) << endl; 
  cout << compare(str_1, str_3) << endl;
  cout << compare(str_1, str_4) << endl;

  return 0;
}