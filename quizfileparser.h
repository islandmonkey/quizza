#ifndef QUIZFILEPARSER_H
#define QUIZFILEPARSER_H

#include <QObject>
#include <QMessageBox>

class QuizFileParser : public QObject
{
    Q_OBJECT
public:
    explicit QuizFileParser(QObject *parent = 0);
    void checkValidity();

signals:

public slots:
};

#endif // QUIZFILEPARSER_H
