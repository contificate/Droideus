#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "readers/dexreader.h"

// DEBUG
#include "ui/dexopener.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow w; // FUTURE: load JSON config?
    w.show();

    return app.exec();
}
