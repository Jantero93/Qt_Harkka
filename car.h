#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QMetaType>

class Car
{
public:
    Car();
    Car(int year, /*int id,*/ int horsepower, QString make, QString model, int price/*, QString img_url*/);
    ~Car();

    Car &operator=(const Car& car);


    int m_year;
  //  int m_id;
    int m_horsepower;
    QString m_make;
    QString m_model;
    int m_price;
  //  QString m_img_url;
};

Q_DECLARE_METATYPE(Car);
/*
bool operator ==(const Car& car1, const Car& car2);
bool operator !=(const Car& car1, const Car& car2);
*/





#endif // CAR_H
