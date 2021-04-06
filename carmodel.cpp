#include "carmodel.h"

#include <algorithm>
#include <iostream>

// columneja yhtä monta kuin autolla attribuutteja
static constexpr int CAR_ATTRIBUTES_COUNT = 5;

CarModel::CarModel()
{
}

void CarModel::add_car(Car car)
{
    m_data.push_back(car);
}

void CarModel::remove_car(QModelIndexList indexList)
{
    //poista indeksit suurimmasta pienimpään, ei mene järjestys sekasin
    std::sort(std::begin(indexList), std::end(indexList));
    std::reverse(std::begin(indexList), std::end(indexList));

    foreach(QModelIndex index, indexList){
        beginRemoveRows(QModelIndex(), index.row(), index.row());
        m_data.remove(index.row());
        endRemoveRows();
    }

}

// Set headers for view
QVariant CarModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0: return "Make";
        case 1: return "Model";
        case 2: return "Year";
        case 3: return "Horsepower";
        case 4: return "Price";
        case 5: return "Image URL";
        default: break;
        }
    }

    return QVariant();
}



QVariant CarModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        Car car = m_data.at(index.row());

        return insertDataToColumn(index, car);
    }
 return QVariant();
}

int CarModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

int CarModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return CAR_ATTRIBUTES_COUNT;
}

QVariant CarModel::insertDataToColumn(QModelIndex index, Car car) const
{
    switch (index.column()) {
    case 0: return car.m_make;
    case 1: return car.m_model;
    case 2: return car.m_year;
    case 3: return car.m_horsepower;
    case 4: return car.m_price;
    case 5: return car.m_img_url;
    default: break;
    }

}
