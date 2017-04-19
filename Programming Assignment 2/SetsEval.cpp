#include "stdafx.h"
#include "SetsEval.h"
#include <iostream>
#include <string>
using namespace std;

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

	for (int i = 0; i <= inLength; i++) {
		char temp;
		temp = input.at(i);
		if (temp != '*' || '+' || ' ' || '=' || '0' || '1' || '2' || '3' || '4' || '5' ||
					'6' || '7' || '8' || '9' || 'a' || 'b' || 'c' || 'd' || 'e' || 'f' ||
					'g' || 'h' || 'i' || 'j' || 'k' || 'l' || 'm' || 'n' || 'o' || 'p' ||
					'q' || 'r' || 's' || 't' || 'u' || 'v' || 'w' || 'x' || 'y' || 'z') {
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