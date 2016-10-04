#include "quizzawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication quizza(argc, argv);
    QuizzaWindow window;
    window.show();

    return quizza.exec();
}
