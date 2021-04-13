#ifndef FILTERINPUTDIALOG_H
#define FILTERINPUTDIALOG_H

#include "utility.h"

#include <QDialog>


namespace Ui {
class FilterInputDialog;
}

class FilterInputDialog : public QDialog
{
    Q_OBJECT

private slots:
    void on_make_change();
    void on_model_change();
    void on_max_power_change();
    void on_min_power_change();
    void on_max_price_change();
    void on_min_price_change();
    void on_max_year_change();
    void on_min_year_change();

public:
    explicit FilterInputDialog(QWidget *parent = nullptr);
    ~FilterInputDialog();
    // ei init vielä
    FilterOptions getOptions();

private:
    Ui::FilterInputDialog *ui;

    // struct
    FilterOptions m_settings;
    void initialize_ui();

    //set ok button enabled if inputs are valid
    void inputfieldsValid();
};

#endif // FILTERINPUTDIALOG_H
