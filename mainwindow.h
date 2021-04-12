#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "carmodel.h"
#include "customproxymodel.h"

#include <QMainWindow>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
  //  void on_click_filter_settings_button();
  //  void on_click_calculate_costs_button();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    CarModel* m_car_model;
    CustomProxyModel* m_proxy_model;

};
#endif // MAINWINDOW_H
