#ifndef COSTSCALCULATOR_H
#define COSTSCALCULATOR_H

#include <QDialog>
#include "car.h"
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

    void setCar(Car car);

    struct UserInput
    {
        int driven_kilometers = 0;
        double fuel_price = 0;
        double fuel_consuption = 0;
        int insurance = 0;
        int maintance = 0;
        int inspection = 0;
    };

private:
    Ui::CostsCalculator *ui;

    UserInput getInputFromUI();
    void setCarLabels();

    Car m_car;
};

#endif // COSTSCALCULATOR_H
