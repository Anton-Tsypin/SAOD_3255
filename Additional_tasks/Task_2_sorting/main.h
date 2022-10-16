#include <iostream>

void Print_array(double* array, size_t N) {
  std::cout << '[';
  for (double *p = array; p - array < N; p++) {
    std::cout << *p; 
    if (p - array == N - 1) { continue; }
    std::cout << ", ";
  }
  std::cout << ']' << std::endl;
}

bool Condition(double first, double second, bool reverse) {
  if(reverse) { return first < second; }
  else { return first > second; }
}

void Sort_array(double* array, size_t N, bool reverse) {

  int flag_break;
  double temp;

  for (size_t i = 0; i < N - 1; i++) {
    flag_break = 1;
    for (size_t j = 0; j < N - i - 1; j++) {

      if (Condition(array[j], array[j + 1], reverse)) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        flag_break = 0;
      }
    }
    if (flag_break) { break; }
  }
}
