#include "filterinputdialog.h"
#include "ui_filterinputdialog.h"

#include <QPushButton>
#include <QDebug>

void FilterInputDialog::on_make_change()
{
    settings.make = ui->lineEdit_Make->text();
    qDebug() << settings.make;
}

void FilterInputDialog::on_model_change()
{
    settings.model = ui->lineEdit_Model->text();
    qDebug() << settings.model;
}

void FilterInputDialog::on_max_power_change()
{
    // jos default "max power", aseta nolla niin ei filtteröidy mitää, muille sama
    if(ui->comboBox_MaxPower->currentIndex() == 0)
        settings.max_power = 0;

    else
        settings.max_power = ui->comboBox_MaxPower->currentText().toInt();

    qDebug() << settings.max_power;
}

void FilterInputDialog::on_min_power_change()
{
    if (ui->comboBox_MinPower->currentIndex() == 0)
        settings.min_power = 0;

    else
        settings.min_power = ui->comboBox_MinPower->currentText().toInt();

        qDebug() << settings.min_power;
}

void FilterInputDialog::on_max_price_change()
{
    if (ui->comboBox_MaxPrice->currentIndex() == 0)
        settings.max_price = 0;

    else
    {
        // parsi tuhaterottimet pois
        QString string = ui->comboBox_MaxPrice->currentText().remove(",");
        settings.max_price = string.toInt();
    }

    qDebug() << settings.max_price;
}

void FilterInputDialog::on_min_price_change()
{
    if (ui->comboBox_MinPrice->currentIndex() == 0)
        settings.min_price = 0;

    else
    {
        // parsi tuhaterottimet pois
        QString string = ui->comboBox_MinPrice->currentText().remove(",");
        settings.min_price = string.toInt();
    }

    qDebug() << settings.min_price;
}

void FilterInputDialog::on_max_year_change()
{
    if (ui->comboBox_MaxYear->currentIndex() == 0)
        settings.max_year = 0;

    else
        settings.max_year = ui->comboBox_MaxYear->currentText().toInt();

    qDebug() << settings.max_year;
}

void FilterInputDialog::on_min_year_change()
{
    if (ui->comboBox_MinYear->currentIndex() == 0)
        settings.min_year = 0;

    else
        settings.min_year = ui->comboBox_MinYear->currentText().toInt();

    qDebug() << settings.min_year;
}

FilterInputDialog::FilterInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterInputDialog)
{
    ui->setupUi(this);
    this->initialize_ui();



    //ui->comboBox_MaxPower->setCompleter(QCompleter::T)
}

FilterInputDialog::~FilterInputDialog()
{
    delete ui;
}

void FilterInputDialog::initialize_ui()
{
    //connect ui to code
    connect(ui->lineEdit_Make,
            &QLineEdit::textChanged,
            this,
            &FilterInputDialog::on_make_change);

    connect(ui->lineEdit_Model,
            &QLineEdit::textChanged,
            this,
            &FilterInputDialog::on_model_change);

    connect(ui->comboBox_MaxPower,
            &QComboBox::currentTextChanged,
            this,
            &FilterInputDialog::on_max_power_change);

    connect(ui->comboBox_MinPower,
            &QComboBox::currentTextChanged,
            this,
            &FilterInputDialog::on_min_power_change);

    connect(ui->comboBox_MaxPrice,
            &QComboBox::currentTextChanged,
            this,
            &FilterInputDialog::on_max_price_change);

    connect(ui->comboBox_MinPrice,
            &QComboBox::currentTextChanged,
            this,
            &FilterInputDialog::on_min_price_change);
    connect(ui->comboBox_MaxYear,
            &QComboBox::currentTextChanged,
            this,
            &FilterInputDialog::on_max_year_change);
    connect(ui->comboBox_MinYear,
            &QComboBox::currentTextChanged,
            this,
            &FilterInputDialog::on_min_year_change);

    // add dropdown items for year comboboxes
    QStringList list = generateDropDownForLoop(1900,1,2022, true);
    list.insert(0,"Minimum year");
    ui->comboBox_MinYear->addItems(list);
    list.pop_front();
    list.insert(0,"Maximum year");
    ui->comboBox_MaxYear->addItems(list);

    // add dropdrown items for power comboboxes
    list = generateDropDownForLoop(50,50,1000, false);
    list.insert(0,"Maximum power");
    ui->comboBox_MaxPower->addItems(list);
    list.pop_front();
    list.insert(0,"Minimum power");
    ui->comboBox_MinPower->addItems(list);

    // add dropdown items for price combos
    list = generateDropDownPriceItems();
    list.insert(0,"Minimum price");
    ui->comboBox_MinPrice->addItems(list);

    list = generateDropDownPriceItems();
    list.insert(0,"Maximum price");
    ui->comboBox_MaxPrice->addItems(list);

    QPushButton* test = ui->buttonBox->button(QDialogButtonBox::Ok);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}


