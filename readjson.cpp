#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "readjson.h"

#include <iostream>
#include <QDebug>

#include <QVector>

QVector<Car> get_car_vector_from_json_file() {
    QFile file;
    QByteArray json_text;

    file.setFileName("CARS_data.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    json_text = file.readAll();
   // std::cout << json_text.toStdString() << std::endl;
    file.close();

    QJsonParseError parseError;
    QJsonDocument document = QJsonDocument::fromJson(json_text, &parseError);

    // check parse errors
    if (parseError.error != QJsonParseError::NoError){
        qDebug() << "Parse error: " << parseError.errorString();
    }
    // array from root object
    QJsonArray car_json_array = document.array();

    QVector<Car> car_list;
    foreach (const QJsonValue& value, car_json_array) {
       car_list.append(parse_car_from_jsonArray(value));
    }

    /*
    foreach(const Car car, car_list){
        std::cout << car.m_id << std::endl;
        std::cout << car.m_make.toStdString() << std::endl;
        std::cout << car.m_model.toStdString() << std::endl;
        std::cout << car.m_year << std::endl;
        std::cout << std::endl;

    }
    */
    return car_list;
}



Car parse_car_from_jsonArray(const QJsonValue value)
{
    int year = value.toObject().value("year").toInt();
    int id = value.toObject().value("id").toInt();
    int horsepower = value.toObject().value("horsepower").toInt();
    int price = value.toObject().value("price").toInt();
    QString make(value.toObject().value("make").toString());
    QString img_url(value.toObject().value("img_url").toString());
    QString model(value.toObject().value("model").toString());

    return Car(year, id, horsepower, make, model, price, img_url);
}
