#include "car.h"
#include "mainwindow.h"
#include "readjson.h"
#include "ui_mainwindow.h"


#include <QVector>
#include <QDebug>


void MainWindow::on_click_filter_settings_button()
{
    if(m_filter_input_dialog->exec() == QDialog::Accepted)
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
        // get selection from tableview (only one row can be selected)
        QItemSelectionModel* selection = ui->tableView->selectionModel();

        if (selection->hasSelection())
        {
            Car car;
            if(ui->checkBox_EnableFilter->isChecked())
            {
                QModelIndex index = m_proxy_model->mapToSource(selection->selectedIndexes().at(0));
                qDebug() << "valittu rivin indeksi proxymodel : " << selection->selectedIndexes().at(0).row();
                car = m_car_model->get_car(index.row());

            }
            else
            {
                QModelIndex index = selection->selectedIndexes().at(0);
                qDebug() << "rivi on car_modelissa  " << index.row();

                car = m_car_model->get_car(index.row());
                qDebug() << "auton malli " << car.m_model;

            }

            // set selected car on costs calc and execute
            m_costs_calc->setCar(car);
            m_costs_calc->exec();
        }

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
    , m_costs_calc(new CostsCalculator)
    , m_proxy_model(new CustomProxyModel)
    , m_filter_input_dialog(new FilterInputDialog)
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
    ui->checkBox_EnableFilter->setChecked(false);

    // car list from json file
    QVector<Car> cars = get_cars_from_json_file();

    // add car data to model from json
    foreach (const Car car, cars){
        m_car_model->add_car(car);
    }

    // set custom model
    ui->tableView->setModel(m_car_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSortingEnabled(true);

    // selectaa whole row one at time
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // data for proxy model (from car model)
    m_proxy_model->setSourceModel(m_car_model);
    m_proxy_model->enableFiltering(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// help function for mainwindow to fetch data
void MainWindow::setSettingsFromDialogToProxyModel()
{
    // get settings struct from input dialog and set them on proxy model
    FilterOptions filter_options = m_filter_input_dialog->getOptions();

    m_proxy_model->setMake(filter_options.make);

    m_proxy_model->setModel(filter_options.model);

    m_proxy_model->setMinYear(filter_options.min_year);
    m_proxy_model->setMaxYear(filter_options.max_year);

    m_proxy_model->setMinPower(filter_options.min_power);
    m_proxy_model->setMaxPower(filter_options.max_power);

    m_proxy_model->setMinPrice(filter_options.min_price);
    m_proxy_model->setMaxPrice(filter_options.max_price);
}

