#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "luhnalgorithm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cardNumber->setValidator( new QRegExpValidator( QRegExp( "^[0-9]*" ) ) );
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cardNumber_textChanged( const QString & text )
{
    LuhnAlgorithm luhn( text );
    QVector < qint16 > array = luhn.execute().getSequence();
    if ( array.isEmpty() )
    {
        ui->digits->clear();
        ui->sum->clear();
        ui->successful->clear();
        return;
    }

    QString result = QString::number( array.at(0) );
    for ( int i = 1; i < array.size(); i++ )
        result += ( i % 4 == 0 ? " + " : "+" ) + QString::number( array.at(i) );

    ui->digits->setText( result );
    ui->sum->setText( " = " + QString::number( luhn.getSum() ) );

    ui->successful->setPixmap( QPixmap( luhn.isValid() ? ":/valid" : ":/not_valid" ) );
}
