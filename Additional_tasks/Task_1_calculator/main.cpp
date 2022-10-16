#include <iostream>
#include <string>

int main(int argc, char **argv){

  double a, b, result; char c;
  
  a = std::stod(argv[1]);
  c = *argv[2];
  b = std::stod(argv[3]);

  switch(c){
    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*': result = a * b; break;
    case '/': result = a / b; break;
  }

  std::cout << "Result is: " << result << std::endl;

  return 0;
}
