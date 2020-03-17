#include "MyUi.h"
#include <string.h>
#include<string>
#include<iostream>
#include <fstream>
#include "File.h"
#include <Windows.h>
#include < Shellapi.h >

using namespace std;

MyUi::MyUi()
{
	
}


vector<string> MyUi::string_split(string str)
{
	vector<string> v;
	int i;
		i = 0;
		while (i <= 3) {
			if (i < 3) {

				v.push_back(str.substr(str.find(":")+1, str.find(",")- str.find(":")-1));
				i++;
				str.erase(0, str.find(",")+1);
			}
			else {
				v.push_back(str.substr(str.find(":")+1, str.length()-1));
				i++;

			}

		}
		return v;
}

void MyUi::read_from_text_file()
{
	fstream f("Fisier.txt");
	vector<string> v;
	string str;
	Dog doggo;
	while (!f.eof()) {
		getline(f, str);
		v = this->string_split(str);
		doggo.setBreed(v[0]);
		doggo.setName(v[1]);
		doggo.setAge(stoi(v[2]));
		doggo.setPhoto(v[3]);
		this->controler.add_dog_admin(doggo);
	}
	f.close();


}

void MyUi::update_file()
{
	ofstream f("Fisier.txt");
	for (int i = 0; i < this->controler.get_all_admin().size();i++) {
		if (i < this->controler.get_all_admin().size() - 1)
			f << this->controler.get_all_admin()[i].toString() << endl;
		else
			f << this->controler.get_all_admin()[i].toString();
	}
		
	f.close();


}


Dog MyUi::create_dog() {

	string breed, name, photo;
	int age;
	cin.ignore();
	cout << "Insert the breed: " ;
	getline(cin, breed);
	cout << endl;
	cout << "Insert the name: " ;
	getline(cin, name); cout << endl;
	cout << "Insert the age: ";
	cin >> age; cin.ignore(); cout << endl;
	cout << "Insert the link of the photo: ";
	getline(cin, photo);
	cout << endl;
	Dog Doggo;
	Doggo.createDog(breed, name, age, photo);
	return Doggo;

}

void MyUi::add_dog_admin_ui()
{
	Dog Doggo = create_dog();
	try {
		this->controler.add_dog_admin(Doggo);
	}
	catch (MyException &ex) {
		cout << ex.getFile() << " " << ex.getLine() << " " << ex.getMessage()<<endl;
	}

}

void MyUi::delete_dog_admin_ui()
{
	cout << "What dog do you wanna delete?:" << endl;
	Dog Doggo = create_dog();
	try {
		this->controler.delete_dog_admin(Doggo);
	}
	catch (MyException &ex) {
		cout << ex.getFile() << " " << ex.getLine() << " " << ex.getMessage() << endl;
	}

}

void MyUi::update_dog_admin_ui()
{
	string breed, name, photo;
	int age;
	cout << "What dog do you wanna update?: " << endl;
	Dog Doggo = create_dog();
	cout << "Insert the breed: ";
	getline(cin, breed);
	cout << endl;
	cout << "Insert the name: ";
	getline(cin, name); cout << endl;
	cout << "Insert the age: ";
	cin >> age; cin.ignore(); cout << endl;
	cout << "Insert the link of the photo: ";
	getline(cin, photo);
	cout << endl;
	Dog DoggoUpdate;
	DoggoUpdate.createDog(breed, name, age, photo);
	try {
		this->controler.update_dog_admin(Doggo, DoggoUpdate);
	}
	catch (MyException &ex) {
		cout << ex.getFile() << " " << ex.getLine() << " " << ex.getMessage()<<endl;
	}
}

void MyUi::get_all_admin_ui()
{
	int i;
	for (i = 0; i < this->controler.get_all_admin().size(); i++) {
		string str;
		str = this->controler.get_all_admin()[i].toString();
		cout << str << endl;
	}
}

vector<Dog> MyUi::get_vector_ui()
{
	return this->controler.get_all_admin();
}

void MyUi::get_by_breed_age_user_ui()
{
	string breed;
	int age;
	cin.ignore();
	cout << "Insert the breed: ";
	getline(cin, breed);
	cout << endl;
	cout << "Insert the age: ";
	cin >> age;
	cout << endl;
	vector<Dog> dogs = controler.get_by_breed_age_user(breed,age);
	if (dogs.size() == 0)
		cout << "Doesn't exist dogs" << endl;
	else {

		for (auto elem : dogs) {
			cout << elem.toString() << endl;
			cout << "Do you wanna adopt him?" << endl;
			int option = -1;
			cout << "1-Yes" << endl;
			cout << "2-No" << endl;
			cout << "option="; cin >> option; cout << endl;
			if (option == 1) {
				this->controler.setCurentPos_ctrl(elem);
				this->controler.adopt_dog_user();
			}
			else {

			}

		}
	}


}

void MyUi::next_dog_user_ui()
{
	this->controler.next_dog_user();
}

void MyUi::get_curent_dog_user_ui()
{
	Dog Doggo = this->controler.get_curent_dog_user();
	string str;
	str = Doggo.toString();
	cout << str << endl;

}

void MyUi::adopt_dog_user_ui()
{
	this->controler.adopt_dog_user();
}

