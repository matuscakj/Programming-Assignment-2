#include "stdafx.h"
#include "BooleanEval.h"
#include <iostream>
#include <string>
using namespace std;

void BooleanEval(string input) {
	int inLength = 0;
	int leftPar = 0;
	int rightPar = 0;
	string leftSide;
	string rightSide;
	bool valid = true;
	bool equal = false;

	inLength = input.length();

	for (int i = 0; i <= inLength; i++) {
		char temp;
		temp = input.at(i);
		if (temp != '*' || '+' || ' ' || '=' || '0' || '1' || '(' || ')') {
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