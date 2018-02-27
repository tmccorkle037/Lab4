// Lab4_strings.cpp
// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab4_strings.cpp -o Lab4_strings -std=c++11
//      or:  g++ Lab4_strings.cpp -o Lab4_strings -std=c++0x
// Some initialization methods and other things are not supported by the old standard. 

#include <iostream>
#include <string>

using namespace std;

// Complete the assignments stated in the comments.
int main()
{
// ****************************************************************************
// Declare and initialize four or five strings. Use different ways of
// initializing, as shown in Table 7.1 (Lecture 7). 
// Try all the operations in Table 7.2 (Lecture 7) using the strings that
// you declared.
// ****************************************************************************

// -----------------------------------------------------------------------
	string line;
	cout << "\nEnter some text:" << endl;
	getline(cin, line);
	cout << line << endl << endl;

// ****************************************************************************
// Use "Range for" loops (L7_Ex6_Strings.cpp) and operations in table 7.3 to:
// 1) Count the number of letters in your input line above;
// 2) Count the number of digits;
// 3) Count the number of words (may be separated by white spaces, dots, etc.);

// 4) change the case of the letters (upper to lowercase and vice-versa).
// 5) Replace any whitespace with a dot ('.').
// Print the converted text in 4) and 5)
// ****************************************************************************

	return 0;
}