#include <iostream>

int main(){

  double a, b, result; char c;

  while(1){
    std::cin >> a >> c >> b;
    switch(c){
      case '+': result = a + b; break;
      case '-': result = a - b; break;
      case '*': result = a * b; break;
      case '/': result = a / b; break;
    }
    std::cout << "Result is: " << result << std::endl;
  }

  return 0;
}
