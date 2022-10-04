#include <iostream>
#include <cmath>

class Complex{
public:
  double Re, Im;
  Complex(double re = 0, double im = 0){
    Re = re; Im = im;
  };

  Complex Conjugate(){
    Complex answer(Re, -Im);
    return answer;
  };

  double Mod(){
    return sqrt(pow(Re, 2) + pow(Im, 2));
  };

  double Arg(){
    if(Mod() == 0){
      return 0;
    } 
    else if(Re > 0){
      return atan(Im/Re);
    }
    else if(Re < 0){
      if(Im >= 0){
        return acos(-1) + atan(Im/Re);
      }
      else if(Im < 0){
        return -acos(1) + atan(Im/Re);
      }
    }
    else{
      if(Im > 0){
        return acos(0);
      }
      else if(Im < 0){
        return -acos(0);
      }
    }
    return 0;
  };

  Complex operator + (const Complex &c) const 
  { return Complex (Re + c.Re, Im + c.Im); }

  Complex operator - (const Complex &c) const 
  { return Complex (Re - c.Re, Im - c.Im); }

  Complex operator * (const Complex &c) const 
  { return Complex (Re * c.Re - Im * c.Im, Im * c.Re + c.Im * Re); }

  Complex operator / (const Complex &c) const 
  { return Complex ((Re * c.Re + Im * c.Im) / (c.Re * c.Re +  c.Im * c.Im), (-Re * c.Im + c.Re * Im) / (c.Re * c.Re + c.Im * c.Im)); }
};

inline std::ostream& operator << (std::ostream &o, const Complex &c)
{ return o << '(' << c.Re << ", " << c.Im << ')'; };