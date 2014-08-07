#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    vector<string>::iterator iter;
    vector<string> games;
    string input;

    cout << "Welcome to your Games List!\n";

    while(true)
    {
	cout << "Here's your list of games:\n";
	
	for (iter = games.begin(); iter != games.end(); iter++)
	{
	    cout << *iter << endl;
	}
	
	cout << "\nYou can add, remove, or quit the program.\n";
	cout << "\nWhat do you want to do?\n";
	cout <<">> ";
	cin >> input;
	cin.ignore();

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	if (input == "add")
	{
	    cout << "\nEnter a game to add: ";
	    //ws(cin); //gets rid of trailing \n
	    getline(cin, input);
	    games.push_back(input);
	    cout << "\nAdded '" << input << "'" << endl;
	}
	else if (input == "remove")
	{
	    cout << "\nEnter a game to remove: ";
	    //ws(cin); //gets rid of trailing \n
	    getline(cin, input);
	    iter = find(games.begin(), games.end(), input);
	    if (iter != games.end())
	    {
		games.erase(iter);
	    }
	    else
	    {
		cout << "\nCould not find '" << input << "'" << endl;
	    }
	}
	else if (input == "quit")
	{
	    cout << "\nQuitting...\n";
	    break;
	}
	else
	{
	    cout << "I don't understand how to '" << input << "'" << endl;
	}
    }
    
    cout << "Thanks for using! Goodbye.";
    
    return 0;
}
