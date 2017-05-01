#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>

#include "readers/dexreader.h"

// DEBUG
#include "ui/dexopener.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // load QDarkStyle
    QFile f(":/qdarkstyle/style.qss");
    if (f.exists())
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        app.setStyleSheet(ts.readAll());
    }

    // show main window
    MainWindow w; // FUTURE: load JSON config?
    w.show();

    return app.exec();
}
