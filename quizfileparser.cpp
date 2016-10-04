#include "quizfileparser.h"
#include "quizzawindow.h"

QuizFileParser::QuizFileParser(QObject *parent) : QObject(parent)
{

}

void QuizFileParser::checkValidity(QString *references)
{
    references = QuizzaWindow.file;
    if(!references->contains("-QZCONF COMMENCE-"))
    {
        QMessageBox dialog;
        dialog.setGeometry(100,100,100,100);
        dialog.setWindowTitle("No way hosay!");
        dialog.setText("This file is wrongly corrupted. Please check it and load again.");
        dialog.setIcon(QMessageBox::Warning);
        dialog.activateWindow();
        return;
    }
}

