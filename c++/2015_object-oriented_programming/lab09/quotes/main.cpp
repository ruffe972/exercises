#include "quoteswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QuotesWindow window;
    window.show();
    return app.exec();
}
