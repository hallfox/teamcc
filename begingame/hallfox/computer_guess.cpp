#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int comGuess(int comLower, int comUpper)
{
  if (comLower == comUpper) return comLower;
  return rand() % (comUpper - comLower + 1) + comLower;
}

int main()
{
  srand(static_cast<unsigned int> (time(0)));

  int pNum;

  do
  {
    cout << "Enter a number for the computer to guess (between 1 and 100): ";
    cin >> pNum;
  } while (pNum < 1 || pNum > 100);
  
  int comNum;
  int comUpper = 100, comLower = 1;
  int comTries = 0;
  while (comNum != pNum)
  {
    comTries++;
    comNum = comGuess(comLower, comUpper);
    cout << "My guess: " << comLower << " " << comNum << " " << comUpper << endl;
    if (comNum < pNum)
    {
      comLower = comNum + 1;
    }  
    else if (comNum > pNum)
    {
      comUpper = comNum - 1;
    }
    else
    {
      cout << "Your number is: " << comNum << endl;
      cout << "It took me " << comTries << " tries to figure that out." << endl;
    }
  }

  return 0;
}
