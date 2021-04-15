#include "readjson.h"

#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVector>
#include <QException>

QVector<Car> get_cars_from_json_file() {

    const QString FILE_NAME("CARS_data.json");

    QFile file;
    file.setFileName(FILE_NAME);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QByteArray json_text = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument document = QJsonDocument::fromJson(json_text, &parseError);

    // check parse errors
    if (parseError.error != QJsonParseError::NoError){
        qDebug() << "Parse error on fetching data from json file, error msg: " << parseError.errorString();

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
    int horsepower = value.toObject().value("horsepower").toInt();
    int price = value.toObject().value("price").toInt();
    QString make(value.toObject().value("make").toString());
    QString model(value.toObject().value("model").toString());

    return Car(year, horsepower, make, model, price);
}
