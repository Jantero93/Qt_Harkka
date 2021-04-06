#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include "readjson.h"

#include <iostream>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_car_model(new CarModel)
{
    ui->setupUi(this);
    QVector<Car> cars = get_car_vector_from_json_file();
    ui->tableView->setModel(m_car_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    foreach (const Car car, cars){
        m_car_model->add_car(car);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

