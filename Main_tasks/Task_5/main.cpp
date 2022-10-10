#include <iostream>
#include "Test.h"

int Test::nCount = 0;

void foo(Test t){
  std::cout << "foo is running" << std::endl;
  std::cout << "coping object | objects: " << Test::nCount << std::endl;
}

int main(){
  std::cout << "\nstart    | objects: " << Test::nCount << std::endl;
  Test* test = new Test();
  std::cout << "continue | objects: " << Test::nCount << std::endl;
  delete test;
  std::cout << "end      | objects: " << Test::nCount << '\n' << std::endl;

  int count = 3;
  Test **mas = new Test*[count];
  for (int i = 0; i < count; ++i) mas[i] = new Test();
  std::cout << "\ncreating objects | objects: " << Test::nCount << '\n' << std::endl;

  // delete[] mas;
  for (int i=0; i<3; i++){ delete mas[i]; }
  std::cout << "\ndeleting objects | objects: " << Test::nCount << '\n' << std::endl;

  foo(*test);
  std::cout << "delete object | objects: " << Test::nCount << '\n' << std::endl;

  Child* c = new Child;
  delete c;

  std::cout << std::endl;

  Aggregate<Test>* a1 = new Aggregate<Test>;
  delete a1;

  std::cout << std::endl;

  Aggregate<Child>* a3 = new Aggregate<Child>;
  delete a1;

  return 0;
}
