#ifndef QUIZZAWINDOW_H
#define QUIZZAWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include <QFileDialog>

namespace Ui {
class QuizzaWindow;
}

class QuizzaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuizzaWindow(QWidget *parent = 0);
    ~QuizzaWindow();
    QString quiztitle;
    QFileDialog *filename;

private:
    Ui::QuizzaWindow *ui;
};

#endif // QUIZZAWINDOW_H
