#include <QString>
#include <QStringList>

QStringList generateDropDownForLoop(int start, int step, int end, bool reverseOrder);
QStringList generateDropDownPriceItems();

struct FilterOptions
{
    int min_year;
    int max_year;
    int min_price;
    int max_price;
    int min_power;
    int max_power;
    QString make;
    QString model;
};

