#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  //1. Menu Chooser enum
  enum difficulty { EASY = 1, NORMAL, HARD};
  
  cout << "Difficulty Levels\n\n";
  cout << "1 - Easy\n";
  cout << "2 - Normal\n";
  cout << "3 - Hard\n\n";

  int choice; //cannot cin >> enum, so either cast or do this
  cout << "Choice: ";
  cin >> choice;

  switch (choice)
  {
  case EASY:
    cout << "You picked Easy.\n";
    break;
  case NORMAL:
    cout << "You picked Normal.\n";
    break;
  case HARD:
    cout << "You picked Hard.\n";
    break;
  default:
    cout << "You made an illegal choice.\n";
  }

  //2.What's wrong?
  int x = 0;
  while(x) //never stops
  {
    ++x;
    cout << x << endl;
    if (x > 10)
    {
      cout << "Et infinitum..." << endl;
      break;
    }
  }

  //3.Swapped guess numbers
  //other file
  
  return 0;
}
