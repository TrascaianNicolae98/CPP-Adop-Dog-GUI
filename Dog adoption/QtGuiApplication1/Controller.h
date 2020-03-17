#pragma once
#include"Repository.h"
#include"AdoptionList.h"

class Controller {
private:
	Repository repo;
	AdoptionList list;
	

public:
	
	Controller();

	int add_dog_admin(Dog &Doggo);

	void set_dogs_ctrl(vector <Dog> D);

	int delete_dog_admin(Dog &Doggo);

	int update_dog_admin(Dog &Doggo, Dog &DoggoUpdate);

	vector<Dog> get_all_admin();

	vector<Dog> get_by_breed_age_user(string breed, int age);

	void next_dog_user();

	Dog get_curent_dog_user();

	void setCurentPos_ctrl(Dog doggo);

	void adopt_dog_user();

	vector<Dog> get_adoptionlist_user();

	template <typename T>
	void sort_ctrl(Comparator<T> *c) {
		this->repo.sort(c);
	}
	
};



