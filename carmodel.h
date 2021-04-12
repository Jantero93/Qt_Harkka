#ifndef CARMODEL_H
#define CARMODEL_H

#include "car.h"

#include <QAbstractTableModel>
#include <QVector>

class CarModel : public QAbstractTableModel
{
public:
    CarModel();
    // Mikä columni on mikäkin
    static constexpr int COL_MAKE = 0;
    static constexpr int COL_MODEL = 1;
    static constexpr int COL_YEAR = 2;
    static constexpr int COL_HP = 3;
    static constexpr int COL_PRICE = 4;
    static constexpr int COL_URL = 5;

    void add_car(Car car);
    void remove_car(QModelIndexList);

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

private:
    QVariant insert_data_to_column(QModelIndex index, Car car) const;
    // apufunktiota
    void sort_ascending_order(int column);
    void sort_descending_order(int column);

    QVector<Car> m_data;
};

#endif // CARMODEL_H
