#include <iostream>
using namespace std;

int main()
{
  //1. A literal is the value on its own (ie "string", 7, 2.17 ...) while a
  //   declared constant is referred to like a variable (ie pi) but cannot be
  //   be changed.
  //2. A normal variable can be reassigned, a constant cannot.
  //3.
  double Feet = 5.7; //I think?
  const double MetersPerFoot = 0.3048; //Man These Capital Letters Are Annoying
  double Meters = Feet * MetersPerFoot;
  //4.
  const float pi = 3.14159;
  double radius;

  //bare with me newbies
  cout << "Enter the radius: "; //print a prompt
  cin >> radius; //get the user input
  cout << "The diamameter is: " << radius * 2 << endl; //endl "ends the line"
  cout << "The area is: " << radius * radius * pi << endl;
}