void MyUi::get_adoptionlist_user()
{
	cout << "How do you wanna show them?" << endl;
	cout << "1-Csv"<<endl;
	cout << "2-Html" << endl;
	int option = -1;
	cout << "option="; cin >> option; cout << endl;
	if (option == 1) {
		File *f1 = new Csv();
		f1->writeToFile(this->controler.get_adoptionlist_user());
		ShellExecute(NULL, TEXT("open"), TEXT("file:///C:/Users/trasc/source/repos/ConsoleApplication4/ConsoleApplication4/Dogs.csv"), NULL, NULL, SW_SHOWNORMAL);
	}
	else {
		File *f2 = new Html();
		f2->writeToFile(this->controler.get_adoptionlist_user());
		 
		ShellExecute(NULL, TEXT("open"), TEXT("file:///C:/Users/trasc/source/repos/ConsoleApplication4/ConsoleApplication4/Dogs.html"), NULL, NULL, SW_SHOWNORMAL);
		
	}

}



void MyUi::printMenu(int option)
{
	
	if (option == 1) {
		cout << "1-Add dog:" << endl;
		cout << "2-Delete dog:" << endl;
		cout << "3-Update dog:" << endl;
		cout << "4-Get all dogs" << endl;
		cout << "5-Sort" << endl;
		cout << "6-Update text file" << endl;
		cout << "7-Change to user" << endl;
		cout << "0-Exist"<<endl;
		
	}
	else if (option == 2) {
		cout << "1-Get dogs that have a given breed with age less then a given value" << endl;
		cout << "2- Next dog" << endl;
		cout << "3-Get curent dog" << endl;
		cout << "4-Adopt dog" << endl;
		cout << "5-See adoption list" << endl;
		cout << "6-Change to admin" << endl;
		cout << "0-Exist" << endl;
		
	}
}

void MyUi::readInteger(int &x)
{
	cout << "Choose an option: ";
	cin >> x;
	cout << "---------------------------------------------" << endl;
	cout << endl;
	while (x < 0 || x>8) {
		cout << "Choose an option: ";
		cin >> x;
		cout << "---------------------------------------------" << endl;
		cout << endl;
	}
	cout << endl;
}


void MyUi::sort_ui()
{
	cout << "What do you wanna sorted by?" << endl;
	int option = -1;
	cout << "1-By name;" << endl;
	cout << "2-By breed;" << endl;
	cout << "3-By age;" << endl;
	cout << "option="; cin >> option; cout << endl;
	if (option == 1) {
		Comparator<Dog> *c1 = new CompareByName;
		this->controler.sort_ctrl(c1);
		delete c1;
	}
	else if (option == 2) {
		Comparator<Dog> *c2 = new CompareByBreed;
		this->controler.sort_ctrl(c2);
		delete c2;
		
	}

	else {
		Comparator<Dog> *c3 = new CompareByAge;
		this->controler.sort_ctrl(c3);
		delete c3;
	}
}

void MyUi::startUi()
{
	
	int option=-1;
	
	while (option) {

		cout << "1-For admin choose 1" << endl;
		cout << "2-For user choose 2" << endl;
		cout << "Option=";
		cin >> option;
		while (option != 1 && option != 2) {
			cout << "You can only choose 1 or 2"<<endl;
			cout << "Option=";
			cin >> option;
			cout << endl;
		}
		cout << "---------------------------------------------";
		cout << endl;
		if (option == 1) {
			int option2 = -1;
			while (option2 != 0) {
				this->printMenu(option);
				this->readInteger(option2);

				if (option2 == 1)
				{
					this->add_dog_admin_ui();
					cout << "---------------------------------------------" << endl;
				}

				else if (option2 == 2)
				{
					this->delete_dog_admin_ui();
					cout << "---------------------------------------------" << endl;
				}

				else if (option2 == 3)
				{
					this->update_dog_admin_ui();
					cout << "---------------------------------------------" << endl;
				}

				else if (option2 == 4)
				{
					this->get_all_admin_ui();
					cout << "---------------------------------------------" << endl;
				}

				else if (option2 == 5) {
					this->sort_ui();
					cout << "---------------------------------------------" << endl;
				}

				else if (option2 == 6) {
					this->update_file();
					cout << "---------------------------------------------" << endl;
				}

				else if (option2 == 7) {
					option = 2;
					break;
				}

				else if (option2 == 0)
				{
					option = 0;
					break;
				}


			}

		}

		else if (option == 2) {
			int option2 = -1;
			while (option2 != 0) {
				this->printMenu(option);
				this->readInteger(option2);

				if (option2 == 1)
				{
					this->get_by_breed_age_user_ui();
					cout << "---------------------------------------------"<<endl;
				}
				else if (option2 == 2)
				{
					this->next_dog_user_ui();
					cout << "---------------------------------------------" << endl;
				}
				else if (option2 == 3)
				{
					this->get_curent_dog_user_ui();
					cout << "---------------------------------------------" << endl;
				}
				else if (option2 == 4)
				{
					this->adopt_dog_user_ui();
					cout << "---------------------------------------------" << endl;
				}
				else if (option2 == 5)
				{
					this->get_adoptionlist_user();
					cout << "---------------------------------------------" << endl;
				}

				else if (option2 == 6) {
					option = 1;
					break;
				}

				else if (option2 == 0) {
					option = 0;
					break;
					
				}
					
			}


		}
		if (option == 0)
			break;
	}

	

	



}






