#include "costscalculator.h"
#include "ui_costscalculator.h"
#include <QIntValidator>

void CostsCalculator::on_click_exit_button()
{
    ui->doubleSpin_FueConsuption->setValue(10);
    ui->doubleSpin_FuelPriceLiter->setValue(1.6);
    ui->lineEdit_Inspection->setText("");
    ui->lineEdit_Insurance->setText("");
    ui->lineEdit_Maintance->setText("");
    ui->lineEdit_driven->setText("");

    ui->label_CostKilometer->setText("");
    ui->label_CostConsuption->setText("");
    ui->label_CostTotal->setText("");
    this->close();
}

void CostsCalculator::on_click_calc_button()
{
    UserInput input = getInputFromUI();

    double driven_costs = (input.driven_kilometers / 100) * input.fuel_consuption * input.fuel_price;
    ui->label_CostKilometer->setText(QString::number(driven_costs));

    double consuption_per_100 = input.fuel_consuption * input.fuel_price;
    ui->label_CostConsuption->setText(QString::number(consuption_per_100) + " /100km");

    double total_costs = driven_costs + input.inspection + input.insurance + input.maintance;
    QString totalText("Total costs: ");
    totalText.append( QString::number(total_costs) );
    ui->label_CostTotal->setText(totalText);

}

CostsCalculator::CostsCalculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CostsCalculator)
{
    ui->setupUi(this);

    // input 7 digits, no leading zeros
    QRegExpValidator* validator = new QRegExpValidator(QRegExp("[1-9]\\d{0,6}"));


    // set input validators for lineediut
    ui->lineEdit_driven->setValidator(validator);
    ui->lineEdit_Inspection->setValidator(validator);
    ui->lineEdit_Insurance->setValidator(validator);
    ui->lineEdit_Maintance->setValidator(validator);



    // connect buttons
    connect(ui->pushButton_Exit,
            &QPushButton::pressed,
            this,
            &CostsCalculator::on_click_exit_button);

    connect(ui->pushButton_Calculate,
            &QPushButton::pressed,
            this,
            &CostsCalculator::on_click_calc_button);
}

CostsCalculator::~CostsCalculator()
{
    delete ui;
}

void CostsCalculator::setCar(Car car)
{
    m_car = car;
    this->setCarLabels();
}

CostsCalculator::UserInput CostsCalculator::getInputFromUI()
{
    UserInput input;
    input.driven_kilometers = ui->lineEdit_driven->text().toInt();
    input.fuel_consuption = ui->doubleSpin_FueConsuption->value();
    input.fuel_price = ui->doubleSpin_FuelPriceLiter->value();
    input.inspection = ui->lineEdit_Inspection->text().toInt();
    input.insurance = ui->lineEdit_Insurance->text().toInt();
    input.maintance = ui->lineEdit_Maintance->text().toInt();
    return input;
}

void CostsCalculator::setCarLabels()
{
    ui->label_CarMake->setText("Make: " + m_car.m_make);
    ui->label_CarModel->setText("Model: " + m_car.m_model);
    ui->label_CarHorsepower->setText( "Power: " + QString::number(m_car.m_horsepower) );
    ui->label_CarYear->setText( "Year: " + QString::number(m_car.m_year) );
}
