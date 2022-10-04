#include <iostream>
#include "complex.h"

int main(){
  Complex a(1, 2), b(3), c;
  std::cout << "a: " << a << " | b: " << b << " | c: " << c << std::endl;  

  std::cout << "\na + b: " << a + b << std::endl;
  std::cout << "a - b: " << a - b << std::endl;
  std::cout << "a * b: " << a * b << std::endl;
  std::cout << "a / b: " << a / b << std::endl;

  std::cout << "\na / a: " << a / a << std::endl;
  std::cout << "a * b / b: " << a * b / b << std::endl;

  std::cout << "\na Conjugate: " << a.Conjugate() << std::endl;

  std::cout << "\na Mod: " << a.Mod() << std::endl;
  std::cout << "a Arg: " << a.Arg() << std::endl;

  Complex v[4]{ 1,2, Complex (2,3) };
  for(Complex *p = v; p - v < 4; p++){
  std::cout << *p << ' ';
  }
  std::cout << std::endl;

  Complex* pd = new Complex(3, 4);
  std::cout << "\n" <<  pd << ' ' << *pd <<  std::endl;

  std::cout << "Re: " << pd -> Re << " | Im: " << pd -> Im << std::endl;
  delete pd;
  
  return 0;
}