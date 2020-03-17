#include "QtGuiApplication1.h"
#include <fstream>
#include "File.h"
#include <Windows.h>
#include < Shellapi.h >

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);

	this->read_from_text_file();

	this->listDogs();

	connect(ui.add_b, SIGNAL(clicked()), this, SLOT(add()));

	connect(ui.delete_b, SIGNAL(clicked()), this, SLOT(delete_dog()));

	connect(ui.update_b, SIGNAL(clicked()), this, SLOT(update_dog()));

	connect(ui.updateFile, SIGNAL(clicked()), this, SLOT(update_file()));

	connect(ui.pushButton_seeDog, SIGNAL(clicked()), this, SLOT(see_curent_dog()));

	connect(ui.pushButton_NextDog, SIGNAL(clicked()), this, SLOT(next_dog()));

	connect(ui.adopt_b, SIGNAL(clicked()), this, SLOT(adopt_dog()));

	connect(ui.Html, SIGNAL(clicked()), this, SLOT(see_adoption_list_HTML()));

	connect(ui.Csv, SIGNAL(clicked()), this, SLOT(see_adoption_list_Csv()));

	connect(ui.filter_b, SIGNAL(clicked()), this, SLOT(filter_by_breed_age()));

	connect(ui.update_b, SIGNAL(clicked()), this, SLOT(init_update_dog()));

	

	

	
	
}

vector<string> QtGuiApplication1::string_split(string str)
{
	vector<string> v;
	int i;
	i = 0;
	while (i <= 3) {
		if (i < 3) {

			v.push_back(str.substr(str.find(":") + 1, str.find(",") - str.find(":") - 1));
			i++;
			str.erase(0, str.find(",") + 1);
		}
		else {
			v.push_back(str.substr(str.find(":") + 1, str.length() - 1));
			i++;

		}

	}
	return v;
	
}

void QtGuiApplication1::read_from_text_file()
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
		this->ctrl .add_dog_admin(doggo);
	}
	f.close();
}

void QtGuiApplication1::update_file()
{
	ofstream f("Fisier.txt");
	for (int i = 0; i < this->ctrl.get_all_admin().size(); i++) {
		if (i < this->ctrl.get_all_admin().size() - 1)
			f << this->ctrl.get_all_admin()[i].toString() << endl;
		else
			f << this->ctrl.get_all_admin()[i].toString();
	}

	f.close();
}

void QtGuiApplication1::see_curent_dog()
{
	this->ui.Dogs->clear();
	Dog doggo;
	doggo = this->ctrl.get_curent_dog_user();
	QString s;
	s = QString::fromStdString(doggo.toString());
	this->ui.Dogs->addItem(s);
}

void QtGuiApplication1::next_dog()
{
	this->ctrl.next_dog_user();
}


void QtGuiApplication1::adopt_dog()
{
	this->ctrl.adopt_dog_user();
	Dog doggo;
	doggo = this->ctrl.get_adoptionlist_user()[this->ctrl.get_adoptionlist_user().size() - 1];
	QString s;
	s = QString::fromStdString(doggo.toString());
	this->ui.list_adopt->addItem(s);


}

void QtGuiApplication1::see_adoption_list_HTML()
{
	File *f1 = new Html();
	f1->writeToFile(this->ctrl.get_adoptionlist_user());
	ShellExecute(NULL, TEXT("open"), TEXT("file:///C:/Users/trasc/source/repos/QtGuiApplication1/QtGuiApplication1/Dogs.html"), NULL, NULL, SW_SHOWNORMAL);
}

void QtGuiApplication1::see_adoption_list_Csv()
{
	File *f1 = new Csv();
	f1->writeToFile(this->ctrl.get_adoptionlist_user());
	ShellExecute(NULL, TEXT("open"), TEXT("file:///C:/Users/trasc/source/repos/QtGuiApplication1/QtGuiApplication1/Dogs.csv"), NULL, NULL, SW_SHOWNORMAL);

}

