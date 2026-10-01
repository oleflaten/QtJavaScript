#include "TinyTest.h"
#include <QDebug>

TinyTest::TinyTest(QObject *parent) : QObject(parent)
{
}

void TinyTest::scriptFunction(float in)
{
    qDebug() << "This C++ function is called from the script! How cool is that!";
    qDebug() << "The javaScript variable is " << in << "\n";
}

void TinyTest::privateFunc()
{
    qDebug() << "Private funtion" << "\n";
}

float TinyTest::getSpeed() const
{
    return mSpeed;
}

void TinyTest::setSpeed(float value)
{
    mSpeed = value;
}

void TinyTest::sendSignal()
{
    emit signalOne();
}

int TinyTest::commonFunc()
{
    int a{234};
    qDebug() << "commonFunc";
    return a;
}

