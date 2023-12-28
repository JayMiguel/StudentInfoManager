#include "studentinfo.h"
#include "student.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
    connect(ui->m_okBtn, SIGNAL(clicked(bool)), this, SLOT(onOkBtnClicked()));
    connect(ui->m_cancelBtn, SIGNAL(clicked(bool)), this, SLOT(onCancelBtnClicked()));
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
        ui->m_nameLine->setText(m_stu.m_name.toUtf8());
        ui->m_sexLine->setText(m_stu.m_sex.toUtf8());
        ui->m_ageLine->setText(QString::number(m_stu.m_age));
        ui->m_classLine->setText(m_stu.m_class.toUtf8());
    }
    ui->m_idLine->setDisabled(m_flag == 0 || m_flag == 2 || m_flag == 3);
    ui->m_nameLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_sexLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_ageLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_classLine->setDisabled(m_flag == 0 || m_flag == 3);
    ui->m_cancelBtn->setVisible(m_flag != 0);

    return QDialog::exec();
}

void StudentInfo::setStuInfo(Student& stu)
{
    m_stu = stu;
}

void StudentInfo::onCancelBtnClicked()
{
    this->reject();
}

void StudentInfo::onOkBtnClicked()
{
    if (m_flag == 0)
    {
        this->accept();
    }
    else if (m_flag == 1)
    {
        
        this->addStuInfo();
    }
    else if (m_flag == 2)
    {
        m_stu.m_id = ui->m_idLine->text().toInt();
        m_stu.m_name = ui->m_nameLine->text();
        m_stu.m_sex = ui->m_sexLine->text();
        m_stu.m_age = ui->m_ageLine->text().toInt();
        m_stu.m_class = ui->m_classLine->text();
        this->modifyStuInfo();
    }
    else
    {
        this->deleteStuInfo();
    }
}

void StudentInfo::addStuInfo()
{
    m_stu.m_id = ui->m_idLine->text().toInt();
    m_stu.m_name = ui->m_nameLine->text();
    m_stu.m_sex = ui->m_sexLine->text();
    m_stu.m_age = ui->m_ageLine->text().toInt();
    m_stu.m_class = ui->m_classLine->text();

    studentList.push_back(m_stu);

    QFile file("data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file for writing";
        return;
    }

    file.resize(0);

    QTextStream out(&file);
    out.setCodec("UTF-8");
    for (Student stu : studentList)
    {
        out << stu.m_id << ","
            << stu.m_name << ","
            << stu.m_sex << ","
            << stu.m_age << ","
            << stu.m_class << "\n";
    }

    file.close();

    QMessageBox::information(this, tr("提示"), tr("新增学生信息成功！"));
    this->accept();
}

void StudentInfo::modifyStuInfo()
{
    for (Student& stu : studentList)
    {
        if (stu.m_id == ui->m_idLine->text().toInt())
        {
            stu.m_name = ui->m_nameLine->text();
            stu.m_sex = ui->m_sexLine->text();
            stu.m_age = ui->m_ageLine->text().toInt();
            stu.m_class = ui->m_classLine->text();
            break;
        }
    }

    QFile file("data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file for writing";
        return;
    }

    file.resize(0);

    QTextStream out(&file);
    out.setCodec("UTF-8");
    for (Student stu : studentList)
    {
        out << stu.m_id << ","
            << stu.m_name << ","
            << stu.m_sex << ","
            << stu.m_age << ","
            << stu.m_class << "\n";
    }

    file.close();

    QMessageBox::information(this, tr("提示"), tr("修改学生信息成功！"));
    this->accept();
}

void StudentInfo::deleteStuInfo()
{
    int idx = -1;
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i].m_id == ui->m_idLine->text().toInt())
        {
            idx = i;
            break;
        }
    }
    studentList.removeAt(idx);

    QFile file("data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file for writing";
        return;
    }

    file.resize(0);

    QTextStream out(&file);
    out.setCodec("UTF-8");
    for (Student stu : studentList)
    {
        out << stu.m_id << ","
            << stu.m_name << ","
            << stu.m_sex << ","
            << stu.m_age << ","
            << stu.m_class << "\n";
    }

    file.close();

    QMessageBox::information(this, tr("提示"), tr("删除学生信息成功！"));
    this->accept();
}
