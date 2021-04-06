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
    // piilota nysä
    ui->tableView->verticalHeader()->hide();
    // sorttaus päälle
    ui->tableView->setSortingEnabled(true);
    // selectaa koko rivi
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // vain yksi rivi kerrallaan
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // https://stackoverflow.com/questions/5927499/how-to-get-selected-rows-in-qtableview

    foreach (const Car car, cars){
        m_car_model->add_car(car);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

