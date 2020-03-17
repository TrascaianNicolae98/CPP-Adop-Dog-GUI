#pragma once
#include <vector>
#include "Dog.h"
#include "Comparator.h"
#include "Exception.h"
class Repository {
private:
	vector <Dog> Dogs;
	int curentPos;

public:
	Repository();

	int Return_poz(Dog &Doggo);

	void set_dogs(vector <Dog> D);

	int add_dog(Dog &Doggo);

	int delete_dog(Dog &Doggo);

	int update_dog(Dog &Doggo, Dog &DoggoUpdate);

	vector <Dog> get_all();

	vector <Dog> get_by_breed_age(string breed, int age);

	void next_dog();

	Dog getCurentDog();

	int getCurentPos();

	void setCurentDog(Dog doggo);

	template <typename T>
	void sort_generic(vector<T> &vec, Comparator<T> *c) {
		T aux;
		for (int i = 0; i < vec.size() - 1; i++)
			for (int j = i + 1; j < vec.size(); j++)
				if (c->compare_c(vec[i], vec[j]) == false) {
					aux = vec[i];
					vec[i] = vec[j];
					vec[j] = aux;
				}
		

	}

	template <typename T>
	void sort(Comparator<T> *c) {
		this->sort_generic(this->Dogs, c);
		
	}


	

};


