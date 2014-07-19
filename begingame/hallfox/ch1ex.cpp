#include <iostream>
using namespace std;

int main()
{

  //1.
  //good names, short but descriptive
  int count;
  char letter;
  double pi;
  //bad names
  int theCountOfMyLoop; //way too long
  char m; //too short
  double the_valuePi; //inconsistent naming conventions

  //2.

  //Seven divided by three is 2
  cout << "Seven divided by three is " << 7 / 3 << endl;
  //Seven divided by three is 2.33333333
  cout << "Seven divided by three is " << 7.0 / 3 << endl;
  //Seven divided by three is 2.33333333
  cout << "Seven divided by three is " << 7.0 / 3.0 << endl;

  //3.
  int a, b, c;

  cout << "Enter three scores: " << endl;
  cout << "Score 1: ";
  cin >> a;
  cout << "Score 2: ";
  cin >> b;
  cout << "Score 3: ";
  cin >> c;
  cout << "The average is " << (a + b + c) / 3.0 << endl;
}
