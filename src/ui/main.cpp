#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList keyList = QStyleFactory::keys();
    for(int i = 0; i < keyList.length(); i++)
    {
        qDebug(keyList.at(i).toUtf8());
    }


    MainWindow w;
    w.show();
#if defined (Q_OS_WIN32)
    // windowsvista Windows Fusion
    a.setStyle(QStyleFactory::create("Fusion"));
    qDebug("system run at window");
#elif defined (Q_OS_MACX)
    // macintosh Windows Fusion
    a.setStyle(QStyleFactory::create("macintosh"));
    qDebug("system run at macx");
#endif
    return a.exec();
}
