#include "stdafx.h"
#include "SetsEval.h"
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

void SetsEval(string input) {
	int inLength = 0;
	int leftPar = 0;
	int rightPar = 0;
	int leftBra = 0;
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
		if ((temp != '*') && (temp != '+') && (temp != ' ') && (temp != '=') && (temp != '0') && (temp != '1') && (temp != '2') && (temp != '3') && (temp != '4') && (temp != '5') &&
			(temp != '6') && (temp != '7') && (temp != '8') && (temp != '9') && (temp != 'a') && (temp != 'b') && (temp != 'c') && (temp != 'd') && (temp != 'e') && (temp != 'f') &&
			(temp != 'g') && (temp != 'h') && (temp != 'i') && (temp != 'j') && (temp != 'k') && (temp != 'l') && (temp != 'm') && (temp != 'n') && (temp != 'o') && (temp != 'p') &&
			(temp != 'q') && (temp != 'r') && (temp != 's') && (temp != 't') && (temp != 'u') && (temp != 'v') && (temp != 'w') && (temp != 'x') && (temp != 'y') && (temp != 'z') &&
			(temp != '(') && (temp != ')') && (temp != '{') && (temp != '}') && (temp != ',')) {
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
		if (temp == '{') {
			leftBra++;
		}
		if (temp == '}') {
			rightBra++;
		}
	}
	if ((leftPar != rightPar) || (leftBra != rightBra) || !equal || !valid) {
		cout << "The set line: '" << input << "' is invalid." << endl;
	}
	else {
		cout << "The set line: '" << input << "' is valid." << endl;
	}
}