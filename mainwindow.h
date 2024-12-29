#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include "./ui_mainwindow.h"
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <memory>
#include "httpreq.h"
#include "sender.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_Force_clicked(); // Button handler
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
