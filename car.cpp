#include "car.h"

Car::Car() : m_year(-1), m_id(-1), m_horsepower(-1), m_make("null"), m_price(-1), m_img_url("null")
{

}

Car::Car( int year, int id, int horsepower, QString make, int price, QString img_url )
{
    m_year = year;
    m_id = id;
    m_horsepower = horsepower;
    m_make = make;
    m_price = price;
    m_img_url = img_url;
}

Car::~Car()
{

}

/* every car has unique id */
bool operator == (const Car& car1, const Car& car2)
{
    return car1.m_id == car2.m_id;
}

bool operator != (const Car& car1, const Car& car2)
{
    return car1.m_id != car2.m_id;
}

