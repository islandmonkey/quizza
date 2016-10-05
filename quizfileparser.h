#ifndef QUIZFILEPARSER_H
#define QUIZFILEPARSER_H

#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>


class QuizFileParser : public QObject
{
    Q_OBJECT
public:
    explicit QuizFileParser(QObject *parent = 0);
    void checkValidity();
    QString namesOfFiles;
    QFileDialog *filename;
    QString line;
    QFile *file;

signals:

public slots:
};

#endif // QUIZFILEPARSER_H
