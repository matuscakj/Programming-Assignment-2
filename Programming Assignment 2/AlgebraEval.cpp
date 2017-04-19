#include "stdafx.h"
#include "AlgebraEval.h"
#include <iostream>
#include <string>
using namespace std;

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
	rewind;

	for (int i = 0; i < inLength; i++) {
		char temp;
		temp = input.at(i);
		if (temp != '*' || '+' || '-' || '^' || ' ' || '=' || '0' || '1' ||
					'2' || '3' || '4' || '5' || '6' || '7' || '8' || '9') {
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