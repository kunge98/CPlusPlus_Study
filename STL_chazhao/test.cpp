#include <algorithm>
#include <vector>
#include <string>
#include "iostream"
using namespace std;
void test01()
{
    vector<int> v;
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }\
    // �����������Ƿ��� 5 ���Ԫ��
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it == v.end())
    {
        cout << "û���ҵ�!" << endl;
    }
    else
    {
        cout << "�ҵ�:" << *it << endl;
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
    // �����Զ�����������ʱ��Ҫ ����==
    bool operator==(const Person& p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
    string m_Name;
    int m_Age;
};

void test02()
{
    vector<Person> v;

    // ��������
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person p5("ddd", 40);
    vector<Person>::iterator it = find(v.begin(), v.end(), p5);
    if (it == v.end())
    {
        cout << "û���ҵ�!" << endl;
    }
    else
    {
        cout << "�ҵ�����:" << it->m_Name << " ����: " << (*it).m_Age << endl;
    }
}
int main()
{
    test01();
    test02();
}