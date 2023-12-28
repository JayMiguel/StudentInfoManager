#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <QApplication>

QVector<Student> studentList = {};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("data.txt");
    if (!file.exists())
    {
        if (file.open(QIODevice::WriteOnly))
        {
            qDebug() << "File created.";
        }
    }
    else
    {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Could not open the file for writing";
            return -1;
        }

        QTextStream in(&file);
        in.seek(0);
        in.setCodec("UTF-8");
        // Read all lines from the file
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList data = line.split(',');

            if (data.size() == 5) {
                int id = data[0].toInt();
                QString name = data[1];
                QString sex = data[2];
                int age = data[3].toInt();
                QString className = data[4];

                Student student(id, name, sex, age, className);
                studentList.push_back(student);
            }
            else {
                qDebug() << "Invalid data format in line: " << line;
            }
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}
