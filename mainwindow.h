#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queryform.h"
#include "studentinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showQuery();
    void showAdd();
    void showModify();
    void showDelete();

    void receiveStuInfo(Student stu);

private:
    Ui::MainWindow *ui;
    QueryForm *m_queryForm;
    StudentInfo* m_stuInfoDlg;

};
#endif // MAINWINDOW_H
