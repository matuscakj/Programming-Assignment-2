#include "stdafx.h"
#include "AlgebraEval.h"
#include <iostream>
#include <string>
using namespace std;

//string trim(const string& str) {
//	size_t first = str.find_first_not_of(' ');
//	if (string::npos == first)
//	{
//		return str;
//	}
//	size_t last = str.find_last_not_of(' ');
//	return str.substr(first, (last - first + 1));
//}

void AlgebraEval(string input) {
	int inLength = 0;
	int leftPar  = 0;
	int rightPar = 0;
	int leftBra  = 0;
	int rightBra = 0;
	string leftSide;
	string rightSide;
	bool valid = true;
	bool equal = false;

	inLength = input.length();
	//rewind;

	for (int i = 0; i < inLength; i++) {
		char temp;
		temp = input.at(i);
		if ((temp != '*') && (temp != '+') && (temp != '-') && (temp != '^') && (temp != ' ') && (temp != '=') && (temp != '0') && (temp != '1') &&
			(temp != '2') && (temp != '3') && (temp != '4') && (temp != '5') && (temp != '6') && (temp != '7') && (temp != '8') && (temp != '9') &&
			(temp != '(') && (temp != ')')) {
			valid = false;
		}
		if (((temp == '+') || (temp == '*') || (temp == '-') || (temp == '^') || (temp == '=')) &&
			(((input.at(i - 1) == '+') || (input.at(i - 1) == '*') || (input.at(i - 1) == '-') || (input.at(i - 1) == '^') || (input.at(i - 1) == '=')) ||
			  (input.at(i - 2) == '+') || (input.at(i - 2) == '*') || (input.at(i - 2) == '-') || (input.at(i - 2) == '^') || (input.at(i - 2) == '='))) {
			valid = false;
		}
		if (temp == '=') {
			equal = true;
		}
		if (temp == '(') {
			leftPar++;
		}
		if (temp == ')') {
			rightPar++;
		}
	}
	if ((leftPar != rightPar) || !equal || !valid) {
		cout << "The algebra line: '" << input << "' is invalid." << endl;
	}
	else {
		cout << "The algebra line: '" << input << "' is valid." << endl;
	}
}