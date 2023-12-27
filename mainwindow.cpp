#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_queryForm = new QueryForm(this);
    m_stuInfoDlg = new StudentInfo(this);

    connect(ui->m_queryBtn, SIGNAL(clicked(bool)), this, SLOT(showQuery()));
    connect(ui->m_addBtn, SIGNAL(clicked(bool)), this, SLOT(showAdd()));
    connect(ui->m_modifyBtn, SIGNAL(clicked(bool)), this, SLOT(showModify()));
    connect(ui->m_deleteBtn, SIGNAL(clicked(bool)), this, SLOT(showDelete()));

    connect(m_queryForm, SIGNAL(sendStuInfo(Student)), this, SLOT(receiveStuInfo(Student)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showQuery()
{
    m_stuInfoDlg->setOperation(0);
    m_queryForm->exec();
}

void MainWindow::showAdd()
{
    m_stuInfoDlg->setOperation(1);
    m_stuInfoDlg->exec();
}

void MainWindow::showModify()
{
    m_stuInfoDlg->setOperation(2);
    m_queryForm->exec();
}

void MainWindow::showDelete()
{
    m_stuInfoDlg->setOperation(3);
    m_queryForm->exec();
}

void MainWindow::receiveStuInfo(Student stu)
{
    m_stuInfoDlg->setStuInfo(stu);
    m_stuInfoDlg->exec();
}
