#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//STL - 常用算法

//find if

//功能描述:
//按条件查找元素

//函数原型 :
//find if (iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
//_Pred 函数或者谓词(返回bool类型的仿函数)

class Greator1
{
public:
	bool operator()(int val)
	{
		return val > 5;

		/*在这个Greator1类中不是默认返回true
		在Greator1类的operator()函数中，返回值是由val > 5这个条件决定的。只有当传入的val大于 5 时，才会返回true；
		否则返回false。
		例如，如果调用Greator1的对象，传入值为 3，像这样Greator1 g; g(3); ，此时返回值是false，因为 3 不大于 5。*/

		//下面的写法好理解一点
		/*
		if (val > 5)
		{
			return true;
		}
		else
		{
			return false;
		}
		*/
	}
};

//查找 内置数据类型
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}	
	
	vector<int>::iterator it = find_if(v.begin(), v.end(), Greator1());
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
		cout << *it << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//若要比较非内置数据类型，需要重载比较运算符
	bool operator==(const Person& p)
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
		
	}

	/*bool operator>(const Person& p)
	{
		return this->m_Age > p.m_Age;
	}*/

	/*重载>操作符通常用于定义两个自定义对象之间的大小关系。例如，如果要对Person对象进行排序（如使用sort函数），并且排序依
	据是年龄大小，那么就需要重载>操作符来告诉sort函数如何比较两个Person对象的大小。
    但在find_if的场景中，只是在逐个检查Person对象是否满足特定条件（这里是年龄大于1），而不是比较两个Person对象的大小关系，
	所以不需要重载>操作符。
    综上所述，在使用find_if查找自定义数据类型时，由于只关注单个对象是否满足特定条件，而不是对象之间的大小比较，因此不需要
	重载>操作符。*/

	string m_Name;
	int m_Age;
};

class Greater2
{
public:
	bool operator()(Person&p)
	{
		return p.m_Age > 1;	
	}

	/*bool operator()(Person& p1，Person& p2)
	{
		return p1 > p2;

	}*/
	//当将Greater2类的operator()函数定义为接受两个Person对象作为参数，并在函数内部进行p1 > p2这样的比较操作时，
	//就需要对Person类的>运算符进行重载。
};

//查找 自定义数据类型
void test02()
{
	Person p1("A", 1);
	Person p2("B", 2);
	Person p3("C", 3);
	Person p4("D", 4);
	Person p5("E", 5);

	vector<Person>v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	Person pp("A", 1);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater2());
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
		cout << it->m_Name << "  " << it->m_Age << endl;
	}
}

int main()
{
	test01();
	cout << "----------------------------------" << endl;
	test02();

	return 0;
}



//这是19.41推送的
//这是19.47
//20.06
//20.08