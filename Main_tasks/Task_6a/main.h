#include <iostream>

class Array;

class _data{
  int* pData;
  int nCount = 1;

  friend class Array;

  _data(int sz, int *p = 0){
    nCount = 1;
    pData = new int[sz];
    if(*p == 0){
      std::fill(pData, pData + sz, 0);
    }
    else{
      pData = p;
    }
    std::cout << this << " _data created: ";
    for(int *ptr = pData; ptr - pData < sz; ptr++){
      std::cout << *ptr << ' ';
    } std::cout << std::endl;
  }
  ~_data(){ 
    delete[] pData; 
    std::cout << this << " _data deleted" << std::endl;
  }

  void AddRef(){ 
    nCount++; 
    std::cout << this << " _data AddRef count: " << nCount << std::endl;
  }
  void Release(){ 
    nCount--; 
    std::cout << this << " _data Release count: " << nCount << std::endl;
    if(nCount == 0){ 
      delete this; 
    } 
  }
};

class Array{
  int rows, cols;
  friend class _data;
  _data *pDataRef;
  public:
    Array(int m, int n, int *p = 0){
      rows = m; cols = n;
      pDataRef = new _data(m*n, p);
      std::cout << this << " Array created with " << rows << " x " << cols << " shape | data: " << pDataRef << std::endl;
    }

    Array(const Array &a){
      pDataRef = a.pDataRef;
      pDataRef -> AddRef();
      std::cout << this << " Array copied from " << &a << std::endl;
    }

    int Rows(){ return rows; }
    int Cols(){ return cols; }

    int & Item(int i, int j){
      if(i >= 0 && i <= rows-1 && j >= 0 && j <= cols-1){
        return pDataRef -> pData[cols * i + j];
      }
      else{
        std::cout << "i = " << i << " | rows = " << rows-1 << " | j = " << j << " | cols = " << cols-1 << std::endl;
        throw std::out_of_range("Index out of range");
      }
    }

    int const Item(int i, int j) const{
      if(i >= 0 && i <= rows-1 && j >= 0 && j <= cols-1){
        int elem = pDataRef -> pData[cols * i + j];
        return elem;
      }
      else{
        throw std::out_of_range("Index out of range");
      }
    }

    Array* Reshape(int m, int n){
      if(m * n == rows * cols){
        Array *reshaped = new Array(m, n, pDataRef -> pData);
        return reshaped;
      }
      else{
        throw std::invalid_argument("Array & View size mismatch");
      }
    }

    ~Array(){ 
      this -> pDataRef -> Release(); 
      std::cout << this << " Array deleted" << std::endl;
    }
};


std::ostream & operator << (std::ostream &os, Array &t){
  int rows = t.Rows();
  int cols = t.Cols();
  for(int i = 0; rows - i != 0; i++){
    os << "[ ";
    for(int j = 0; cols - j != 0; j++){
      int num = t.Item(i, j);
      os << num;
      if(j != cols-1){ os << ", "; }
    }
    os << " ]" << std::endl;
  }

  return os;
} 