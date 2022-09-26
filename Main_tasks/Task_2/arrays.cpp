#include <iostream>

using namespace std;

void rotate (int a[], int n, bool clockwise = false) { 
  if (clockwise == false){
    int *px = a + 4; int x = *a;
    for(int *p = a; p - a < n; p++){
      int *pp = p + 1;
      *p = *pp;
    };
    *px = x;
  } 
  else 
  {
    int *px = a; int x = *a + 4;  
    for(int *p = a + 4; p - a > 0; p--){
      int *pp = p - 1;
      *p = *pp;
    };
    *px = x;
  };
};

int main(){
  int a[5]{ 1, 2, 3, 4, 5 };
  cout << "a = " << a << endl;

  for (int *p = a; p - a < 5; p++)
    cout << "|  *p = " << *p << "  |  p = " << p << "  |  a = " << a << "  |  p - a = " << p - a << "  |" << endl;
	cout << endl;

  for(int i = 0; i < 5; i++)
    cout << a[i] << ' ';
  cout << endl;

  rotate(a, 5);
  
  for(int i = 0; i < 5; i++)
    cout << a[i] << ' ';
  cout << endl;
  
  int b[5]{ 1, 2, 3, 4, 5 };

  rotate(b, 5, true);
  
  for(int i = 0; i < 5; i++)
    cout << b[i] << ' ';
  cout << endl;

  return 0;
};  