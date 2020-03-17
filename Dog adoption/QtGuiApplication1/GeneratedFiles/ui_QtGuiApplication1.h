/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION1_H
#define UI_QTGUIAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication1Class
{
public:
    QWidget *centralWidget;
    QListWidget *Dogs;
    QLabel *label;
    QLabel *label_breed;
    QLabel *label_name;
    QLabel *label_age;
    QLabel *label_photo;
    QLineEdit *lineEdit_breed;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_age;
    QLineEdit *lineEdit_photo;
    QPushButton *add_b;
    QPushButton *delete_b;
    QPushButton *update_b;
    QPushButton *filter_b;
    QPushButton *adopt_b;
    QListWidget *list_adopt;
    QPushButton *pushButton_seeDog;
    QPushButton *pushButton_NextDog;
    QPushButton *updateFile;
    QPushButton *Html;
    QPushButton *Csv;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication1Class)
    {
        if (QtGuiApplication1Class->objectName().isEmpty())
            QtGuiApplication1Class->setObjectName(QString::fromUtf8("QtGuiApplication1Class"));
        QtGuiApplication1Class->resize(1221, 873);
        centralWidget = new QWidget(QtGuiApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Dogs = new QListWidget(centralWidget);
        Dogs->setObjectName(QString::fromUtf8("Dogs"));
        Dogs->setGeometry(QRect(40, 40, 421, 431));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 81, 21));
        label_breed = new QLabel(centralWidget);
        label_breed->setObjectName(QString::fromUtf8("label_breed"));
        label_breed->setGeometry(QRect(50, 490, 51, 21));
        label_name = new QLabel(centralWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(50, 530, 61, 21));
        label_age = new QLabel(centralWidget);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setGeometry(QRect(50, 570, 61, 21));
        label_photo = new QLabel(centralWidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(50, 610, 51, 21));
        lineEdit_breed = new QLineEdit(centralWidget);
        lineEdit_breed->setObjectName(QString::fromUtf8("lineEdit_breed"));
        lineEdit_breed->setGeometry(QRect(130, 490, 271, 21));
        lineEdit_name = new QLineEdit(centralWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(130, 530, 271, 21));
        lineEdit_age = new QLineEdit(centralWidget);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        lineEdit_age->setGeometry(QRect(130, 570, 271, 21));
        lineEdit_photo = new QLineEdit(centralWidget);
        lineEdit_photo->setObjectName(QString::fromUtf8("lineEdit_photo"));
        lineEdit_photo->setGeometry(QRect(130, 610, 271, 21));
        add_b = new QPushButton(centralWidget);
        add_b->setObjectName(QString::fromUtf8("add_b"));
        add_b->setGeometry(QRect(60, 680, 93, 28));
        delete_b = new QPushButton(centralWidget);
        delete_b->setObjectName(QString::fromUtf8("delete_b"));
        delete_b->setGeometry(QRect(200, 680, 93, 28));
        update_b = new QPushButton(centralWidget);
        update_b->setObjectName(QString::fromUtf8("update_b"));
        update_b->setGeometry(QRect(330, 680, 93, 28));
        filter_b = new QPushButton(centralWidget);
        filter_b->setObjectName(QString::fromUtf8("filter_b"));
        filter_b->setGeometry(QRect(200, 740, 93, 28));
        adopt_b = new QPushButton(centralWidget);
        adopt_b->setObjectName(QString::fromUtf8("adopt_b"));
        adopt_b->setGeometry(QRect(520, 200, 93, 31));
        adopt_b->setMinimumSize(QSize(93, 0));
        list_adopt = new QListWidget(centralWidget);
        list_adopt->setObjectName(QString::fromUtf8("list_adopt"));
        list_adopt->setGeometry(QRect(700, 40, 411, 571));
        list_adopt->setAlternatingRowColors(false);
        pushButton_seeDog = new QPushButton(centralWidget);
        pushButton_seeDog->setObjectName(QString::fromUtf8("pushButton_seeDog"));
        pushButton_seeDog->setGeometry(QRect(520, 260, 93, 28));
        pushButton_NextDog = new QPushButton(centralWidget);
        pushButton_NextDog->setObjectName(QString::fromUtf8("pushButton_NextDog"));
        pushButton_NextDog->setGeometry(QRect(520, 300, 93, 28));
        updateFile = new QPushButton(centralWidget);
        updateFile->setObjectName(QString::fromUtf8("updateFile"));
        updateFile->setGeometry(QRect(60, 740, 93, 28));
        Html = new QPushButton(centralWidget);
        Html->setObjectName(QString::fromUtf8("Html"));
        Html->setGeometry(QRect(710, 660, 141, 31));
        Csv = new QPushButton(centralWidget);
        Csv->setObjectName(QString::fromUtf8("Csv"));
        Csv->setGeometry(QRect(930, 660, 161, 31));
        QtGuiApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1221, 26));
        QtGuiApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiApplication1Class->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_breed->setBuddy(lineEdit_breed);
        label_name->setBuddy(lineEdit_name);
        label_age->setBuddy(lineEdit_age);
        label_photo->setBuddy(lineEdit_photo);
