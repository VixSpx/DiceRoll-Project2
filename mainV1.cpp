/* 
 * File:   main.cpp
 * Author: Victor Gutierrez
 * Created on July 19, 2023
 * Purpose:  Project 1 Dice/Guessing Game
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


int main()
{
	string name;  //Player name
	int amnt;     //Amount
	int betAmnt;  //Bet amount placed
	int guess;    //Game Type
	int dice;     //Game method
	char choice;  //Players choice

	srand(time(0));	 // Use for Generating Random Number Each Time.

	cout << "\n===============================================================================================";
	cout << "\n GGGGGGGG       AA        MMM       MMM      EEEEEEEE       ";
        cout <<"\n GG           AA  AA      MMM MM MM MMM      EE             ";
        cout <<"\n GG   GGG    AA AA AA     MMM   MM  MMM      EEEEEEEE       ";
        cout <<"\n GG    GG   AA      AA    MMM       MMM      EE             ";
        cout <<"\n  GGGGGGG  AA        AA   MMM       MMM      EEEEEEEE       ";
	cout <<"\n===============================================================================================\n";

	cout << "\nEnter Player Name: ";
	
        getline(cin, name);

	cout << "\nDeposit Your Amount: $";
	
        cin >> amnt;

	do {
		system("dice");
		
		do { 	cout << "\nWelcome " << name << " Are You Ready To Play? " << "\n\n";
			
                        cout << "Enter Bet Amount: $";
			cin >> betAmnt;
			
                        if (betAmnt > amnt)
				cout << "You Can not Bet More Than Current Amount\n" <<
				"\nRe-enter Amount: ";
		} while (betAmnt > amnt);

		do { 	cout << "Guess The Number Between 1 To 10 :";
			cin >> guess;
			
                        if (guess <= 0 || guess > 10)
				cout << "\nNumber Should Be Between 1 To 10\n" <<
				"\nGuess Number Again: ";
                        
		} while (guess <= 0 || guess > 10);

		dice = rand() % 10 + 1;

		if (dice == guess)
		{
			cout << "\n Congratulations, You Won " << betAmnt * 10 << "$";
			
                        amnt = amnt + betAmnt * 10;
		}
		else
		{
			cout << "Sorry, You Lose " << betAmnt << "$\n";
			
                        amnt = amnt - betAmnt;
		}

		cout << "\nThe Winning Number Is: " << dice << "\n";
		cout << "\n" << name << ", Your Remaining Balance Is " << amnt << "$\n";
		
                if (amnt == 0)
		{
			cout << "\nSorry, You Don't Have Enough Money To Play \n";
			
		}

		cout << "\nYou Want To Play Again Press (y/n)? ";
		cin >> choice;
                
	} while (choice == 'Y' || choice == 'y');

	cout << "\n===============================================================================================\n";
	cout << "Thanks For Playing Game, Your Current Balance Is " << amnt << "$";
	cout << "\n===============================================================================================\n";

	return 0;
}

//Functions & Arrays will implement the rules system & different outputs.