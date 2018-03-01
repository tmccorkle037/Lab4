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
	string line2 = "Hello";	//line2 is a copy of the string literal "Hello"
	string line3(4, '!');	//initializes line3 with 4 copies of the '!' character
	string line5("Dogs are cool"); //line5 is a copy of the string literal, doesn't include null terminator
	string line6;	//declares line6 as an empty string

	cout << "\nEnter some text:";
	getline(cin, line);

	string line4 = line;	//line4 is a copy of line
	cout <<"\n\nValue of line: " << line << endl;
	cout <<"Value of line2: " << line2 << endl;

	if(line == line2){
		cout << "The line entered is the same as line2" << endl;
	}
	else{
		cout << "The line entered is not the same as line2" << endl;
	}
	
	cout << "line2 + line3 = " << line2 + line3 << endl;

	cout << "\nEnter another line of text: ";
	getline(cin, line6);
	
	cout << "\nThis is line6: " << line6 << endl;
	cout << "line6[0]: " << line6[0] << endl;

	if(line6.empty()){
		cout << "line6 is empty, enter a string: ";
		cin >> line6;
	}
	
	line = line5;	//line is a copy of line5 ("Dogs are cool")

	auto num = line6.size();
	cout << "number of characters in line6: " << num << endl;
	
	cout << "Comparing line6[0] and line6[1]: ";
	if( line6[0] < line6[1] ){
		cout << line6[0] << "<" << line6[1] << endl;
	}
	else{
		cout << line6[0] << ">" << line6[1] << endl;
	}
// ****************************************************************************
// Use "Range for" loops (L7_Ex6_Strings.cpp) and operations in table 7.3 to:
// 1) Count the number of letters in your input line above;
// 2) Count the number of digits;
// 3) Count the number of words (may be separated by white spaces, dots, etc.);

// 4) change the case of the letters (upper to lowercase and vice-versa).
// 5) Replace any whitespace with a dot ('.').
// Print the converted text in 4) and 5)
// ****************************************************************************
	int countL;
	int countD;
	int wordCount = 1; //starts at one becasue if there's a string there is always atleast one word

	for( auto c : line6 ){
		if(!(isspace(c))){	//if c is not a space determine if it's a character or digit	
			if( isalpha(c) ){	//if c is a letter, change the casing
				countL++;
				if(isupper(c)){
                                	c = tolower(c);
                                	cout << c;
                        	}
                        	else{	//c is a lower case letter
                                	c = toupper(c);
                                	cout << c;
                         	}
			}
			else if( isdigit(c) ){
				countD++;
				cout << c;
			}	
		}
		else{	//c is a space 
			wordCount++; 
			c ='.';
			cout << c;
		}
	}

	cout << "\nLetters in line6: " << countL << endl;
	cout << "Digits in line6: " << countD << endl;
	cout << "Number of words: " << wordCount << endl;


	return 0;
}
