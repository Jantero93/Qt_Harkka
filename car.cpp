#include "car.h"

Car::Car() : m_year(-1), m_horsepower(-1), m_make("null"), m_price(-1)
{

}

Car::Car( int year, int horsepower, QString make, QString model, int price)
{
    m_year = year;
    m_horsepower = horsepower;
    m_make = make;
    m_model = model;
    m_price = price;
}

Car::~Car()
{

}

Car &Car::operator=(const Car &car)
{
    if (this != &car)
    {
        m_year = car.m_year;
        m_horsepower = car.m_horsepower;
        m_make = car.m_make;
        m_model = car.m_model;
        m_price = car.m_price;
    }
    return *this;
}
