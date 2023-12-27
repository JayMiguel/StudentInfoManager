#include "studentinfo.h"
#include "student.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
    connect(ui->m_okBtn, SIGNAL(clicked(bool)), this, SLOT(onOkBtnClicked()));
}

StudentInfo::~StudentInfo()
{
    delete ui;
}

void StudentInfo::setOperation(int flag)
{
    m_flag = flag;
}

int StudentInfo::exec()
{
    if (m_flag == 1)
    {
        ui->m_idLine->clear();
        ui->m_nameLine->clear();
        ui->m_sexLine->clear();
        ui->m_ageLine->clear();
        ui->m_classLine->clear();
    }
    else
    {
        ui->m_idLine->setText(QString::number(m_stu.m_id));
        ui->m_nameLine->setText(m_stu.m_name);
        ui->m_sexLine->setText(m_stu.m_sex);
        ui->m_ageLine->setText(QString::number(m_stu.m_age));
        ui->m_classLine->setText(m_stu.m_class);
    }
    ui->m_idLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_nameLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_sexLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_ageLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_classLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_cancelBtn->setVisible(m_flag != 1);

    return QDialog::exec();
}

void StudentInfo::setStuInfo(Student& stu)
{
    m_stu = stu;
}

void StudentInfo::onOkBtnClicked()
{
    if (m_flag == 0)
    {
        this->reject();
    }
    else if (m_flag == 1)
    {
        this->addStuInfo();
    }
    else if (m_flag == 2)
    {
        this->modifyStuInfo();
    }
    else
    {
        this->deleteStuInfo();
    }
}

void StudentInfo::addStuInfo()
{

}

void StudentInfo::modifyStuInfo()
{

}

void StudentInfo::deleteStuInfo()
{

}
