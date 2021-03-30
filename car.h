#ifndef CAR_H
#define CAR_H

#include <QString>

class Car
{
public:
    Car();
    Car(int year, int id, int horsepower, QString model, int price, QString img_url);
    ~Car();

    int m_year;
    int m_id;
    int m_horsepower;
    QString m_model;
    int m_price;
    QString m_img_url;
};

bool operator ==(const Car& car1, const Car& car2);
bool operator !=(const Car& car1, const Car& car2);



#endif // CAR_H
