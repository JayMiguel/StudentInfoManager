#include "student.h"

Student::Student(int id, QString name, QString sex, int age, QString className)
{
    m_id = id;
    m_name = name;
    m_sex = sex;
    m_age = age;
    m_class = className;
}

Student& Student::operator=(Student& other)
{
    m_id = other.m_id;
    m_name = other.m_name;
    m_sex = other.m_sex;
    m_age = other.m_age;
    m_class = other.m_class;
    return *this;
}
