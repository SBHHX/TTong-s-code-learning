#include"Person.h"

//���캯������ʵ��
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}

//���ﺯ������ʵ��
template<class T1, class T2>
void Person<T1, T2>::ShowPerson()
{
    cout << "������" << this->m_Name << "\t���䣺" << this->m_Age << endl;
}