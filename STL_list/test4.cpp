#include "iostream"
#include "list"
using namespace std;
class Person
{
public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->heght = height;
    };
    string name;
    int age;
    int heght;
};
bool ComparePersonAge(Person & p1, Person & p2)
{
    if (p1.age == p2.age)
    {
        return p1.heght > p2.heght;  // 按照身高进行降序
    } else
    {
        p1.age < p2.age; // 按照年龄进行升序
    }
}
void test()
{
    list<Person> l;
    Person p1("刘备", 35 , 175);
    Person p2("曹操", 45 , 180);
    Person p3("孙权", 40 , 170);
    Person p4("赵云", 25 , 190);
    Person p5("张飞", 35 , 160);
    Person p6("关羽", 35 , 200);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    for (list<Person>::iterator i = l.begin(); i != l.end() ; i++)
    {
        cout << (*i).name << " " << i->age << " " << (*i).heght << endl;
    }
    l.sort(ComparePersonAge); // 按照自己的算法进行排序，年龄进行升序，相同时按照身高进行降序

    for (list<Person>::iterator i = l.begin(); i != l.end() ; i++)
    {
        cout << (*i).name << " " << i->age << " " << (*i).heght << endl;
    }
}
int main()
{
    test();
}