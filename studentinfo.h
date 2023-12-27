#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QDialog>
#include "student.h"
namespace Ui {
class StudentInfo;
}

class StudentInfo : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = nullptr);
    ~StudentInfo();

    void setOperation(int flag);
    void setStuInfo(Student& stu);

public slots:
    int exec();
    void onOkBtnClicked();

private:
    void addStuInfo();
    void modifyStuInfo();
    void deleteStuInfo();

private:
    Ui::StudentInfo *ui;
    int m_flag;
    Student m_stu;
};

#endif // STUDENTINFO_H
