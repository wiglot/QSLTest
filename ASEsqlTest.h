#ifndef ASEsqlTest_H
#define ASEsqlTest_H

#include <QtGui/QMainWindow>

class ASEsqlTest : public QMainWindow
{
Q_OBJECT
public:
    ASEsqlTest();
    virtual ~ASEsqlTest();
public slots:
    void connecteDB(bool);
signals:
    void connected(bool);
};

#endif // ASEsqlTest_H
