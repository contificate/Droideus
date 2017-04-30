#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // just some small tests at the moment
    try {

        DexReader reader("/home/dosto/Desktop/classes.dex");
        auto header = reader.readHeader();

    } catch (const std::runtime_error& e) {
        qDebug() << e.what();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
