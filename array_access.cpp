// C++ Program to print the elements of a
// Two-Dimensional array
#include <iostream>
using namespace std;

int main() {
  // initialize an array with 3 rows and 2 columns.
  int x[3][2] = {{0, 1}, {2, 3}, {4, 5}};

  // cout << x << endl;
  // cout << &(x[0][0]) << endl;
  // cout << &(x[0][1]) << endl;
  // cout << &(x[1][0]) << endl;
  // cout << x[0] << endl;
  // cout << x[1] << endl;
  // cout << x[2] << " : " << &(x[2][0]) << endl;

  // access 2d array element's value
  // 1.
  cout << "method 1" << endl;
  cout << "Element at x[0][0] address: " << &(x[0][0]) << " value: " << x[0][0]
       << endl;
  cout << "Element at x[0][1] address: " << &(x[0][1]) << " value: " << x[0][1]
       << endl;
  cout << "Element at x[1][0] address: " << &(x[1][0]) << " value: " << x[1][0]
       << endl;
  cout << "Element at x[1][1] address: " << &(x[1][1]) << " value: " << x[1][1]
       << endl;

  // 2.
  cout << "method 2" << endl;
  cout << "Element at x[0][0] address: " << *x << " value: " << **x << endl;
  cout << "Element at x[0][1] address: " << *x + 1 << " value: " << *(*x + 1)
       << endl;
  cout << "Element at x[1][0] address: " << *x + 2 << " value: " << *(*x + 2)
       << endl;
  cout << "Element at x[1][1] address: " << *x + 3 << " value: " << *(*x + 3)
       << endl;

  // 3.
  cout << "method 3" << endl;
  int *ptr = (int *)x;
  cout << "Element at x[0][0] address: " << ptr << " value: " << *ptr << endl;
  cout << "Element at x[0][1] address: " << ptr + 1 << " value: " << *(ptr + 1)
       << endl;
  cout << "Element at x[1][0] address: " << ptr + 2 << " value: " << *(ptr + 2)
       << endl;
  cout << "Element at x[1][1] address: " << ptr + 3 << " value: " << *(ptr + 3)
       << endl;

  // 4.
  cout << "method 4" << endl;
  int *ptr1 = reinterpret_cast<int *>(x);
  cout << "Element at x[0][0] address: " << ptr1 << " value: " << *ptr1 << endl;
  cout << "Element at x[0][1] address: " << ptr1 + 1
       << " value: " << *(ptr1 + 1) << endl;
  cout << "Element at x[1][0] address: " << ptr1 + 2
       << " value: " << *(ptr1 + 2) << endl;
  cout << "Element at x[1][1] address: " << ptr1 + 3
       << " value: " << *(ptr1 + 3) << endl;

  return 0;
}
