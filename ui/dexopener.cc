#include "dexopener.h"
#include "ui_dexopener.h"

DexOpener::DexOpener(QWidget *parent) :
    QWidget(parent, Qt::Dialog),
    ui(new Ui::DexOpener)
{
    ui->setupUi(this);

    setWindowTitle("Open .dex file");
}

DexOpener::~DexOpener()
{
    delete ui;
}
