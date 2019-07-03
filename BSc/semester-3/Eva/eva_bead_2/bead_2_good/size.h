#ifndef SIZE_H
#define SIZE_H

#include <QDialog>

namespace Ui {
class Size;
}

class Size : public QDialog
{
    Q_OBJECT

public:
    explicit Size(QWidget *parent = nullptr);
    ~Size();

signals:
    void sendSize(int);
    void sendLoad(QString);

private slots:
    void go();

private:
    Ui::Size *ui;
    int size;
};

#endif // SIZE_H
