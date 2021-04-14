#include "filterinputdialog.h"
#include "ui_filterinputdialog.h"

#include <QPushButton>
#include <QDebug>

void FilterInputDialog::on_click_dialog_buttons(QAbstractButton *clicked_button)
{
    if (clicked_button == ui->buttonBox->button(QDialogButtonBox::Reset))
    {
        m_settings.make.clear();
        ui->lineEdit_Make->setText("");

        m_settings.model.clear();
        ui->lineEdit_Model->setText("");

        m_settings.max_power = 0;
        ui->comboBox_MaxPower->setCurrentIndex(0);

        m_settings.min_power = 0;
        ui->comboBox_MinPower->setCurrentIndex(0);

        m_settings.max_price = 0;
        ui->comboBox_MaxPrice->setCurrentIndex(0);

        m_settings.min_price = 0;
        ui->comboBox_MinPrice->setCurrentIndex(0);

        m_settings.max_year = 0;
        ui->comboBox_MaxYear->setCurrentIndex(0);

        m_settings.min_year = 0;
        ui->comboBox_MinYear->setCurrentIndex(0);
    }
}

void FilterInputDialog::on_make_change()
{
    m_settings.make = ui->lineEdit_Make->text();
    qDebug() << m_settings.make;
    inputfieldsValid();
}

void FilterInputDialog::on_model_change()
{
    m_settings.model = ui->lineEdit_Model->text();
    qDebug() << m_settings.model;
    inputfieldsValid();
}

void FilterInputDialog::on_max_power_change()
{
    // jos default "max power", aseta nolla niin ei filtteröidy mitää, muille sama
    if(ui->comboBox_MaxPower->currentIndex() == 0)
        m_settings.max_power = 0;

    else
        m_settings.max_power = ui->comboBox_MaxPower->currentText().toInt();

    qDebug() << m_settings.max_power;
    inputfieldsValid();
}

void FilterInputDialog::on_min_power_change()
{
    if (ui->comboBox_MinPower->currentIndex() == 0)
        m_settings.min_power = 0;

    else
        m_settings.min_power = ui->comboBox_MinPower->currentText().toInt();

        qDebug() << m_settings.min_power;
        inputfieldsValid();
}

void FilterInputDialog::on_max_price_change()
{
    if (ui->comboBox_MaxPrice->currentIndex() == 0)
        m_settings.max_price = 0;

    else
        m_settings.max_price = ui->comboBox_MaxPrice->currentText().toInt();



    qDebug() << m_settings.max_price;
    inputfieldsValid();
}

void FilterInputDialog::on_min_price_change()
{
    if (ui->comboBox_MinPrice->currentIndex() == 0)
        m_settings.min_price = 0;

    else
        m_settings.min_price = ui->comboBox_MinPrice->currentText().toInt();



    qDebug() << m_settings.min_price;
    inputfieldsValid();
}

void FilterInputDialog::on_max_year_change()
{
    if (ui->comboBox_MaxYear->currentIndex() == 0)
        m_settings.max_year = 0;

    else
        m_settings.max_year = ui->comboBox_MaxYear->currentText().toInt();

    qDebug() << m_settings.max_year;
    inputfieldsValid();
}

void FilterInputDialog::on_min_year_change()
{
    if (ui->comboBox_MinYear->currentIndex() == 0)
        m_settings.min_year = 0;

    else
        m_settings.min_year = ui->comboBox_MinYear->currentText().toInt();

    qDebug() << m_settings.min_year;
    inputfieldsValid();
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

FilterOptions FilterInputDialog::getOptions()
{
    return m_settings;
}

void FilterInputDialog::initialize_ui()
{
    //connect ui to code

    // button clicks from buttonBox reset, ok, cancel
    connect(ui->buttonBox,
            &QDialogButtonBox::clicked,
            this,
            &FilterInputDialog::on_click_dialog_buttons);

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
    // insert maximun power and minimun power on top of combos
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


}

void FilterInputDialog::inputfieldsValid()
{
    bool validInput = true;

    // check is max_power default (= 0)
    if (m_settings.max_power < m_settings.min_power && ui->comboBox_MaxPower->currentIndex() != 0)
        validInput = false;

    if (m_settings.max_year < m_settings.min_year && ui->comboBox_MaxYear->currentIndex() != 0)
        validInput = false;

    if (m_settings.max_price < m_settings.min_price && ui->comboBox_MaxPrice->currentIndex() != 0)
        validInput = false;

    if (!validInput)
    {
        ui->label_Warning->setStyleSheet("QLabel {background-color : red; color : white}");
        ui->label_Warning->setText("Check input!");
    }
    else
    {
        ui->label_Warning->setStyleSheet("");
        ui->label_Warning->setText("");
    }

}


