#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtGui/QWidget>

class QSqlQueryModel;
class QLineEdit;
class QPushButton;
class QTableView;

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);
public slots:
    void setConnected(const bool &);
void executeQuery ( bool );

private:
    QLineEdit* m_sql;
    QPushButton* m_execute;
    QTableView* m_view;
    QSqlQueryModel* m_model;


};

#endif // CENTRALWIDGET_H
