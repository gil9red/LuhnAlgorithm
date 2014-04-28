#ifndef LUHNALGORITHM_H
#define LUHNALGORITHM_H

#include <QString>
#include <QVector>

class LuhnAlgorithm
{
public:
    LuhnAlgorithm( const QString & t );
    LuhnAlgorithm & execute();
    int getSum() const;
    bool isValid() const;

    QVector < qint16 > getSequence();
    static QVector < qint16 > getSequence( const QString & text );

private:
    QString text;
    int sum;
    QVector < qint16 > digits;
    bool valid;
};
#endif // LUHNALGORITHM_H
