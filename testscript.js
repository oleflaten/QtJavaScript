function addition(a, b)
{
    return a + b;
}

var myVariable = "Really cool! Regards, The Script.";

function callCFunction()
{
    var mNum = 24.5;
    //call a C++ function with my variable
    //cObject is given to script in C++ code
    cObject.scriptFunction(mNum);

    var s = cObject.speed + 0.3;
    return s;
}

function callCommonFunction()
{
    var a = cObject.commonFunc();
    return a;
}

function callPFunction()
{
    //does not work because it is private and not a public slot or Q_INVOKABLE
    cObject.privateFunc();
}

function connectToSlot()
{
    // test 1 - call a slot in the class:
    cObject.signalOne.connect(callCFunction);
}

function useCVariable()
{
    return cObject.speed;
}

function setCVariable()
{
    cObject.speed = 23.4;
}
