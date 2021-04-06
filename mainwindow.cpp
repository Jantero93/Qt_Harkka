#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include "readjson.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    get_car_vector_from_json_file();
}

MainWindow::~MainWindow()
{
    delete ui;
}

