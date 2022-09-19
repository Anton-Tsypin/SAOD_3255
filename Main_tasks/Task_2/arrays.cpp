#include <iostream>

using namespace std;

void rotate (int a[], int n) { 
  int x = a[0];
  for (int i = 1; i < n; i++)
    a[i - 1] = a[i];
  a[n - 1] = x;
};

int main(){
  int a[5]{ 1, 2, 3, 4, 5 };
  cout << "a = " << a << endl;

  for(int i = 0; i < 5; i++)
    cout << a[i] << ' ';
  cout << endl;


  for (int *p = a; p - a < 5; p++)
    cout << "|  *p = " << *p << "  |  p = " << p << "  |  a = " << a << "  |  p - a = " << p - a << "  |" << endl;
	cout << endl;

  
};  