#pragma once
#include<iostream>
#include "Dog.h"
#include<string>
#include<string.h>
using namespace std;
template <typename C>
class  Comparator{
public:
	Comparator() {

	}
	~Comparator() {

	}
	bool virtual compare_c(C &elem1, C &elem2) = 0;

};

class CompareByName: public Comparator<Dog>
{
public:
	CompareByName() {

	}
	~CompareByName() {

	}
	bool compare_c(Dog &Doggo1,Dog &Doggo2) override {
		if (Doggo1.getName().compare(Doggo2.getName()) < 0)
			return true;
		else
			return false;
	}


};

class CompareByAge :public Comparator<Dog> {
public:
	CompareByAge() {

	}
	~CompareByAge() {

	}

	bool compare_c(Dog &Doggo1, Dog &Doggo2) override {
		if (Doggo1.getAge() < Doggo2.getAge())
			return true;
		return false;
	}
};

class CompareByBreed :public Comparator<Dog> {
public:
	CompareByBreed() {

	}
	~CompareByBreed() {

	}

	bool compare_c(Dog &Doggo1, Dog &Dogggo2)override {
		if (Doggo1.getBreed().compare(Dogggo2.getBreed()) < 0)
			return true;
		else return false;

		
	}


};