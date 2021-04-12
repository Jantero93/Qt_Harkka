#include "filterinputdialog.h"
#include "ui_filterinputdialog.h"
#include <QPushButton>
FilterInputDialog::FilterInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterInputDialog)
{
    ui->setupUi(this);


    QStringList list=(QStringList()<<"stuff"<<"klol"<<"testings");
    ui->comboBox_MinYear->addItems(list);
    // set range for inputs
    QIntValidator* validatorYear = new QIntValidator(1900,2022,this);
    QIntValidator* validatorPower = new QIntValidator(0,10000, this);

    ui->comboBox_MinYear->setValidator(validatorYear);
    ui->comboBox_MaxYear->setValidator(validatorYear);
    ui->comboBox_MaxPower->setValidator(validatorPower);
    ui->comboBox_MinPower->setValidator(validatorPower);
    ui->spinBox_MaxPrice->setRange(0,1000*1000*1000);
    ui->spinBox_MinPrice->setRange(0,1000*1000*1000);
    QPushButton* test = ui->buttonBox->button(QDialogButtonBox::Ok);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);


}

FilterInputDialog::~FilterInputDialog()
{
    delete ui;
}