void QtGuiApplication1::filter_by_breed_age()
{
	string breed;
	string age;
	breed = ui.lineEdit_breed->text().toStdString();
	age = ui.lineEdit_age->text().toStdString();
	int age1 = stoi(age);
	this->ctrl.set_dogs_ctrl(this->ctrl.get_by_breed_age_user(breed, age1));
}



void QtGuiApplication1::add()
{
	QString breed, name, age, photo;
	breed = ui.lineEdit_breed->text();
	name = ui.lineEdit_name->text();
	age = ui.lineEdit_age->text();
	photo = ui.lineEdit_photo->text();
	string breed1, name1, age1, photo1;
	breed1 = breed.toStdString();
	name1 = name.toStdString();
	age1 = age.toStdString();
	int age2;
	age2 = stoi(age1);
	photo1 = photo.toStdString();
	Dog doggo;
	doggo.createDog(breed1, name1, age2, photo1);
	ctrl.add_dog_admin(doggo);
	ui.Dogs->clear();
	this->listDogs();
	


}

void QtGuiApplication1::delete_dog()
{
	string breed, name, age, photo;
	breed = ui.lineEdit_breed->text().toStdString();
	name = ui.lineEdit_name->text().toStdString();
	age = ui.lineEdit_age->text().toStdString();
	photo = ui.lineEdit_photo->text().toStdString();
	int age1 = stoi(age);
	Dog doggo;
	doggo.createDog(breed, name, age1, photo);
	this->ctrl.delete_dog_admin(doggo);
	ui.Dogs->clear();
	this->listDogs();


}

void QtGuiApplication1::listDogs()
{
	for (auto elem : this->ctrl.get_all_admin()) {
		QString qs = QString::fromStdString(elem.toString());
		ui.Dogs->addItem(qs);
	 
	}

}

void QtGuiApplication1::init_update_dog()
{
	wnd = new QWidget;
	QVBoxLayout *vl = new QVBoxLayout;
	wnd->setLayout(vl);

	QLabel *lb1 = new QLabel("&Breed");
	ln1 = new QLineEdit;
	lb1->setBuddy(ln1);
	vl->addWidget(lb1);
	vl->addWidget(ln1);

	QLabel *lb2 = new QLabel("&Name");
	ln2 = new QLineEdit;
	lb2->setBuddy(ln2);
	vl->addWidget(lb2);
	vl->addWidget(ln2);

	QLabel *lb3 = new QLabel("&Age");
	ln3 = new QLineEdit;
	lb3->setBuddy(ln3);
	vl->addWidget(lb3);
	vl->addWidget(ln3);

	QLabel *lb4 = new QLabel("&Photo");
	ln4 = new QLineEdit;
	lb4->setBuddy(ln4);
	vl->addWidget(lb4);
	vl->addWidget(ln4);


	

	
	update = new QPushButton("&Update");
	vl->addWidget(update);
	



	connect(update, SIGNAL(clicked()), this, SLOT(update_doggo()));
	wnd->show();

	






}

void QtGuiApplication1::update_doggo()
{
	Dog  doggo1, doggo2;

	string breed, name, age, photo;
	breed = ui.lineEdit_breed->text().toStdString();
	name = ui.lineEdit_name->text().toStdString();
	age = ui.lineEdit_age->text().toStdString();
	photo = ui.lineEdit_photo->text().toStdString();
	int age1 = stoi(age);
	
	doggo1.createDog(breed, name, age1, photo);


	string breed1, name1, age2, photo1;
	breed1 = ln1->text().toStdString();
	name1 = ln2->text().toStdString();
	age2 = ln3->text().toStdString();
	photo1 = ln4->text().toStdString();
	int age3 = stoi(age2);
	
	doggo2.createDog(breed1, name1, age3, photo1);
	
	this->ctrl.update_dog_admin(doggo1, doggo2);
	this->ui.Dogs->clear();
	this->listDogs();

}
