#include "car.h"
#include "mainwindow.h"
#include "readjson.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_car_model(new CarModel)
    , m_proxy_model(new CustomProxyModel)
{
    ui->setupUi(this);
    // car list from json file
    QVector<Car> cars = get_cars_from_json_file();
    // set custom model
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

    // add car data to model
    foreach (const Car car, cars){
        m_car_model->add_car(car);
    }


    m_proxy_model->setSourceModel(m_car_model);
  // m_proxy_model->setModel("age");
//    m_proxy_model->setMaxPrice(0);
 //   m_proxy_model->setMinPrice(6*55000);
 //   m_proxy_model->setMinYear(2016);

  //  m_proxy_model->setFilterWildcard("audi");
  //  m_proxy_model->setFilterKeyColumn(0);
    ui->tableView->setModel(m_proxy_model);


}

MainWindow::~MainWindow()
{
    delete ui;
}

