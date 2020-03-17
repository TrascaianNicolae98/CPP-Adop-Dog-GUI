#pragma once
#include <vector>
#include "Dog.h"
class AdoptionList {
private:
	vector<Dog> Dogs;

public:

	AdoptionList();

	void adopt_dog(Dog &Doggo);

	vector<Dog> get_adoptionlist();
};