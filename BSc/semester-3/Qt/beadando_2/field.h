#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QPushButton>

class Field : public QPushButton
{
    Q_OBJECT
public:
    Field(QWidget* parent = 0);
    void changeColour(QString);
    ~Field();

private:


};

#endif // FIELD_H
