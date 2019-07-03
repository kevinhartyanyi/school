#include "imagebutton.h"
#include <QPainter>

ImageButton::ImageButton(QWidget *parent) :
    QPushButton(parent)
{
}

void ImageButton::paintEvent(QPaintEvent *event)
{
    if (_image.width() > 0 && _image.height() > 0) // ha van kép a gombon
    {
        QPainter painter(this);
        painter.drawPixmap(rect(), _image); // akkor kirajzoljuk a képet
    }
    else
    {
        QPushButton::paintEvent(event); // egyébként az alapértelmezett gombrajzolást végezzük
    }
}
