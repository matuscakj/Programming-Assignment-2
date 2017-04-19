// Programming Assignment 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "StringsEval.h"
#include "AlgebraEval.h"
#include "BooleanEval.h"
#include "SetsEval.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stack>
using namespace std;

void StringsEval(string);

int main()
{
	ifstream file;
	string fileName;
	string line;
	bool isValid;
	stack<string> syntax;


	cout << " Enter a filename for expressions to be evaluated: " << endl;
	getline(cin, fileName);
	file.open(fileName.c_str());

	while (getline(file, line)) {
		if (line.find("<strings>")) {
			syntax.push("strings");
		}else if (line.find("<algebra>")) {
			syntax.push("algebra");
		}else if (line.find("<sets>")) {
			syntax.push("sets");
		}else if (line.find("<boolean>")) {
			syntax.push("boolean");
		}else if (line.find("</>")) {
			syntax.pop();
		}else if (line.at(0) == '<') {
			cout << "The binding expression: '" << line << "' is invalid." << endl;
		}else {
			if (syntax.top() == "string") {
				StringsEval(line);
			}else if (syntax.top() == "algebra") {
				AlgebraEval(line);
			}else if (syntax.top() == "sets") {
				SetsEval(line);
			}else if (syntax.top() == "boolean") {
				BooleanEval(line);
			}
		}
		return 0;
	}
}

