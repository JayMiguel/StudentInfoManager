#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student() = default;
    Student(int id, QString name, QString sex, int age, QString className);

    Student& operator=(Student& other);

    int m_id;
    QString m_name;
    QString m_sex;
    int m_age;
    QString m_class;
};

#endif // STUDENT_H
