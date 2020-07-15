#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myqobject.h"

void MainWindow::OnTestSignal(int value)
{
    qDebug("MainWindow::OnTestSignal: Got value %d\n", value);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyQObject testing;

    // just testing to make sure the linker found this
    MyQObject::staticMetaObject;

    QObject::connect(&testing, &MyQObject::testSignal, this, &MainWindow::OnTestSignal);

    testing.TestFunction(22);

    testing.InitConnection(this);

    this->TestMainWindowSignal(85);

}

MainWindow::~MainWindow()
{
    delete ui;
}
