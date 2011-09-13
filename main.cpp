#include <QtGui/QApplication>
#include "ASEsqlTest.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ASEsqlTest foo;
    foo.show();
    return app.exec();
}
