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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_gameOver
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QDialog *gameOver)
    {
        if (gameOver->objectName().isEmpty())
            gameOver->setObjectName(QStringLiteral("gameOver"));
        gameOver->resize(400, 300);
        verticalLayout = new QVBoxLayout(gameOver);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(gameOver);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(gameOver);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(gameOver);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        pushButton_2 = new QPushButton(gameOver);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(gameOver);

        QMetaObject::connectSlotsByName(gameOver);
    } // setupUi

    void retranslateUi(QDialog *gameOver)
    {
        gameOver->setWindowTitle(QApplication::translate("gameOver", "Dialog", 0));
        label_2->setText(QApplication::translate("gameOver", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">TextLabel</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("gameOver", "New Game", 0));
        label->setText(QApplication::translate("gameOver", "<html><head/><body><p><span style=\" font-size:26pt; color:#ff0000;\">Game Over</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("gameOver", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class gameOver: public Ui_gameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
