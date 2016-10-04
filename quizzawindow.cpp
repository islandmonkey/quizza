#include "quizzawindow.h"
#include "ui_quizzawindow.h"
#include "quizfileparser.h"

QuizzaWindow::QuizzaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuizzaWindow)
{
    ui->setupUi(this);
    quiztitle = "Welcome to Quizza! Select a quiz.";
    ui->textEdit->setText(quiztitle);
}

QuizzaWindow::~QuizzaWindow()
{
    delete ui;
}

void QuizzaWindow::selectQuiz()
{
    if(ui->pushButton->isChecked()) {
        filename->setFileMode(QFileDialog::AnyFile);
        filename->setNameFilter(tr("Quizza config files (*.qzconf)"));
        filename->setViewMode(QFileDialog::List);
        if(filename->exec())
        {
            namesOfFiles = filename->selectedFiles();
        }
        file->fileName() = namesOfFiles;
        file->open(1,QIODevice::ReadWrite);
        QuizFileParser::checkValidity();
    }
    



}
