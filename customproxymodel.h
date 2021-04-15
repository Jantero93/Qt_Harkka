#ifndef CUSTOMPROXYMODEL_H
#define CUSTOMPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "car.h"

class CustomProxyModel : public QSortFilterProxyModel
{
public:
    CustomProxyModel();
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
  //  virtual QModelIndex mapFromSource(const QModelIndex& sourceIndex) const override;
  //  virtual QModelIndex mapToSource(const QModelIndex& proxyIndex) const override;
  //  virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  //  virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    // setterit
    void setMinPrice(int min_price);
    void setMaxPrice(int max_price);
    void setMinYear(int min_year);
    void setMaxYear(int max_year);
    void setMinPower(int min_hp);
    void setMaxPower(int max_hp);
    void setMake(QString make);
    void setModel(QString model);
    // resetoi filtter asetukset
    void resetFilter();
    // on / off filteröinti
    void enableFiltering(bool enable);

    // TEST
    Car getCarByModelIndex(QModelIndex proxy_index,int role = Qt::DisplayRole);

private:
    // jos 0 (alustus), niin ei filtteröidä
    int m_min_price;
    int m_max_price;
    int m_min_year;
    int m_max_year;
    int m_min_power;
    int m_max_power;
    QString m_make;
    QString m_model;

    // defaulttina pois päältä
    bool m_filter_enabled;
};

#endif // CUSTOMPROXYMODEL_H
