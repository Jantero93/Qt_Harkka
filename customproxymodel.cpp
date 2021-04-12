#include "customproxymodel.h"
#include "carmodel.h"

CustomProxyModel::CustomProxyModel() : m_min_price(0), m_max_price(0), m_min_year(0)
  , m_max_year(0), m_min_hp(0), m_max_hp(0)
{
}

// täyttääkö rivi filtterin ehdot ja lisätään modeliin
bool CustomProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    // Hae rivin data joka lohkosta
    QModelIndex idx_year = sourceModel()->index(source_row, CarModel::COL_YEAR, source_parent);
    QModelIndex idx_hp = sourceModel()->index(source_row, CarModel::COL_HP, source_parent);
    QModelIndex idx_price = sourceModel()->index(source_row, CarModel::COL_PRICE, source_parent);
    QModelIndex idx_make = sourceModel()->index(source_row, CarModel::COL_MAKE, source_parent);
    QModelIndex idx_model = sourceModel()->index(source_row, CarModel::COL_MODEL, source_parent);

    // jos filtterin ehdot ei täyty --> false
    // jos filtterin ehto 0 == ei asetettu, ei huomioida filtteröinnissä

    // vertaa min hinta
    if (sourceModel()->data(idx_price).toInt() < m_min_price && m_min_price != 0)
        return false;

    // vertaa max hinta
    if (sourceModel()->data(idx_price).toInt() > m_max_price && m_max_price != 0)
        return false;

    // vertaa min horsepower
    if (sourceModel()->data(idx_hp).toInt() < m_min_hp && m_min_hp != 0)
        return false;

    // vertaa max horsepoweriin
    if (sourceModel()->data(idx_hp).toInt() > m_max_hp && m_max_hp != 0)
        return false;

    // vertaa min vuoteen
    if (sourceModel()->data(idx_year).toInt() < m_min_year && m_min_year != 0)
        return false;

    // vertaa max vuoteen
    if (sourceModel()->data(idx_year).toInt() > m_max_year && m_max_year != 0)
        return false;

    // sisältääkö data filtterin valmistajaa
    if (!sourceModel()->data(idx_make).toString().contains(m_make, Qt::CaseInsensitive))
        return false;

    // sisältääkö data filtterin mallia
    if (!sourceModel()->data(idx_model).toString().contains(m_model, Qt::CaseInsensitive))
        return false;


    return true;
}

QVariant CustomProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}

void CustomProxyModel::setMinPrice(int min_price)
{
     if (min_price != m_min_price)
         m_min_price = min_price;

    invalidateFilter();
}

void CustomProxyModel::setMaxPrice(int max_price)
{
    if (max_price != m_max_price)
        m_max_price = max_price;

    invalidateFilter();
}

void CustomProxyModel::setMinYear(int min_year)
{
    if (min_year != m_min_year)
        m_min_year = min_year;

    invalidateFilter();
}

void CustomProxyModel::setMaxYear(int max_year)
{
    if (max_year != m_max_year)
        m_max_year = max_year;

    invalidateFilter();
}

void CustomProxyModel::setMinHP(int min_hp)
{
    if (min_hp != m_min_hp)
        m_min_hp = min_hp;

    invalidateFilter();
}

void CustomProxyModel::setMaxHP(int max_hp)
{
    if (m_max_hp != max_hp)
        m_max_hp = max_hp;

    invalidateFilter();
}

void CustomProxyModel::setMake(QString make)
{
    if (make != m_make)
        m_make = make;

    invalidateFilter();
}

void CustomProxyModel::setModel(QString model)
{
    if (model != m_model)
        m_model = model;

    invalidateFilter();
}
