#include "quizzawindow.h"
#include "ui_quizzawindow.h"


QuizzaWindow::QuizzaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuizzaWindow)
{
    filename = new QFileDialog;
    ui->setupUi(this);
    quiztitle = "Welcome to Quizza! Select a quiz.";
    ui->textEdit->setText(quiztitle);
}

QuizzaWindow::~QuizzaWindow()
{
    delete ui;
    delete filename;
}

void QuizzaWindow::selectQuiz()
{
    if(ui->pushButton->isChecked())
    {
        filename->setFileMode(QFileDialog::AnyFile);
        filename->setNameFilter(tr("Quizza config files (*.qzconf)"));
        filename->setViewMode(QFileDialog::List);
        filename->exec();
    }
}
