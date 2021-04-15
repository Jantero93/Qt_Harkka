#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "carmodel.h"
#include "costscalculator.h"
#include "customproxymodel.h"
#include "filterinputdialog.h"

#include <QMainWindow>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_click_filter_settings_button();
    void on_checkbox_state_change();
    void on_click_calculate_costs_button();
    void on_pressed_cell_table_view_row();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    void setSettingsFromDialogToProxyModel();


    Car m_car;
    CarModel* m_car_model;
    CostsCalculator* m_costs_calc;
    CustomProxyModel* m_proxy_model;
    FilterInputDialog *m_filter_input_dialog;
};
#endif // MAINWINDOW_H
