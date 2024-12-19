#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//STL - �����㷨

//find if

//��������:
//����������Ԫ��

//����ԭ�� :
//find if (iterator beg, iterator end, _Pred);
// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
// beg ��ʼ������
// end ����������
//_Pred ��������ν��(����bool���͵ķº���)

class Greator1
{
public:
	bool operator()(int val)
	{
		return val > 5;

		/*�����Greator1���в���Ĭ�Ϸ���true
		��Greator1���operator()�����У�����ֵ����val > 5������������ġ�ֻ�е������val���� 5 ʱ���Ż᷵��true��
		���򷵻�false��
		���磬�������Greator1�Ķ��󣬴���ֵΪ 3��������Greator1 g; g(3); ����ʱ����ֵ��false����Ϊ 3 ������ 5��*/

		//�����д�������һ��
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

//���� ������������
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
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
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

	//��Ҫ�ȽϷ������������ͣ���Ҫ���رȽ������
	bool operator==(const Person& p)
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
		
	}

	/*bool operator>(const Person& p)
	{
		return this->m_Age > p.m_Age;
	}*/

	/*����>������ͨ�����ڶ��������Զ������֮��Ĵ�С��ϵ�����磬���Ҫ��Person�������������ʹ��sort������������������
	���������С����ô����Ҫ����>������������sort������αȽ�����Person����Ĵ�С��
    ����find_if�ĳ����У�ֻ����������Person�����Ƿ������ض��������������������1���������ǱȽ�����Person����Ĵ�С��ϵ��
	���Բ���Ҫ����>��������
    ������������ʹ��find_if�����Զ�����������ʱ������ֻ��ע���������Ƿ������ض������������Ƕ���֮��Ĵ�С�Ƚϣ���˲���Ҫ
	����>��������*/

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

	/*bool operator()(Person& p1��Person& p2)
	{
		return p1 > p2;

	}*/
	//����Greater2���operator()��������Ϊ��������Person������Ϊ���������ں����ڲ�����p1 > p2�����ıȽϲ���ʱ��
	//����Ҫ��Person���>������������ء�
};

//���� �Զ�����������
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
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
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



//����19.41���͵�
//����19.47
//20.06
//20.08