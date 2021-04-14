#include "car.h"
#include "mainwindow.h"
#include "readjson.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QVector>
#include <QDebug>
#include <iostream>

void MainWindow::on_click_filter_settings_button()
{
    if(m_filter_input->exec() == QDialog::Accepted)
    {
        // set values from inputdialog to proxy model
        this->setSettingsFromDialogToProxyModel();

        // set automatically filtered model and filter checkbox enablet
        ui->tableView->setModel(m_proxy_model);
        ui->checkBox_EnableFilter->setChecked(true);
    }

    // set off selection after model change
    ui->tableView->selectionModel()->clearSelection();
    ui->pushButton_Cost->setEnabled(false);

}

void MainWindow::on_checkbox_state_change()
{
        // set car model if filter goes off vice versa
    if (ui->checkBox_EnableFilter->isChecked())
        ui->tableView->setModel(m_proxy_model);

    else
        ui->tableView->setModel(m_car_model);

    // unselect tableview after model change
    ui->tableView->selectionModel()->clearSelection();
    ui->pushButton_Cost->setEnabled(false);

}


void MainWindow::on_click_calculate_costs_button()
{
       m_costs_calc->exec();
}

void MainWindow::on_pressed_cell_table_view_row()
{

    // check is row selected, if it is then enable costs button
    QItemSelectionModel* selection = ui->tableView->selectionModel();

    if(selection->hasSelection())
        ui->pushButton_Cost->setEnabled(true);
    else
        ui->pushButton_Cost->setEnabled(false);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_car_model(new CarModel)
    , m_proxy_model(new CustomProxyModel)
    , m_costs_calc(new CostsCalculator)
    , m_filter_input(new FilterInputDialog)
{
    ui->setupUi(this);

    connect(ui->checkBox_EnableFilter,
            &QCheckBox::stateChanged,
            this,
            &MainWindow::on_checkbox_state_change);

    connect(ui->pushButton_Filter,
            &QPushButton::pressed,
            this,
            &MainWindow::on_click_filter_settings_button);

    connect(ui->pushButton_Cost,
            &QPushButton::pressed,
            this,
            &MainWindow::on_click_calculate_costs_button);

    connect(ui->tableView,
            &QTableView::pressed,
            this,
            &MainWindow::on_pressed_cell_table_view_row);

    // default off when rows no selected
    ui->pushButton_Cost->setEnabled(false);

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

    // proxy modelille auto data
    m_proxy_model->setSourceModel(m_car_model);

    m_proxy_model->enableFiltering(true);
    // TEST
  //  ui->tableView->setModel(m_proxy_model);
    //m_proxy_model->setMaxHP(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// apu funktio mainwindowiin
void MainWindow::setSettingsFromDialogToProxyModel()
{
    // get settings struct from input dialog and set them on proxy model
    FilterOptions filter_options = m_filter_input->getOptions();

    m_proxy_model->setMake(filter_options.make);

    m_proxy_model->setModel(filter_options.model);

    m_proxy_model->setMinYear(filter_options.min_year);
    m_proxy_model->setMaxYear(filter_options.max_year);

    m_proxy_model->setMinHP(filter_options.min_power);
    m_proxy_model->setMaxHP(filter_options.max_power);

    m_proxy_model->setMinPrice(filter_options.min_price);
    m_proxy_model->setMaxPrice(filter_options.max_price);
}

