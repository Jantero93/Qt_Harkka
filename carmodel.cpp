#include "carmodel.h"

#include <algorithm>
#include <iostream>



CarModel::CarModel()
{
}

void CarModel::add_car(Car car)
{
    m_data.push_back(car);
}

void CarModel::remove_car(QModelIndexList indexList)
{
    // delete indexes descending order
    std::sort(std::begin(indexList), std::end(indexList));
    std::reverse(std::begin(indexList), std::end(indexList));

    foreach(QModelIndex index, indexList){
        beginRemoveRows(QModelIndex(), index.row(), index.row());
        m_data.remove(index.row());
        endRemoveRows();
    }

}

Car CarModel::get_car(int row)
{
    return m_data.at(row);
}

// Set headers for view
QVariant CarModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case COL_MAKE: return "Make";
        case COL_MODEL: return "Model";
        case COL_YEAR: return "Year";
        case COL_POWER: return "Horsepower";
        case COL_PRICE: return "Price";
        default: break;
        }
    }

    return QVariant();
}

QVariant CarModel::data(const QModelIndex &index, int role) const
{
    // set data center on table view
    if(role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }

    if (role == Qt::DisplayRole)
    {
        Car car = m_data.at(index.row());
        return this->insert_data_to_column(index, car);
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
    return CAR_MODEL_ATTRIBUTES_COUNT;
}

void CarModel::sort(int column, Qt::SortOrder order)
{
    switch (order)
    {
    case Qt::AscendingOrder:
        sort_ascending_order(column);
        break;

    case Qt::DescendingOrder:
        sort_descending_order(column);
        break;
    }

    emit(dataChanged( index(0,0), index(rowCount() - 1, columnCount() - 1) ));
}

QVariant CarModel::insert_data_to_column(QModelIndex index, Car car) const
{
    switch (index.column())
    {
    case 0: return car.m_make;
    case 1: return car.m_model;
    case 2: return car.m_year;
    case 3: return car.m_horsepower;
    case 4: return car.m_price;
    default: break;
    }

    return QVariant();
}

void CarModel::sort_ascending_order(int column) {

    switch (column) {
    case 0:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b){return a.m_make > b.m_make; });
        break;

    case 1:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_model > b.m_model; });
        break;

    case 2:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_year> b.m_year; });
        break;

    case 3:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_horsepower > b.m_horsepower; });
        break;

    case 4:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_price > b.m_price; });
        break;
    }
}

void CarModel::sort_descending_order(int column)
{
    switch (column) {
    case 0:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b){return a.m_make < b.m_make; });
        break;

    case 1:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_model < b.m_model; });
        break;

    case 2:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_year < b.m_year; });
        break;

    case 3:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_horsepower < b.m_horsepower; });
        break;

    case 4:
        std::sort(m_data.begin(), m_data.end(),
                  [](Car a, Car b) {return a.m_price < b.m_price; });
        break;
    }
}
