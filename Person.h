#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    /*{
        this->m_Name = name;
        this->m_Age = age;
    }*/
    void ShowPerson();
    /*{
        cout << "������" << this->m_Name << "\t���䣺" << this->m_Age << endl;
    }*/

    T1 m_Name;
    T2 m_Age;
};