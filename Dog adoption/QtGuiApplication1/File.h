#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "Dog.h"
#include "MyUi.h"
#include <fstream>
using namespace std;
class File {
public:
	File() {

	}

	virtual void writeToFile(vector<Dog> v) = 0;


};

class Csv :public File {
public:
	Csv() :File{} {
		

	}

	void writeToFile(vector<Dog> v)override {
		ofstream f("Dogs.csv", ios_base::out);
		f << "Breed" << "," << "Name" << "," << "Age" <<","<<"Photo"<< endl;
		for (auto elem : v)
			f << elem.getBreed() << "," << elem.getName()<<"," <<elem.getAge()<< "," << elem.getPhoto()<<endl;
	
	}

};

class Html :public File {
public:
	Html() :File{} {

	}

	void writeToFile(vector<Dog> v)override {
		ofstream f("Dogs.html", ios_base::out);
		string start = "<!DOCTYPE html><html><head><style>table {font-family: arial, sans-serif;border-collapse: collapse;width: 100%;}td, th {border: 1px solid #dddddd;text-align: left;padding: 8px;}tr:nth-child(even) {background-color: #dddddd;}</style></head><body><h2>Pets available</h2><table><tr><th>Breed</th><th>Name</th><th>Age</th><th>Photo</th></tr>";
		string end = "</table></body></html>";
		f << start;
		for (auto elem : v) {
			f << "<tr>";
			f << "<td>" << elem.getBreed() << "</td>";
			f << "<td>" << elem.getName() << "</td>";
			f << "<td>" << elem.getAge() << "</td>";
			f << "<td><a href=\"" << elem.getPhoto() << "\"/>Link</td>";
			f << "</tr>";
		}
		f << end;
		f.close();
	
	
	}
};