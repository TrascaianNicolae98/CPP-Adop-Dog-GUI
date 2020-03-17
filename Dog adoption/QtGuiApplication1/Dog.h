#pragma once
#include<string>
using namespace std;

class Dog
{
private:
	string breed;
	string name;
	int age;
	string photo;

public:
	Dog();

	void createDog(string breed, string name, int age, string photo);

	string getBreed() const;

	string getName() const;

	int getAge() const;

	string getPhoto() const;

	void setBreed(string breed);

	void setName(string name);

	void setAge(int age);

	void setPhoto(string photo);

	void update(Dog &Doggo);

	string toString();

	Dog &operator=(const Dog &Doggo);

	int operator==(const Dog & Doggo);




};
