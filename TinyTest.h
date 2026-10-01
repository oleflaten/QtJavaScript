#ifndef TINYTEST_H
#define TINYTEST_H

#include <QObject>

//The class needs to be of type QObject
class TinyTest : public QObject
{
    // to call functions from JavaScript
    Q_OBJECT

    // To use a C++ variable in JavaScript you need to use Q_PROPERTY
    // These are names and function calls you can use from JavaScript
    //       variabel-name   read-function   write-function    signal when changed
    Q_PROPERTY(float speed READ getSpeed WRITE setSpeed) // NOTIFY valueChanged)
                                                            //get warning without this but it works

public:
    TinyTest(QObject *parent = nullptr);

    void sendSignal();

//  Q_INVOKABLE must be used in front of functions that will be called from JavaScript
    Q_INVOKABLE int commonFunc();

    //Setter and getter for speed-variable
    //names are the same as in Q_PROPERTY above
    float getSpeed() const;
    void setSpeed(float value);

signals:
    void signalOne();

public slots:
//  a public slot can be called from JavaScript, without Q_INVOKABLE
    void scriptFunction(float in);

private:
//  this cannot be called, because it is private
    Q_INVOKABLE void privateFunc();

//  this has setters and getters that through Q_PROPERTY can be used from
//  JavaScript - where it is named "speed" as given in Q_PROPERTY
    float mSpeed{4.234f};
};

#endif // TINYTEST_H
