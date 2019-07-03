#include "numbergridwidget.h"

NumberGridWidget::NumberGridWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(trUtf8("Számrács"));
    setFixedSize(400,400);

    _sizeButton = new QPushButton(trUtf8("Átméretezés"));
    _lcdNumber = new QLCDNumber();
    _gridLayout = new QGridLayout();

    _vBoxLayout = new QVBoxLayout(); 
    _vBoxLayout->addWidget(_sizeButton);
    _vBoxLayout->addWidget(_lcdNumber); 
    _vBoxLayout->addLayout(_gridLayout);

    setLayout(_vBoxLayout);

    _gridSizeDialog = new GridSizeDialog();
    connect(_sizeButton, SIGNAL(clicked()), _gridSizeDialog, SLOT(exec())); // méretező ablak megjelenítése gombnyomásra
    connect(_gridSizeDialog, SIGNAL(accepted()), this, SLOT(resizeGrid())); // átméretezés a dialógus elfogadására
}

NumberGridWidget::~NumberGridWidget()
{
    delete _gridSizeDialog;
}

void NumberGridWidget::setNumber()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    // a küldõ tí­pusát castolnunk kell, hogy lekérdezhessük a text tulajdonságát

    if (senderButton->text() != "X")
        _lcdNumber->display(senderButton->text());

    senderButton->setText("X");
    // a gombra beállí­tunk egy X feliratot
}

void NumberGridWidget::resizeGrid()
{
    foreach(QPushButton* button, _buttonGrid) // korábbi gombok
    {
        _gridLayout->removeWidget(button); // levétel az elrendezésről
        delete button; // vezérlő törlése
    }
    _buttonGrid.clear(); // mutatók törlése

    for (int i = 0; i < _gridSizeDialog->gridSize(); ++i) {
        for (int j = 0; j < _gridSizeDialog->gridSize(); ++j){
            QPushButton* button = new QPushButton(QString::number(i * _gridSizeDialog->gridSize() + j + 1)); // gomb létrehozása
            _gridLayout->addWidget(button, i, j); // gomb felvétele az elrendezésbe
            _buttonGrid.append(button); // elmentés a vektorba
            QObject::connect(button, SIGNAL(clicked()), this, SLOT(setNumber())); // eseménykezelő kapcsolat
        }
    }
}

