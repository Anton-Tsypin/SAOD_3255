#include <iostream>
#include <string>

int main(int argc, char **argv){

  double a = 0, b = 0, result = 0; char c = '+';
  
  if(argc > 3){
    a = std::stod(argv[1]);
    c = *argv[2];
    b = std::stod(argv[3]);
  }

  switch(c){
    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*': result = a * b; break;
    case '/': result = a / b; break;
  }

  std::cout << a << ' ' << c << ' ' << b << " = " << result << std::endl;

  return 0;
}
