#ifndef NUMBERGRIDWIDGET_H
#define NUMBERGRIDWIDGET_H

#include <QWidget>
#include <QLCDNumber>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "gridsizedialog.h"

class NumberGridWidget : public QWidget
{
    Q_OBJECT

public:
    NumberGridWidget(QWidget *parent = 0);
    ~NumberGridWidget();

private slots:
    void setNumber(); // szám megjelenítése az LCD kijelzőn
    void resizeGrid(); // rács méretezése

private:
    GridSizeDialog* _gridSizeDialog; // méretbeállító ablak
    QLCDNumber *_lcdNumber;
    QPushButton *_sizeButton;
    QGridLayout* _gridLayout;
    QVBoxLayout *_vBoxLayout;
    QVector<QPushButton*> _buttonGrid; // gombrács
};

#endif // NUMBERGRIDWIDGET_H
