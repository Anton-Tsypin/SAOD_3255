#include <iostream>

class Array;

class _data{
  public:
    int* pData;
    int nCount;

    friend class Array;

    _data(int sz, int *p = 0){
      nCount = 1;
      pData = new int[sz];
      std::cout << pData << std::endl;
      if(*p == 0){
        std::fill(pData, pData + sz, 0);
      }
      else{
        pData = p;
      }
      std::cout << pData << std::endl;
      for(int *ptr = pData; ptr - pData < sz; ptr++){
        std::cout << *ptr << ' ';
      }
    }
    ~_data(){ delete []pData; }

    void AddRef(){ 
      nCount++; 
    }
    void Release(){ 
      nCount--; 
      if(nCount == 0){ 
        delete this; 
      } 
    }
};