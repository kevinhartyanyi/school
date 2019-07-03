#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>

// képet megjelenítő gomb típusa
class ImageButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ImageButton(QWidget *parent = 0);

    QPixmap pixmap() const { return _image; }

public slots:
    void setPixmap(const QPixmap& pixmap) { _image = pixmap; repaint(); } // kép beállítása és újrarajzolás
    void clearPixmap() { _image = QPixmap(); }

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPixmap _image;
};

#endif // CARDBUTTON_H
