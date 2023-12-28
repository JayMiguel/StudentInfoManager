#ifndef QUERYFORM_H
#define QUERYFORM_H

#pragma execution_character_set("utf-8")
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include "student.h"

extern QVector<Student> studentList;

namespace Ui {
class QueryForm;
}

class QueryForm : public QDialog
{
    Q_OBJECT

public:
    explicit QueryForm(QWidget *parent = nullptr);
    ~QueryForm();

signals:
    void sendStuInfo(Student stu);

public slots:
    int exec() override;

private slots:
    void queryStuInfo();

private:
    Ui::QueryForm *ui;
};

#endif // QUERYFORM_H
