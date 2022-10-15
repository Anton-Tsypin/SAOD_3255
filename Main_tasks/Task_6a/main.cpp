// Вариант 7

#include <iostream>
#include "main.h"

void copy_testing(Array a){}

int main(){
  int a[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  // int b[] = { 1, 2, 3, 4, 5, 6 };
  // int c[] = { 0, 0, 0, 0 };

  Array *test = new Array(4, 3, a);
  std::cout << *test << std::endl;
  std::cout << "  copy_testing() start" << std::endl;
  copy_testing(*test);
  std::cout << "  copy_testing() end" << '\n' << std::endl;

  std::cout << "rows: " << test -> Rows() << " cols: " << test -> Cols() << std::endl;
  std::cout << "Array[1][0]: " << test -> Item(1, 0) << std::endl;
  std::cout << "Array[3][1]: " << test -> Item(3, 1) << std::endl;
  // std::cout << "Array[999][999]: " << test -> Item(3, 3) << std::endl;

  Array *reshaped = test -> Reshape(2, 6);
  std::cout << *reshaped;

  std::cout << std::endl << "element changed in first Array" << std::endl;
  test -> Item(1, 1) = 10 * test -> Item(1, 1); 
  std::cout << *test << std::endl << *reshaped;

  std::cout << std::endl;
  delete test;
  delete reshaped;
  return 0;
}