#ifndef FILTERINPUTDIALOG_H
#define FILTERINPUTDIALOG_H

#include "utility.h"

#include <QDialog>
#include <QIntValidator>

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

private:
    Ui::FilterInputDialog *ui;

    // struct
    FilterOptions settings;
    void initialize_ui();
};

#endif // FILTERINPUTDIALOG_H
