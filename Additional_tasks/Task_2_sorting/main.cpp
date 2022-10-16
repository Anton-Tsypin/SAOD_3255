#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  std::cout << std::endl;
  
  size_t reverse = 0;
  if(*argv[1] == 'r'){ reverse = 1; }

  const size_t N = argc - 1 - reverse;
  double* array = new double[N];

  const size_t iter = reverse + 1;
  for(size_t i = iter; i < argc; i++){
    array[i - iter] = std::stod(argv[i]);
  }
  
  for(double *p = array; p - array < N; p++){
    std::cout << *p << ' ';
  }
  std::cout << std::endl << std::endl;

  if(reverse){ std::cout << "reverse "; } std::cout << "sorting" << std::endl;

  std::cout << std::endl;
  return 0;
};
