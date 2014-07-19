//Guess My Number
//The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(static_cast<unsigned int> (time(0)));
  
  int num = rand() % 100 + 1;
  int guess;
  int tries = 0;  

  do
  {
    cout << "Guess my number?: ";
    cin >> guess;
    
    if (guess < num)
      cout << "Wrong! That's too low.\n\n";
    else if (guess > num)
      cout << "Wrong! That's too high.\n\n";
    else
      cout << "Correct! It was " << num;

    tries++;
  } while (guess != num);

  cout << "\n\nIt took you " << tries << " tries." << endl;

  return 0;
}
