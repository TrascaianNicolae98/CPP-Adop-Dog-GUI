#include "Repository.h"

Repository::Repository()
{
	this->curentPos = 0;
	
}

int Repository::Return_poz(Dog & Doggo)
{
	int i;
	for (i = 0; i < this->Dogs.size(); i++)
		if (this->Dogs[i] == Doggo)
			return i;
	return -1;
}

void Repository::set_dogs(vector<Dog> D)
{
	this->Dogs = D;
}

int Repository::add_dog(Dog & Doggo)
{
	MyException ex("Couldn't add dog", 19, "Repository.h");
	if (this->Return_poz(Doggo) != -1)
		throw ex;
	this->Dogs.push_back(Doggo);
	return 1;
	
}

int Repository::delete_dog(Dog & Doggo)
{
	MyException ex("Couldn't delete dog", 29, "Repository.h");
	if (this->Return_poz(Doggo) == -1)
		throw ex;
	this->Dogs.erase(this->Dogs.begin()+this->Return_poz(Doggo));
	return 1;
	
}

int Repository::update_dog(Dog & Doggo, Dog &DoggoUpdate)
{
	if (this->Return_poz(Doggo) != -1) {
		this->Dogs[this->Return_poz(Doggo)].update(DoggoUpdate);
		return 1;
	}
	else
	{
		MyException ex("Couldn't update dog", 39, "Repository.h");
		throw ex;
	}
}

vector<Dog> Repository::get_all()
{
	return this->Dogs;
}

vector<Dog> Repository::get_by_breed_age(string breed, int age)
{
	vector<Dog> auxlist;
	int i;
	for(i=0;i<this->Dogs.size();i++)
		if ((this->Dogs[i].getBreed() == breed && this->Dogs[i].getAge() < age) || (this->Dogs[i].getBreed() == "" && this->Dogs[i].getAge() < age)) {
			auxlist.push_back(this->Dogs[i]);
		}
	return auxlist;
}





void Repository::next_dog()
{
	if (this->Dogs.empty()!=true)
		this->curentPos++;
}

Dog Repository::getCurentDog()
{
	if (this->curentPos == this->Dogs.size())
		this->curentPos = 0;
	return this->Dogs[this->curentPos];
}

int Repository::getCurentPos()
{
	return this->curentPos;
}

void Repository::setCurentDog(Dog doggo)
{
	for (int i = 0; i < this->Dogs.size(); i++)
		if (this->Dogs[i] == doggo)
			this->curentPos = i;
}





