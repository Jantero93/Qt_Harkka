#include "carmodel.h"

#include <algorithm>
#include <iostream>

// columneja yhtä monta kuin autolla attribuutteja
static constexpr int CAR_ATTRIBUTES_COUNT = 6;

CarModel::CarModel()
{
}

void CarModel::remove_car(QModelIndexList indexList)
{
    //poista indeksit suurimmasta pienimpään, ei mene järjestys sekasin
    std::sort(std::begin(indexList), std::end(indexList));
    std::reverse(std::begin(indexList), std::end(indexList));

    for(QModelIndex index : indexList){
        beginRemoveRows(QModelIndex(), index.row(), index.row());
        m_data.remove(index.row());
        endRemoveRows();
    }

}



QVariant CarModel::data(const QModelIndex &index, int role) const
{

}

int CarModel::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

int CarModel::columnCount(const QModelIndex &parent) const
{
    return CAR_ATTRIBUTES_COUNT;
}
