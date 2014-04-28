#include "luhnalgorithm.h"

const int getSumSequence( const QVector < qint16 > & arr )
{
    int sum = 0;
    foreach ( qint16 n, arr )
        sum += n;

    return sum;
}

LuhnAlgorithm::LuhnAlgorithm( const QString & t )
    : text(t), sum(0), valid( false )
{

}

LuhnAlgorithm &LuhnAlgorithm::execute()
{
    digits = getSequence( text );
    sum = getSumSequence( digits );
    valid = sum % 10 == 0; // Если сумма кратна 10, тогда номер правильный

    return *this;
}
int LuhnAlgorithm::getSum() const
{
    return sum;
}
bool LuhnAlgorithm::isValid() const
{
    return valid;
}

QVector < qint16 > LuhnAlgorithm::getSequence()
{
    return digits;
}
QVector < qint16 > LuhnAlgorithm::getSequence( const QString & text )
{
    // Алгоритм Луна
    // http://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9B%D1%83%D0%BD%D0%B0
    //
    QVector < qint16 > array;
    const qint32 length = text.length();
    for( qint32 i = 0; i < length; i++ )
    {
        qint16 digit = text.at(i).digitValue();
        if ( i % 2 == 0 )
        {
            digit *= 2;
            digit = (digit > 9 ? digit - 9 : digit);
        }
        array << digit;
    }

    return array;
}
