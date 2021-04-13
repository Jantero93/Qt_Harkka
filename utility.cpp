
#include "utility.h"
#include <QLocale>

QStringList generateDropDownForLoop(int start, int step, int end, bool reverseOrder)
{
    QStringList list;

    if (reverseOrder)
    {
        for ( ; end >= start; end -= step)
        {
            list.append(QString::number(end));
        }
    }
    else
    {
        for ( ; start <= end; start += step)
        {
            list.append(QString::number(start));
        }
    }

    return list;
}


QStringList generateDropDownPriceItems()
{
    QStringList list;
    int step = 500;

    for (int i = 500; i <= 1000*1000; i += step)
    {

        QString string_number(QString::number(i));

        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
        QLocale english;


        list.push_back(english.toString(i));

        switch (i)
        {
        case 3 * 1000:  step = 1000; break;
        case 10 * 1000: step = 2000; break;
        case 20 * 1000: step = 5000; break;
        case 50 * 1000: step = 10000; break;
        case 100 * 1000: step = 20000; break;
        case 200 * 1000: step = 50000; break;
        default: break;
        }
    }

    return list;
}
