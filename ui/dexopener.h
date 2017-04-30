#ifndef DEXOPENER_H
#define DEXOPENER_H

#include <QWidget>

namespace Ui {
class DexOpener;
}

class DexOpener : public QWidget
{
    Q_OBJECT
public:
    explicit DexOpener(QWidget *parent = nullptr);



    ~DexOpener();

private:
    Ui::DexOpener *ui;
};

#endif // DEXOPENER_H
