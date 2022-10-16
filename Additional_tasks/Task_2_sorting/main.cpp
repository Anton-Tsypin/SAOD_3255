#include <iostream>
#include <string>
#include "main.h"

int main(int argc, char **argv) {
  
  std::cout << std::endl;
  bool reverse = false;
  if (*argv[1] == 'r') { reverse = true; }

  const size_t N = argc - 1 - reverse;
  double* array = new double[N];
  double* sorted_array = new double[N];

  const size_t iter = reverse + 1;
  for (size_t i = iter; i < argc; i++) {
    array[i - iter] = std::stod(argv[i]);
  }
  
  Print_array(array, N);

  if (reverse) { std::cout << "reverse "; } std::cout << "sorting" << std::endl;

  Sort_array(array, N, reverse);

  Print_array(array, N);
  
  std::cout << std::endl;
  return 0;
};
