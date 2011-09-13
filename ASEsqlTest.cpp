#include "ASEsqlTest.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include "ConnectToDatabase.h"
#include "centralWidget.h"


ASEsqlTest::ASEsqlTest()
{
    CentralWidget *l = new CentralWidget();
    setCentralWidget( l );

    QAction* a = new QAction(this);
    a->setText( "Quit" );
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( a );
    a = menuBar()->addAction("Connect");
    connect (a, SIGNAL(triggered(bool)), SLOT(connecteDB(bool)));
    connect (this, SIGNAL(connected(bool)), l, SLOT(setConnected(bool)));
}

ASEsqlTest::~ASEsqlTest()
{}

void ASEsqlTest::connecteDB(bool )
{
  ConnectToDatabase c(this);
  c.exec()==QDialog::Accepted?
         emit connected(true):
         emit connected(false);
}



#include "ASEsqlTest.moc"
