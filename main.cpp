/* ------------------------------------------------
   prog1RockPaperScissors.cpp

   Program #1: Play the game of Paper / Rock / Scissors against the computer.
   Class: CS 141
   Author: Alejandro Cabral

	 See the program description page on the course web site at bit.ly/cs141
	 Within Codio you can run the solution by doing the following steps:
   1. Select the Tools / Terminal menu option
	 2. Within the terminal window, type in:  ./solution

   Grading Rubric:
		 55 Execution points
						  Option 1: (Computer always chooses R) and:
					 2		 User input of X immediately exits program
					 3		 User input of x (lower case) immediately exits program
				  10		 Program handles both lower and upper case user input (e.g. 'r' and 'R'); also
							  move number increments each move
				  15		 Score updates correctly for all user inputs: r, p, s
						  Option 2: Computer's move is random and:
					 7		 Predetermined input sequence correctly leads to computer win
				   8		 Predetermined input sequence correctly leads to human win
				 Option 3:
		   2     Correctly displays and updates the graphical score
			   8     Correctly displays and updates the graphical score, with assessment results hidden

		 45 Programming Style (Given only if program runs substantially correctly)
					10 Meaningful identifier names
					10 Comments: Has header.  Comments on each block of code.
					15 Appropriate data and control structures.  Code duplication is avoided.
					10 Code Layout: Appropriate indentation and blank lines.

   Having sample program output is not required within this header of your program, though it is helpful.


*/

#include <iostream>    // For cin and cout
#include <cstdlib>     // For rand()
using namespace std;


//-----------------------------------------------------------------------------------------
// *** Arvan: Great job.
int main()
{
	// Display Instructions
	cout << "CS 141 Program #1: Rock/Paper/Scissors                                \n"
		<< endl
		<< "Welcome to the game of Rock/Paper/Scissors where you play against     \n"
		<< "the computer.  On each move the computer will choose R, P, or S, then \n"
		<< "the user will be prompted for their choice, and then the score will   \n"
		<< "be updated.  P beats R, R beats S, and S beats P. The score starts    \n"
		<< "at 0.  Add one if the person wins, subtract one if the computer wins. \n"
		<< "The game ends if the score reaches -5 or + 5.                         \n"
		<< "User input of 'x' or 'X' causes the game to exit.                     \n"
		<< endl
		<< "Here we go!  \n"
		<< endl;

	int computerChoiceVersion;
	cout << "Select how the computer chooses its move: \n"
		<< "1. Always choose Rock \n"
		<< "2. Random guess \n"
		<< "3. Random guess with graphical score \n"
		<< "Enter your choice: ";
	cin >> computerChoiceVersion;
	cout << endl << endl;

	int roundNum = 1;          // counter for rounds
	int score = 0;
	char computerChoice = ' ';
	char userChoice = ' ';

	// Main loop should go here, with the indented sections below inside the main loop
	while ((score > -5) || (score < 5))
	{
		int randomChoice = rand() % 3;
		cout << endl << roundNum << ". Your move: ";

		// Get the computer choice
		// Option 1: Computer always picks rock
		if (computerChoiceVersion == 1)
		{
			computerChoice = 'R';
		}
		// Option 2: Random picks between 0 - 2; each number corresponding to rock/paper/scissors
		else if (computerChoiceVersion >= 2)
		{
			if (randomChoice == 0)
			{
				computerChoice = 'R';
			}
			else if (randomChoice == 1)
			{
				computerChoice = 'P';
			}
			else
			{
				computerChoice = 'S';
			}
		}
		else if (computerChoiceVersion > 3)
		{
			break; // just in case
		}

		// Prompt for and get the user's choice
		cin >> userChoice;

		// Check if user wants to exit
		if (userChoice == 'x' || userChoice == 'X')
		{
			cout << endl << "Exiting program..." << endl;
			break;
		}

		// Display computer choice
		cout << endl << "   Computer chose ";
		cout << computerChoice << endl;


		// Update score, and then display it
		// User option as paper vs. computerChoice
		if ((userChoice == 'p' || userChoice == 'P') && (computerChoice == 'r' || computerChoice == 'R'))
		{
			score++;
			cout << "   User's point.";
		}
		else if ((userChoice == 'p' || userChoice == 'P') && (computerChoice == 's' || computerChoice == 'S'))
		{
			score--;
			cout << "   Computer's point.";
		}
		else if ((userChoice == 'p' || userChoice == 'P') && (computerChoice == 'p' || computerChoice == 'P'))
		{
			cout << "   Tie.";
		}

		// User option as scissors vs. computerChoice
		else if ((userChoice == 's' || userChoice == 'S') && (computerChoice == 'r' || computerChoice == 'R'))
		{
			score--;
			cout << "   Computer's point.";
		}
		else if ((userChoice == 's' || userChoice == 'S') && (computerChoice == 'p' || computerChoice == 'P'))
		{
			score++;
			cout << "   User's point.";
		}
		else if ((userChoice == 's' || userChoice == 'S') && (computerChoice == 's' || computerChoice == 'S'))
		{
			cout << "   Tie.";
		}

		// User option as rock vs. computerChoice
		else if ((userChoice == 'r' || userChoice == 'R') && (computerChoice == 'r' || computerChoice == 'R'))
		{
			cout << "   Tie.";
		}
		else if ((userChoice == 'r' || userChoice == 'R') && (computerChoice == 'p' || computerChoice == 'P'))
		{
			score--;
			cout << "   Computer's point.";
		}
		else if ((userChoice == 'r' || userChoice == 'R') && (computerChoice == 's' || computerChoice == 'S'))
		{
			score++;
			cout << "   User's point.";
		}

		// Display score for Option 1 & 2
		if (computerChoiceVersion < 3)
		{
			cout << " Score: " << score << endl << endl;
		}
		// Display score for Option 3
		else
		{
			cout << endl << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
			cout << "   ----------------------------------" << endl;
			cout << "   ";
			for (int x = 0; x < score + 5; x++)
			{
				cout << "...";
			}
			cout << "..^" << endl;
		}

		// Increment move number
		roundNum++;
		// Stop program once top score is reached
		if ((score == -5) || (score == 5))
		{
			break;
		}

	}
	// Display final message, depending on the score
	if (score == 0)
	{
		cout << "Tie game!" << endl << endl;
	}
	else if ((score < 0) && (score >= -5))
	{
		cout << "Computer wins!" << endl << endl;
	}
	else if ((score > 0) && (score <= 5))
	{
		cout << "User wins!" << endl << endl;
	}

	cout << "Ending program..." << endl;
	return 0;   // Keep C++ happy
}//end main()
