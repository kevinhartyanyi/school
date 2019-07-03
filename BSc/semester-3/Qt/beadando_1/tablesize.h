#ifndef TABLESIZE_H
#define TABLESIZE_H

#include <QDialog>
#include <QDebug>
#include "size.h"

namespace Ui {
class TableSize;
}

class TableSize : public QDialog
{
    Q_OBJECT

public:
    explicit TableSize(QWidget *parent = nullptr);
    struct size GetTable() {return table;}
    ~TableSize();

private slots:
    void SetTable();

private:
    struct size table;
    Ui::TableSize *ui;
};

#endif // TABLESIZE_H
