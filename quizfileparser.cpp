#include "quizfileparser.h"
#include "quizzawindow.h"

QuizFileParser::QuizFileParser(QObject *parent) : QObject(parent)
{

}

void QuizFileParser::checkValidity()
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
    }
    file.close();
    if(!line.contains("-QZCONF COMMENCE-"))
    {
        QMessageBox *dialog = new QMessageBox();
        dialog->setGeometry(100,100,100,100);
        dialog->setWindowTitle("No way hosay!");
        dialog->setText("This file is wrongly corrupted. Please check it and load again.");
        dialog->setIcon(QMessageBox::Warning);
        dialog->exec();
    }
}

