#include "Dog.h"
#include<string>
#include <iostream>
using namespace std;
Dog::Dog() {
}

void Dog::createDog(string breed, string name, int age, string photo)
{
	if (age > 0 && age < 30) {
		this->breed = breed;
		this->name = name;
		this->age = age;
		this->photo = photo;
	}
	else
		cout << "Instance wasn't created" << endl;
}

string Dog::getBreed() const
{
	return this->breed;
}

string Dog::getName() const 
{
	return this->name;
}

int Dog::getAge() const
{
	return this->age;
}

string Dog::getPhoto() const
{
	return this->photo;
}

void Dog::setBreed(string breed)
{
	this->breed = breed;
}

void Dog::setName(string name)
{
	this->name = name;
}

void Dog::setAge(int age)
{
	this->age = age;
}

void Dog::setPhoto(string photo)
{
	this->photo = photo;
}

void Dog::update(Dog &Doggo)
{
	this->breed = Doggo.breed;
	this->name = Doggo.name;
	this->age = Doggo.age;
	this->photo = Doggo.photo;
}

string Dog::toString()
{
	string str = "";
	str += "Breed:";
	str += this->breed;
	str += ",Name:";
	str += this->name;
	str += ",of age:";
	str += to_string(this->age);
	str += ",Photo:";
	str += this->photo;

	return str;

}

Dog & Dog::operator=(const Dog & Doggo)
{
	this->breed = Doggo.breed;
	this->name = Doggo.name;
	this->age = Doggo.age;
	this->photo = Doggo.photo;
	return *this;
}

int  Dog::operator==( const Dog & Doggo)
{
	if (this->getBreed() == Doggo.getBreed() && this->getName() == Doggo.getName())
		return 1;
	return 0;
}

