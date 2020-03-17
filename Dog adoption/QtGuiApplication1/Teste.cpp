#include "Teste.h"
#include "Dog.h"`
#include <assert.h>
#include <iostream>
using namespace std;
void populantion(Controller & ctrl)
{
	Dog Doggo1;
	Doggo1.createDog("breed1", "name1", 5, "link1");
	ctrl.add_dog_admin(Doggo1);

	Dog Doggo2;
	Doggo2.createDog("breed2", "name2", 6, "link2");
	ctrl.add_dog_admin(Doggo2);

	Dog Doggo3;
	Doggo3.createDog("breed3", "name3", 5, "link3");
	ctrl.add_dog_admin(Doggo3);

	Dog Doggo5;
	Doggo5.createDog("breed5", "name5", 10, "link5");
	ctrl.add_dog_admin(Doggo5);

	Dog Doggo4;
	Doggo4.createDog("breed4", "name4", 12, "link4");
	ctrl.add_dog_admin(Doggo4);

	Dog Doggo6;
	Doggo6.createDog("breed6", "name6", 2, "link6");
	ctrl.add_dog_admin(Doggo6);

	Dog Doggo7;
	Doggo7.createDog("breed7", "name7", 3, "link7");
	ctrl.add_dog_admin(Doggo7);

}

void runTest(Controller & ctrl)
{
	cout << "Test function is running" << endl;
	Dog myDog;
	myDog = ctrl.get_all_admin()[0];
	assert(myDog.getBreed() == "breed1");
	assert(myDog.getName() == "name1");
	assert(myDog.getAge() == 5);
	assert(myDog.getPhoto() == "link1");

	myDog = ctrl.get_curent_dog_user();
	assert(myDog == ctrl.get_all_admin()[0]);
	ctrl.next_dog_user();
	myDog= ctrl.get_curent_dog_user();
	assert(myDog == ctrl.get_all_admin()[1]);

	ctrl.adopt_dog_user();
	assert(myDog == ctrl.get_adoptionlist_user()[0]);

	vector<Dog> auxlist;
	auxlist = ctrl.get_by_breed_age_user("breed4", 20);
	assert(auxlist[0] == ctrl.get_all_admin()[3]);

	myDog = ctrl.get_all_admin()[5];
	ctrl.delete_dog_admin(ctrl.get_all_admin()[4]);
	assert(myDog == ctrl.get_all_admin()[4]);
	
	cout << "Finish testing.\n\n\n" ;
}
