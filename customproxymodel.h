#ifndef CUSTOMPROXYMODEL_H
#define CUSTOMPROXYMODEL_H

#include <QSortFilterProxyModel>


class CustomProxyModel : public QSortFilterProxyModel
{
public:
    CustomProxyModel();
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    // setterit
    void setMinPrice(int min_price);
    void setMaxPrice(int max_price);
    void setMinYear(int min_year);
    void setMaxYear(int max_year);
    void setMinHP(int min_hp);
    void setMaxHP(int max_hp);
    void setMake(QString make);
    void setModel(QString model);
    // resetoi filtter asetukset
    void resetFilter();
    // on / off filteröinti
    void enableFiltering(bool enable);

private:
    // jos 0 (alustus), niin ei filtteröidä
    int m_min_price;
    int m_max_price;
    int m_min_year;
    int m_max_year;
    int m_min_hp;
    int m_max_hp;
    QString m_make;
    QString m_model;

    // defaulttina pois päältä
    bool m_filter_enabled;
};

#endif // CUSTOMPROXYMODEL_H
