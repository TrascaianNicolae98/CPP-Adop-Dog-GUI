#pragma once
#include"Controller.h"
#include <vector>
#include<iostream>
using namespace std;
class MyUi {
private:
	Controller controler;

public:
	MyUi();


	vector<string> string_split(string str);

	void read_from_text_file();

	void update_file();

	Dog create_dog();

	void add_dog_admin_ui();

	void delete_dog_admin_ui();

	void update_dog_admin_ui();

	void get_all_admin_ui();

	vector<Dog> get_vector_ui();

	void get_by_breed_age_user_ui();

	void next_dog_user_ui();

	void get_curent_dog_user_ui();

	void adopt_dog_user_ui();

	void get_adoptionlist_user();

	void printMenu(int option);

	void readInteger(int &x);

	void sort_ui();

	void startUi();

	
};