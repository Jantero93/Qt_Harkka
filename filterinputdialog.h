#ifndef FILTERINPUTDIALOG_H
#define FILTERINPUTDIALOG_H

#include "filtersettings.h"

#include <QDialog>
#include <QIntValidator>

namespace Ui {
class FilterInputDialog;
}

class FilterInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterInputDialog(QWidget *parent = nullptr);
    ~FilterInputDialog();

private:
    Ui::FilterInputDialog *ui;
    // structi
    FilterOptions settings;
};

#endif // FILTERINPUTDIALOG_H
