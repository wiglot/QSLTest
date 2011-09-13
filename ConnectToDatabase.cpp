#include "ConnectToDatabase.h"
#include <QtGui/QGridLayout>
#include <QtGui/QLineEdit>
#include <QtSql/QSqlDatabase>
#include <QtGui/QComboBox>
#include <QtGui/QMessageBox>
#include <QtSql/QSqlError>
#include <QtGui/QDialogButtonBox>
#include <QLabel>

ConnectToDatabase::ConnectToDatabase ( QWidget* parent, Qt::WindowFlags f ) : QDialog ( parent, f )
{
    QGridLayout * lay = new QGridLayout ( this );
    m_driver = new QComboBox ( this );
    foreach ( const QString driver, QSqlDatabase::drivers() )
    m_driver->addItem ( driver );
    lay->addWidget ( new QLabel ( "Driver", this ), 0,0 );
    lay->addWidget ( m_driver, 0,1 );
    m_name = new QLineEdit ( this );
    lay->addWidget ( new QLabel ( "Database", this ), 1,0 );
    lay->addWidget ( m_name, 1,1 );
    m_hostName = new QLineEdit ( QLatin1String ( "localhost" ),this );
    lay->addWidget ( new QLabel ( "Hostname", this ), 2,0 );
    lay->addWidget ( m_hostName, 2,1 );
    m_userName = new QLineEdit ( this );
    lay->addWidget ( new QLabel ( "Username", this ), 3,0 );
    lay->addWidget ( m_userName, 3,1 );
    m_password = new QLineEdit ( this );
    m_password->setEchoMode ( QLineEdit::Password );
    lay->addWidget ( new QLabel ( "Password", this ), 4,0 );
    lay->addWidget ( m_password, 4,1 );
    QDialogButtonBox *box = new QDialogButtonBox ( QDialogButtonBox::Ok|QDialogButtonBox::Cancel );
    connect ( box, SIGNAL ( accepted() ), SLOT ( accept() ) );
    connect ( box, SIGNAL ( rejected() ), SLOT ( reject() ) );
    lay->addWidget ( box, 5,1,1,2 );
    setLayout ( lay );
    QSqlDatabase db = QSqlDatabase::database ( QLatin1String ( "ASETestSql" ) );
    if ( db.isValid() ) {
        m_name->setText ( db.databaseName() );
        m_hostName->setText ( db.hostName() );
        m_userName->setText(db.userName());
        m_password->setText(db.password());
    }
}

void ConnectToDatabase::accept()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(m_driver->currentText(), QLatin1String("ASETestSql"));
    db.setDatabaseName(m_name->text());
    if (!m_userName->text().isEmpty()){
      db.setHostName(m_hostName->text());
      db.setUserName(m_userName->text());
      db.setPassword(m_password->text());
    }
    if (db.open()){
      QDialog::accept();
      return;
    }
    QMessageBox::critical(this, tr("Error connecting to DB"),
                          tr("Error connecting to database: %1").arg(db.lastError().text()),
                          QMessageBox::Close);
}

