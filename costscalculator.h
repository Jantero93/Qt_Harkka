#ifndef COSTSCALCULATOR_H
#define COSTSCALCULATOR_H

#include <QDialog>

namespace Ui {
class CostsCalculator;
}

class CostsCalculator : public QDialog
{
    Q_OBJECT

private slots:
    void on_click_exit_button();
    void on_click_calc_button();

public:
    explicit CostsCalculator(QWidget *parent = nullptr);
    ~CostsCalculator();

private:
    Ui::CostsCalculator *ui;
};

#endif // COSTSCALCULATOR_H
