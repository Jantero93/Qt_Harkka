#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QMetaType>

class Car
{
public:
    Car();
    Car(int year, int horsepower, QString make, QString model, int price);
    ~Car();

    Car &operator=(const Car& car);

    int m_year;
    int m_horsepower;
    QString m_make;
    QString m_model;
    int m_price;

};

Q_DECLARE_METATYPE(Car);


#endif // CAR_H
