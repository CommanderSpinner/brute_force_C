/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_name;
    QPushButton *btn_Force;
    QTextEdit *text_name;
    QLabel *label_password;
    QTextEdit *text_password;
    QTextEdit *text_url;
    QLabel *label_url;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(242, 284);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(10, 30, 54, 17));
        btn_Force = new QPushButton(centralwidget);
        btn_Force->setObjectName("btn_Force");
        btn_Force->setGeometry(QRect(130, 220, 80, 25));
        text_name = new QTextEdit(centralwidget);
        text_name->setObjectName("text_name");
        text_name->setGeometry(QRect(120, 20, 104, 31));
        label_password = new QLabel(centralwidget);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(10, 70, 161, 81));
        text_password = new QTextEdit(centralwidget);
        text_password->setObjectName("text_password");
        text_password->setGeometry(QRect(120, 90, 104, 31));
        text_url = new QTextEdit(centralwidget);
        text_url->setObjectName("text_url");
        text_url->setGeometry(QRect(120, 160, 104, 31));
        label_url = new QLabel(centralwidget);
        label_url->setObjectName("label_url");
        label_url->setGeometry(QRect(10, 140, 161, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 242, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        btn_Force->setText(QCoreApplication::translate("MainWindow", "Force", nullptr));
        label_password->setText(QCoreApplication::translate("MainWindow", "password field \n"
"name", nullptr));
        label_url->setText(QCoreApplication::translate("MainWindow", "url", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