#endif // QT_NO_SHORTCUT

        retranslateUi(QtGuiApplication1Class);

        QMetaObject::connectSlotsByName(QtGuiApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication1Class)
    {
        QtGuiApplication1Class->setWindowTitle(QApplication::translate("QtGuiApplication1Class", "QtGuiApplication1", nullptr));
        label->setText(QApplication::translate("QtGuiApplication1Class", "<html><head/><body><p><span style=\" font-size:10pt;\">All Dogs</span></p></body></html>", nullptr));
        label_breed->setText(QApplication::translate("QtGuiApplication1Class", "<html><head/><body><p><span style=\" font-size:10pt;\">Breed</span></p></body></html>", nullptr));
        label_name->setText(QApplication::translate("QtGuiApplication1Class", "<html><head/><body><p><span style=\" font-size:10pt;\">Name</span></p></body></html>", nullptr));
        label_age->setText(QApplication::translate("QtGuiApplication1Class", "<html><head/><body><p><span style=\" font-size:10pt;\">Age</span></p></body></html>", nullptr));
        label_photo->setText(QApplication::translate("QtGuiApplication1Class", "<html><head/><body><p><span style=\" font-size:10pt;\">Photo</span></p></body></html>", nullptr));
        lineEdit_breed->setText(QString());
        add_b->setText(QApplication::translate("QtGuiApplication1Class", "Add", nullptr));
        delete_b->setText(QApplication::translate("QtGuiApplication1Class", "Delete", nullptr));
        update_b->setText(QApplication::translate("QtGuiApplication1Class", "Update", nullptr));
        filter_b->setText(QApplication::translate("QtGuiApplication1Class", "Filter", nullptr));
#ifndef QT_NO_TOOLTIP
        adopt_b->setToolTip(QApplication::translate("QtGuiApplication1Class", "<html><head/><body><p><span style=\" font-size:11pt;\">&gt;</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        adopt_b->setText(QApplication::translate("QtGuiApplication1Class", ">", nullptr));
        pushButton_seeDog->setText(QApplication::translate("QtGuiApplication1Class", "SeeDog", nullptr));
        pushButton_NextDog->setText(QApplication::translate("QtGuiApplication1Class", "NextDog", nullptr));
        updateFile->setText(QApplication::translate("QtGuiApplication1Class", "UpdateFile", nullptr));
        Html->setText(QApplication::translate("QtGuiApplication1Class", "SeeAdoptionList-HTML", nullptr));
        Csv->setText(QApplication::translate("QtGuiApplication1Class", "SeeAdoptionList-CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication1Class: public Ui_QtGuiApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION1_H
