#include <iostream>
#include "Str.h"

Str str = Str("Hello world");

void Test(Str s) {}

int main(){
  int len = strlen(str);
  std::cout << str << " | len: " << len << std::endl;
  Test(str);
  std::cout << str << std::endl;

  Str t;
  t = str;
  std::cout << "str: " << str << " | t: " << t << std::endl;
  Str tt("test");
  tt = str = tt;
  std::cout << "str: " << str << " | tt: " << tt << std::endl;

  str += "_success";
  std::cout << "+=: " << str << std::endl;

  Str a("te"), b("st");
  Str c = a + b;
  std::cout << "a: " << a << " | b: " << b << " | c: " << c << std::endl;

  return 0;
};
