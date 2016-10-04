#ifndef QUIZZAWINDOW_H
#define QUIZZAWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QStringList>

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
    QString namesOfFiles;
    QFile *file;
    void selectQuiz();

private:
    Ui::QuizzaWindow *ui;
};

#endif // QUIZZAWINDOW_H
