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

    QJsonArray car_json_array = document.array();

    QVector<Car> car_list;
    foreach (const QJsonValue& value, car_json_array) {
       car_list.append(parse_car_from_jsonArray(value));
    }

    for (int i = 0; i < car_list.size(); i++)
        std::cout << car_list.at(i).m_id << std::endl;

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

    return Car(year, id, horsepower, make, price, img_url);
}
