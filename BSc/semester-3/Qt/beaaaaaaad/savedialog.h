#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QDialog>

namespace Ui {
class savedialog;
}

class savedialog : public QDialog
{
    Q_OBJECT

public:
    explicit savedialog(QWidget *parent = nullptr);
    ~savedialog();

private slots:
    void on_pushButton_clicked();
signals:
    void saveName(QString);

private:
    Ui::savedialog *ui;
};

#endif // SAVEDIALOG_H
