#ifndef READJSON_H
#define READJSON_H

#include "car.h"
#include <QJsonValue>

QVector<Car> get_cars_from_json_file();
Car parse_car_from_jsonArray(const QJsonValue value);

#endif // READJSON_H
