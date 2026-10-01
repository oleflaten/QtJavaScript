#include <QCoreApplication>
#include <QDebug>       //Using qDebug
#include <QFile>        //Reading from file
#include <QJSEngine>    //The script engine itself!

//The object I want to use in script
#include "TinyTest.h"

int main(int argc, char *argv[])
{
    //Must have a QCoreApplication or QApplication
    //made before the QJSEngine is made
    //Even if we don't use it in this program.
    //(Our Game Engine project is a QApplication)
    QCoreApplication app(argc, argv);

    // !!!NB!!!
    //Comment in/out the parts of this file that you want to explore!
    //Look in the script file and the TinyTest-class
    //to understand the connections!

    qDebug( "Hello JavaScriptz!\n");

    //Make the Script engine itself
    QJSEngine engine;
    // qDebug() << "The script engine is small: " << sizeof(engine) << "\n";


    //0. Evaluate and run scripts directly (not from scriptfile): *************************
    //You put your script code inside engine.evaluate("script code here");

       // QJSValue scriptVariable = engine.evaluate("1 + 6");
       // qDebug() << scriptVariable.toNumber();

       // qDebug() << engine.evaluate("'the magic number is'").toString()
       //          << engine.evaluate("3.8 + 4").toNumber();

    // NB !!!
    // JS variables are whatever. We need to convert to specific datatypes!
    // We have to use .toNumber() and .toString() etc. to tell C++ what type to expect

    //Using script files: *****************************************
    //You have to do some setup stuff

    //Make variable to the path
    //We also use this in the engine.evaluate() call later
    QString fileName = "../../testscript.js";
    //Make a QFile for it
    QFile scriptFile(fileName);

    //Try to open file and give error if something is wrong
    if (!scriptFile.open(QIODevice::ReadOnly))
        qDebug() << "Error - NO FILE HERE: " << fileName;
    else
        qDebug() << "\n -- script file opened: " << fileName;

    //reads the file
    QTextStream stream(&scriptFile);
    QString contents = stream.readAll();
    //now "contents" holds the whole JavaScript

    //close the file, because we don't need it anymore
    scriptFile.close();

    //Loads the whole script into script engine:
    //The important part! fileName is used to report bugs in the file
    engine.evaluate(contents, fileName);


    //1. Call a function in the script file: *****************************************
    // 4 steps:
    //Make a C++ variable to the function
    // QJSValue func = engine.evaluate("addition");
    //and the arguments
    // QJSValueList args;
    //Read in arguments: 3 is the first (a) 8.9 is the last (b)
    // args << 3 << 8.9;
    //Call the function and hold the return value
    // QJSValue result = func.call(args);
    //Check the return value (toNumber() makes a double of it)
    // qDebug() << result.toNumber() << "\n";


    //2. Reads a variable value from the script file: *****************************************
    // QJSValue mString = engine.evaluate("myVariable");
    // qDebug() << mString.toString() << "\n";

    //3. Push a C++ object to JavaScript: *****************************************
    //Make Tiny object - Tiny is a cpp class we have made:
    // TinyTest *tinyObject = new TinyTest;
    //Makes a script-version for the script engine:
    // QJSValue objectTest = engine.newQObject(tinyObject);
    //Make a name for the object in the script engine
    // engine.globalObject().setProperty("cObject", objectTest);

    //4. Calls a function in script that calls the C-function: ***************************
    //Make a variable for the function
    // QJSValue directCCall = engine.evaluate("callCFunction");
    //Call the function
    // QJSValue speed = directCCall.call();
    // qDebug() << speed.toNumber();

    //5. Calls a function in script that calls the C-function: ***************************
    //C functions have to be public and have Q_INVOKABLE in front of it
    //or it has to be a public slots: function
    //    QJSValue commonF = engine.evaluate("callCommonFunction");
    //    QJSValue c = commonF.call();
    //    qDebug() << "The c++ function returned " << c.toInt() << "to the JavaScript\n";

    //6. Calls a  function in script that calls a private C-function: *********************
    //Does not work because it is private!
    //    QJSValue directPCall = engine.evaluate("callPFunction");
    //    directPCall.call();

    //7. A fancy way to connect a function in script to a signal and slot *****************
    //    QJSValue cFunc = engine.evaluate("connectToSlot");
    //    cFunc.call();
    //    tinyObject->sendSignal();

    //8. Use variable from C object in script
    //    QJSValue useFunction = engine.evaluate("useCVariable");
    //    QJSValue result = useFunction.call();
    //    qDebug() << "C value:" << result.toNumber();

    //    QJSValue useFunction2 = engine.evaluate("setCVariable");
    //    useFunction2.call();
    //    qDebug() << "C value changed to:" << tinyObject->getSpeed();

    return 0;
}
