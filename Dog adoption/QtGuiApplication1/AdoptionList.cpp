#include "AdoptionList.h"




AdoptionList::AdoptionList()
{
	
}

void AdoptionList::adopt_dog(Dog &Doggo)
{
	this->Dogs.push_back(Doggo);
}

vector<Dog> AdoptionList::get_adoptionlist()
{
	return this->Dogs;
}
