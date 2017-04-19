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

string trim(const string& str) {
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

int main()
{
	ifstream file;
	string fileName;
	string line;
	string trimmedLine;
	stack<string> syntax;


	cout << " Enter a filename for expressions to be evaluated: ";
	getline(cin, fileName);
	file.open(fileName.c_str());

	while (getline(file, line)) {
		trimmedLine = trim(line);
		if (trimmedLine == "<strings>") {
			syntax.push("strings");
		}else if (trimmedLine == "<algebra>") {
			syntax.push("algebra");
		}else if (trimmedLine == "<sets>") {
			syntax.push("sets");
		}else if (trimmedLine == "<boolean>") {
			syntax.push("boolean");
		}else if (trimmedLine == "</>") {
			syntax.pop();
		}else if (trimmedLine.at(0) == '<') {
			cout << "The binding expression: '" << trimmedLine << "' is invalid." << endl;
		}else {
			if (syntax.top() == "strings") {
				StringsEval(trimmedLine);
			}else if (syntax.top() == "algebra") {
				AlgebraEval(trimmedLine);
			}else if (syntax.top() == "sets") {
				SetsEval(trimmedLine);
			}else if (syntax.top() == "boolean") {
				BooleanEval(trimmedLine);
			}
		}
	}
	return 0;
}

