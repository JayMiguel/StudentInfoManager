#include "queryform.h"
#include "ui_queryform.h"
#include <QDebug>

QueryForm::QueryForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryForm)
{
    ui->setupUi(this);
    connect(ui->m_okBtn, SIGNAL(clicked(bool)), this, SLOT(queryStuInfo()));
}

QueryForm::~QueryForm()
{
    delete ui;
}

int QueryForm::exec()
{
    ui->m_idLine->clear();
    return QDialog::exec();
}

void QueryForm::queryStuInfo()
{
    int id = ui->m_idLine->text().toInt();
    bool flag = false;
    for (Student& stu : studentList)
    {
        if (stu.m_id == id)
        {
            flag = true;
            sendStuInfo(stu);
            break;
        }
    }
    if (!flag)
    {
        QMessageBox::warning(this, tr("提示"), tr("暂无该学号的学生信息！"));
    }
    this->accept();
}
