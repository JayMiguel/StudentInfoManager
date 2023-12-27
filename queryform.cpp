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

void QueryForm::queryStuInfo()
{
    QFile file("data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file for reading";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(',');

        if (data.size() == 5) {
            bool ok1, ok4;
            int id = data[0].toInt(&ok1);
            QString name = data[1];
            QString sex = data[2];
            int age = data[3].toInt(&ok4);
            QString className = data[4];

            if (ok1 && ok4) {
                Student student(id, name, sex, age, className);
                emit sendStuInfo(student);
            } else {
                qDebug() << "Error parsing data in line: " << line;
            }
        } else {
            qDebug() << "Invalid data format in line: " << line;
        }
    }

    file.close();
}
