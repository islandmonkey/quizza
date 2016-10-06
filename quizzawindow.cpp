#include "quizzawindow.h"
#include "ui_quizzawindow.h"


QuizzaWindow::QuizzaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuizzaWindow)
{
    filename = new QFileDialog;
    ui->setupUi(this);
    quiztitle = "Welcome to Quizza! Select a quiz.";
    ui->textBrowser->setText(quiztitle);
    ui->textBrowser->setFontPointSize(18);
    ui->textBrowser->setAlignment(Qt::AlignCenter);
}

QuizzaWindow::~QuizzaWindow()
{
    delete ui;
    delete filename;
}

void QuizzaWindow::on_pushButton_clicked()
{
    selectQuiz();
}

void QuizzaWindow::selectQuiz()
{
    filename->setFileMode(QFileDialog::AnyFile);
    filename->setNameFilter(tr("Quizza config files (*.qzconf)"));
    filename->setViewMode(QFileDialog::List);
    filename->exec();
}

bool QuizzaWindow::checkIsValid()
{
    namesOfFiles = filename->selectedFiles().join(".").at(0);
    QFile file(namesOfFiles);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if(!fields.contains("-QZCONF COMMENCE-"))
        {
            QMessageBox *dialog = new QMessageBox();
            dialog->setGeometry(100,100,100,100);
            dialog->setWindowTitle("No way hosay!");
            dialog->setText("This file is corrupted. Please check it and load again.");
            dialog->setIcon(QMessageBox::Critical);
            dialog->exec();
            return false;
        }
    }
    file.close();
    return true;
}
