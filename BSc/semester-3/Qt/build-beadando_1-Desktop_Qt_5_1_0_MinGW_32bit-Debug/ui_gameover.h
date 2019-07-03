/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *turn_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *NewGameButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *ExitGameButton;

    void setupUi(QWidget *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QStringLiteral("GameOver"));
        GameOver->resize(400, 300);
        verticalLayout = new QVBoxLayout(GameOver);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(GameOver);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        turn_label = new QLabel(GameOver);
        turn_label->setObjectName(QStringLiteral("turn_label"));

        verticalLayout->addWidget(turn_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        NewGameButton = new QPushButton(GameOver);
        NewGameButton->setObjectName(QStringLiteral("NewGameButton"));

        horizontalLayout->addWidget(NewGameButton);

        horizontalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ExitGameButton = new QPushButton(GameOver);
        ExitGameButton->setObjectName(QStringLiteral("ExitGameButton"));

        horizontalLayout->addWidget(ExitGameButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QWidget *GameOver)
    {
        GameOver->setWindowTitle(QApplication::translate("GameOver", "Form", 0));
        label->setText(QApplication::translate("GameOver", "<html><head/><body><p><span style=\" font-size:28pt; color:#ff1d1d;\">Game Over</span></p></body></html>", 0));
        turn_label->setText(QApplication::translate("GameOver", "<html><head/><body><p><span style=\" font-size:20pt;\">Number of turns:</span></p></body></html>", 0));
        NewGameButton->setText(QApplication::translate("GameOver", "New Game", 0));
        ExitGameButton->setText(QApplication::translate("GameOver", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
