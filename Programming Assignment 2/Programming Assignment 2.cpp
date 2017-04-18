// Programming Assignment 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
	ifstream file;
	string fileName;
	string line;
	bool isValid;
	string strLabel = "strings";
	string algebraLabel = "algebra";
	string setsLabel = "sets";
	string boleanLabel = "boolean";

	cout << " Enter a filename for expressions to be evaluated: " << endl;
	getline(cin, fileName);
	file.open(fileName.c_str());
	
	while (getline(file, line)) {
		if (line.find("strings")) {
			
		}
		if (line.find("algebra")) {

		}
		if (line.find("sets")) {

		}
		if (line.find("boolean")) {

		}
	}

    return 0;
}

