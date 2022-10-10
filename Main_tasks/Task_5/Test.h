#include <iostream>

class Test{
  public:
    static int nCount;

    Test(){
      nCount++;
      std::cout << "  Test class object created." << std::endl;
    };

    ~ Test(){
      nCount--;
      std::cout << "  Test class object destroyed." << std::endl;
    }

    Test(const Test &t){
      nCount++;
      std::cout << "  Test class object copied." << std::endl;
    }
    
};

class Child: public Test{
  public:
  
    Child(){
      std::cout << "  Child class object created." << std::endl;
    };

    ~ Child(){
      std::cout << "  Child class object destroyed." << std::endl;
    }
};

template <typename T>
class Aggregate{
  public:

    T m_obj;
  
    Aggregate(){
      std::cout << "  Aggregate class object created." << std::endl;
    };

    ~ Aggregate(){
      std::cout << "  Aggregate class object destroyed." << std::endl;
    }
};
