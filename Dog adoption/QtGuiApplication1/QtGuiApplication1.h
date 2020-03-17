#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include "MyUi.h"
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT


public:
	QtGuiApplication1( QWidget *parent = Q_NULLPTR);
private slots:
	void add();
	void delete_dog();
	void listDogs();
	void init_update_dog();
	void update_doggo();
	void update_file();
	void see_curent_dog();
	void next_dog();
	void adopt_dog();
	void see_adoption_list_HTML();
	void see_adoption_list_Csv();
	void filter_by_breed_age();
	


private:
	vector<string> string_split(string str);
	void read_from_text_file();
	Ui::QtGuiApplication1Class ui;
	Controller ctrl;
	QPushButton *update;
	QWidget *wnd;
	QLineEdit *ln1;
	QLineEdit *ln2;
	QLineEdit *ln3;
	QLineEdit *ln4;

	
};
