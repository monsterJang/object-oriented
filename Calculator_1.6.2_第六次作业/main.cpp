#include "Calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("calculatorIcon.ico"));
    Calculator *calc = new Calculator();
    calc->show();

    return app.exec();
}
