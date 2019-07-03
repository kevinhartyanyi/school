#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Table");
    setMinimumSize(500,500);

    table = new QGridLayout(this);
    verti = new QVBoxLayout(this);

    timenumb = 0;
    timee.setText("Time: 0");
    timee.setEnabled(false);


    verti->addWidget(&timee);
    verti->addWidget(&pausebutton);
    verti->addLayout(table);


    timer = new QTimer(this);

    center = new QWidget(this);

    center->setLayout(verti);


    connect(timer,SIGNAL(timeout()), this, SLOT(changeTime()));

    connect(&pausebutton, SIGNAL(clicked()), this, SLOT(Pause()));


    setCentralWidget(center);



    AskSize();

    srand(time(NULL));

    Table();

    timer->start(1000);





}

int MainWindow::Number()
{

    return rand() % 4;
}

void MainWindow::Table()
{
    qDebug() << size;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            QPushButton* p = new QPushButton(this);
            p->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
            p->setCheckable(false);
            int n = Number();
            p->setText(QString::number(n));
            switch (n) {
            case 0:
                p->setStyleSheet(white);
                break;
            case 1:
                p->setStyleSheet(black);
                break;
            case 2:
                p->setStyleSheet(red);
                break;
            case 3:
                p->setStyleSheet(blue);
                break;

            }

            table->addWidget(p,i,j);
        }
    }
}

void MainWindow::AskSize()
{
    Ask a(this);
    connect(&a, SIGNAL(size(int)), this, SLOT(set(int)));
    a.exec();
}

void MainWindow::set(int a)
{
    qDebug() << "Call";
    size = a;
}

void MainWindow::Pause()
{
    timer->blockSignals(true);

    QMessageBox m;
    m.setText("Paused");
    m.setDefaultButton(QMessageBox::Yes);////////////
    m.exec();

    timer->blockSignals(false);
}
void MainWindow::changeTime()
{
    timee.setText("Time: " + QString::number(++timenumb));
}

MainWindow::~MainWindow()
{

    delete ui;
}
