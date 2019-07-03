#ifndef VALAMI_H
#define VALAMI_H

#include <QObject>

class valami : public QObject
{
    Q_OBJECT
public:
    explicit valami(QObject *parent = nullptr);

signals:

public slots:
};

#endif // VALAMI_H