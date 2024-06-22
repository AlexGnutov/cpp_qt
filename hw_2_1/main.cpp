#include <QCoreApplication>

#include <QtNetwork/QTcpServer>
#include <QtSql/QSqlDatabase>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto tcp = new QTcpServer();

    auto db = new QSqlDatabase();

    return 0; // a.exec();
}
