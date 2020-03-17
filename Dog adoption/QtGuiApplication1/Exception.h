#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <string.h>
using namespace std;

class MyException :public exception {

private:
	string file;
	int line;
	char message[100];
public:
	MyException() {

	}

	MyException(const char *message1, int line1, string file1) :exception{message1} {

		strcpy(message, message1);
		this->line = line1;
		this->file = file1;
	}




	int getLine() {
		return line;

	}

	string getFile() {
		return file;
	}

	char *getMessage() {
		return this->message;
	}

	
};