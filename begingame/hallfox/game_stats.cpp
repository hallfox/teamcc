//Game Stats
//Demonstrates declaring and initialzing variables

#include <iostream>
using namespace std;

int main()
{
  int score;
  double distance;
  char playAgain;
  bool shieldsUp;
  
  short lives, aliensKilled;

  score = 0;
  distance = 1200.76;
  playAgain = 'y';
  shieldsUp = true;
  lives = 3;
  aliensKilled = 10;

  double engineTemp = 6572.89;
  
  cout << "\nscore: " << score << endl;
  cout << "distance: " << distance << endl;
  cout << "playAgain: " << playAgain << endl;
  cout << "shieldsUp: " << shieldsUp << endl; //prints 1
  cout << "lives: " << lives << endl;
  cout << "aliensKilled: " << aliensKilled << endl;
  cout << "engineTemp: " << engineTemp << endl;
  
  int fuel;
  cout << "\nHow much fuel? ";
  cin >> fuel;
  cout << "fuel: " << fuel << endl;
  
  typedef unsigned short int ushort; // ooh typedef
  ushort bonus = 10;
  cout << "\nbonus: " << bonus << endl;

  return 0;
}