#include <iostream>

class Test {
  public:
    int val;
    Test() {
      val = 0;
      std::cout << this << " -- created" << std::endl;
    }

    ~Test() {
      std::cout << this << " -- deleted" << std::endl;
    }

    void get_val() {
      std::cout << this << " -- val = " << val << std::endl;
    }
};

