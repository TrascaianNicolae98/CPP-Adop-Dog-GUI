#include "Controller.h"





Controller::Controller()
{
	
}

int Controller::add_dog_admin(Dog & Doggo)
{
	try {
		this->repo.add_dog(Doggo);
	}
	catch (MyException &ex) {
		throw ex;
	}
	return 1;
}

void Controller::set_dogs_ctrl(vector<Dog> D)
{
	this->repo.set_dogs(D);
}

int Controller::delete_dog_admin(Dog & Doggo)
{
	try {
		this->repo.delete_dog(Doggo);
	}
	catch(MyException &ex){
		throw ex;
	}
	return 1;
}

int Controller::update_dog_admin(Dog & Doggo, Dog &DoggoUpdate)
{
	try {
		this->repo.update_dog(Doggo, DoggoUpdate);
	}
	catch (MyException &ex) {
		throw ex;
	}
	return 1;
}

vector<Dog> Controller::get_all_admin()
{
	return this->repo.get_all();
}



vector<Dog> Controller::get_by_breed_age_user(string breed, int age)
{
	return this->repo.get_by_breed_age(breed, age);
}

void Controller::next_dog_user()
{
	this->repo.next_dog();
}

Dog Controller::get_curent_dog_user()
{
	return this->repo.getCurentDog();
}

void Controller::setCurentPos_ctrl(Dog doggo)
{
	this->repo.setCurentDog(doggo);
}

void Controller::adopt_dog_user()
{
	Dog Doggo;
	Doggo = this->get_curent_dog_user();
	this->list.adopt_dog(Doggo);
	this->repo.delete_dog(Doggo);
}

vector<Dog> Controller::get_adoptionlist_user()
{
	return this->list.get_adoptionlist();
}
