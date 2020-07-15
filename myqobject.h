#ifndef MYQOBJECT_H
#define MYQOBJECT_H

#endif // MYQOBJECT_H

#include <QObject>
#include "mainwindow.h"

class MyQObject : public QObject
{
    Q_OBJECT

signals:
    void testSignal(int value);

public slots:
    void TestSlot(int value)
    {
        qDebug("MyQObject::TestSlot with value of %d\n", value);
    }

public:
    void InitConnection(MainWindow* mainWindow)
    {
        QObject::connect(mainWindow, &MainWindow::TestMainWindowSignal, this, &MyQObject::TestSlot);
    }

    void TestFunction(int value)
    {
        testSignal(value);
    }

};
