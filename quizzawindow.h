#ifndef QUIZZAWINDOW_H
#define QUIZZAWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QMessageBox>

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
    void selectQuiz();
    bool checkIsValid();
    QString namesOfFiles;
    QString line;
    QFile *file;

private slots:
    void on_pushButton_clicked();

private:
    Ui::QuizzaWindow *ui;
};

#endif // QUIZZAWINDOW_H
