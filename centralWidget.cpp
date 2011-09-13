#include "centralWidget.h"
#include <QGridLayout>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlDatabase>
#include <qsqlquerymodel.h>

CentralWidget::CentralWidget(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f)
{
    QGridLayout * lay = new QGridLayout(this);
    m_view = new QTableView(this);
    m_model = new QSqlQueryModel(this);
    m_view->setModel(m_model);
    lay->addWidget(m_view, 0,0, 1, 2);
    lay->setRowStretch(0,1);

    m_sql = new QLineEdit(this);
    lay->addWidget(m_sql, 1,0);

    m_execute = new QPushButton(tr("exec"), this);
    lay->addWidget(m_execute, 1,1);
    connect (m_execute,SIGNAL(clicked(bool)), SLOT(executeQuery(bool)));
    setLayout(lay);
    setEnabled(false);
}


void CentralWidget::setConnected ( const bool& v)
{
    setEnabled(v);
}

void CentralWidget::executeQuery ( bool )
{
    QSqlDatabase db = QSqlDatabase::database(QLatin1String("ASETestSql"));
    if (db.isValid() || db.isOpen()){
        m_model->setQuery(m_sql->text(), db);
    }
}

#include "centralWidget.moc"
