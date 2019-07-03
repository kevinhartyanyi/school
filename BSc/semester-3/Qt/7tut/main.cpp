#include <QApplication>
#include <QtWidgets>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* window = new QWidget;
    window->setWindowTitle("My App");

    QGridLayout* layout = new QGridLayout;

    window->setLayout(layout);

    QLabel* labell = new QLabel("Name:");
    QLineEdit* txtName = new QLineEdit;

    QLabel* label2 = new QLabel("Name:");
    QLineEdit* txtName2 = new QLineEdit;

    layout->addWidget(labell,0,0);
    layout->addWidget(txtName,0,1);

    layout->addWidget(label2,1,0);
    layout->addWidget(txtName2,1,1);

    QPushButton* button = new QPushButton("OK");

    layout->addWidget(button,2,0,1,2);

    window->show();


    return a.exec();
}
