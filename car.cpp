#include "car.h"

Car::Car() : m_year(-1), m_id(-1), m_horsepower(-1), m_model("null"), m_price(-1), m_img_url("null")
{

}

Car::Car(int year, int id, int horsepower, QString model, int price, QString img_url)
{
    m_year = year;
    m_id = id;
    m_horsepower = horsepower;
    m_model = model;
    m_price = price;
    m_img_url = img_url;
}

Car::~Car()
{

}

bool operator == (const Car& car1, const Car& car2)
{
    if (car1.m_id == car2.m_id)
        return true;
    else
        return false;
    /*
   if (car1.m_horsepower == car2.m_horsepower)
       if (car1.m_id == car2.m_id)
           if (car1.m_horsepower == car2.m_horsepower)
               if (car1.m_model == car2.m_model)
                   if(car1.m_price == car2.m_price)
                       if(car1.m_img_url == car2.m_img_url)
                           return true;

   return false;
   */
}

bool operator != (const Car& car1, const Car& car2)
{
    if (car1.m_id != car2.m_id)
        return true;
    else
        return false;
}

