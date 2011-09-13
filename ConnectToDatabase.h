#ifndef CONNECTTODATABASE_H
#define CONNECTTODATABASE_H

#include <QtGui/QDialog>

class QLineEdit;

class ConnectToDatabase : public QDialog
{

public:
    explicit ConnectToDatabase(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual void accept();
private:
    QLineEdit* m_name;
    class QComboBox* m_driver;
    QLineEdit* m_hostName;
    QLineEdit* m_userName;
    QLineEdit* m_password;
};

#endif // CONNECTTODATABASE_H
