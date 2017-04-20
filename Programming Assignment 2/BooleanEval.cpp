#include "stdafx.h"
#include "BooleanEval.h"
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

void BooleanEval(string input) {
	int inLength = 0;
	int leftPar = 0;
	int rightPar = 0;
	string leftSide;
	string rightSide;
	bool valid = true;
	bool equal = false;

	inLength = input.length();
	//rewind;

	for (int i = 0; i < inLength; i++) {
		char temp;
		temp = input.at(i);
		if ((temp != '*') && (temp != '+') && (temp != ' ') && (temp != '=') && (temp != '0') && (temp != '1') && (temp != '(') && (temp != ')')) {
			valid = false;
		}
		if ((input.at(0) == '*') || (input.at(0) == '+') || (input.at(0) == '-') || (input.at(0) == '^') || (input.at(0) == '=')) {
			valid = false;
		}
		if ((i >= 2) && ((temp == '+') || (temp == '*') || (temp == '-') || (temp == '^') || (temp == '=')) &&
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
		cout << "The boolean line: '" << input << "' is invalid." << endl;
	}
	else {
		cout << "The boolean line: '" << input << "' is valid." << endl;
	}
}