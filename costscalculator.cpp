#include "costscalculator.h"
#include "ui_costscalculator.h"
#include <QIntValidator>

void CostsCalculator::on_click_exit_button()
{
    this->close();
}

void CostsCalculator::on_click_calc_button()
{

}

CostsCalculator::CostsCalculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CostsCalculator)
{
    ui->setupUi(this);

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
