#ifndef QUERYFORM_H
#define QUERYFORM_H

#include <QDialog>
#include "student.h"
#include <QFile>

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

private slots:
    void queryStuInfo();

private:
    Ui::QueryForm *ui;
};

#endif // QUERYFORM_H
