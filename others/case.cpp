#include "iostream"
using namespace std;
#include "case.hpp"
#include "string"

// ����1�����Թ��캯�����������캯�������������ĵ���
void test()
{
    MyArray <int> array (5); // ����int��������Ϊ5������
    MyArray <int> array2(array);  // ���ÿ������캯�����������
    MyArray<int> array3(100); // ����int��������Ϊ100������
    array3 = array; // ��array3��������Ϊ5
}
// --------------------------------------------------------------------------
// ����2��int���͵������Ƿ������������ɾ��
void printInArray(MyArray<int> & arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}
void test2()
{
    MyArray<int> array4(10);
    // ͨ��ѭ���������м�������
    for (int i = 0; i < 6; i++)
    {
        array4.pushBack(4);
    }
    // ��ӡ����
    printInArray(array4);

    cout << array4.getCapcity() << endl;
    cout << array4.getSize() << endl;
    // βɾ��
    array4.popBack();

    cout << array4.getCapcity() << endl;
    cout << array4.getSize() << endl;
}
// --------------------------------------------------------------------------
// ����3���Զ������������������в�����ɾ��
class Person
{
public:
    Person(){}; // �޲ι����������������δ����ʵ��
    Person(string name, int age)  // �вι����ʵ�֣���ʼ��
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};
// ��ӡ�����Զ�����������Person������
void printInArray2(MyArray<Person> & arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i].m_name << arr[i].m_age << endl;
    }
}
void test3()
{
    MyArray<Person> array5(10);
    Person p1("�����", 30);
    Person p2("����", 20);
    Person p3("槼�", 18);
    Person p4("���Ѿ�", 15);
    Person p5("����", 24);

    array5.pushBack(p1);
    array5.pushBack(p2);
    array5.pushBack(p3);
    array5.pushBack(p4);
    array5.pushBack(p5);

    cout << array5.getCapcity() << endl;
    cout << array5.getSize() << endl;

    printInArray2(array5);

    array5.popBack();

    cout << array5.getCapcity() << endl;
    cout << array5.getSize() << endl;
    printInArray2(array5);
}
// --------------------------------------------------------------------------
int main()
{
    test();
    test2();
    test3();
}