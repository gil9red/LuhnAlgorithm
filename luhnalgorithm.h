#ifndef LUHNALGORITHM_H
#define LUHNALGORITHM_H

#include <QString>
#include <QVector>

class LuhnAlgorithm
{
public:
    LuhnAlgorithm( const QString & number = "" );
    LuhnAlgorithm & execute();
    LuhnAlgorithm & execute(const QString & number );
    int getSum() const;
    bool isValid() const;

    void setNumberCard( const QString & number );

    QVector < qint16 > getSequence();
    static QVector < qint16 > getSequence(const QString & numberCard );

private:
    QString numberCard;
    int sum;
    QVector < qint16 > digits;
    bool valid;
};
#endif // LUHNALGORITHM_H
