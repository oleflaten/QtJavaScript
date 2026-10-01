#ifndef TINYTEST_H
#define TINYTEST_H

#include <QObject>

//Klassen må være av type QObject
class TinyTest : public QObject
{
//  for å kalle funksjoner fra javascript
    Q_OBJECT

//  For å bruke en C++ variabel i javascript må du bruke Q_PROPERTY
//  Dette er navn og funksjonskall du kan bruke fra javascript
//           variabel  navn     lesfunk       skrivfunc        signal ved forandring
    Q_PROPERTY(float speed READ getSpeed WRITE setSpeed)    // NOTIFY valueChanged)
                                                            //get warning without this but it works

public:
    TinyTest(QObject *parent = nullptr);

    void sendSignal();

//  Q_INVOKABLE må brukes forran funksjoner som skal kalles fra javascript
    Q_INVOKABLE int commonFunc();

    //Setter og getter for speed-variabelen
    //navnene er de samme som i Q_PROPERTY over
    float getSpeed() const;
    void setSpeed(float value);

signals:
    void signalOne();

public slots:
//  en public slot kan kalles fra javascript, uten Q_INVOKABLE
    void scriptFunction(float in);

private:
//  denne kan ikke kalles, fordi den er private
    Q_INVOKABLE void privateFunc();

//  denne har setters og getters som gjennom Q_PROPERTY kan brukes fra
//  javascript - der den heter bare "speed" som angitt i Q_PROPERTY
    float mSpeed{4.234f};
};

#endif // TINYTEST_H
