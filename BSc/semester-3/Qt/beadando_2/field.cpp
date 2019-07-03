#include "field.h"

Field::Field(QWidget* parent) : QPushButton (parent)
{
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    setEnabled(false);
}

Field::~Field()
{

}

void Field::changeColour(QString colour)
{
    this->setStyleSheet(colour);
}



