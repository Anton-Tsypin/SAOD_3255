#include <iostream>
#include <vector>
#include <tuple>
#include "main.h"

int main() {

	std::vector<double> x = 
    { 0.0855298042e+00, 1.4513241053e+00, 1.3237277269e+00, 
      1.0128350258e+00, 1.4122089148e+00, 6.5826654434e-01, 
      2.0795986652e+00, 1.0230206251e+00, 1.4231411219e+00,
      1.1091691256e+00, 1.7714337111e+00, 1.3986129761e+00,
      1.0640757084e+00, 1.4216910601e+00, 1.2402026653e+00 };

  std::vector<double> y = 
    { 2.1147451401e+00, 1.5606760979e+00, 1.0568326712e+00,
      1.1379202604e+00, 8.5802090168e-01, 1.2779158354e+00,
      1.1540910006e+00, 2.2799887657e+00, 1.5069425106e+00,
      2.4955313206e+00, 1.1681622267e+00, 1.3716301918e+00,
      1.3439905643e+00, 8.5801953077e-01, 1.5243546963e+00 };


  std::cout << std::endl << "Box_info() for x:" << std::endl;
	std::tuple<double, double, double> x_answer = Box_info(x, 2);
  
  std::cout << std::endl << "Box_info() return:"  << std::endl;
  std::cout << "mean:\t"   << std::get<0>(x_answer) << std::endl;
  std::cout << "median:\t" << std::get<1>(x_answer) << std::endl;
  std::cout << "stddev:\t" << std::get<2>(x_answer) << std::endl;


  std::cout << std::endl << std::endl << "Box_info() for y:" << std::endl;
	std::tuple<double, double, double> y_answer = Box_info(y, 4);
  
  std::cout << std::endl << "Box_info() return:"  << std::endl;
  std::cout << "mean:\t"   << std::get<0>(y_answer) << std::endl;
  std::cout << "median:\t" << std::get<1>(y_answer) << std::endl;
  std::cout << "stddev:\t" << std::get<2>(y_answer) << std::endl;
  std::cout << std::endl;
  
  return 0;
}
