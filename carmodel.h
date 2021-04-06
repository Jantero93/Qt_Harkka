#ifndef CARMODEL_H
#define CARMODEL_H

#include "car.h"

#include <QAbstractTableModel>
#include <QVector>

class CarModel : public QAbstractTableModel
{
public:
    CarModel();

    void add_car(Car car);
    void remove_car(QModelIndexList);

    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;

private:
    QVector<Car> m_data;
};

#endif // CARMODEL_H
