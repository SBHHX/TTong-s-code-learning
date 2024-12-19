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
        cout << "ÐÕÃû£º" << this->m_Name << "\tÄêÁä£º" << this->m_Age << endl;
    }*/

    T1 m_Name;
    T2 m_Age;
};