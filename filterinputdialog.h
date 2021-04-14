#ifndef FILTERINPUTDIALOG_H
#define FILTERINPUTDIALOG_H

#include "utility.h"

#include <QDialog>
#include <QAbstractButton>


namespace Ui {
class FilterInputDialog;
}

class FilterInputDialog : public QDialog
{
    Q_OBJECT

private slots:
    void on_click_dialog_buttons(QAbstractButton *clicked_button);

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

    FilterOptions getOptions();

private:
    Ui::FilterInputDialog *ui;

    // struct for filter settings
    FilterOptions m_settings;
    void initialize_ui();

    //set ok button enabled if inputs are valid
    void inputfieldsValid();

};

#endif // FILTERINPUTDIALOG_H
