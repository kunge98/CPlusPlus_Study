#include "iostream"
using namespace std;
#include "case.hpp"
#include "string"

// 测试1：测试构造函数、拷贝构造函数、析构函数的调用
void test()
{
    MyArray <int> array (5); // 定义int类型容量为5的数组
    MyArray <int> array2(array);  // 调用拷贝构造函数，传入对象
    MyArray<int> array3(100); // 定义int类型容量为100的数组
    array3 = array; // 将array3的容量改为5
}
// --------------------------------------------------------------------------
// 测试2：int类型的数组是否可以正常插入删除
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
    // 通过循环往数组中加入数据
    for (int i = 0; i < 6; i++)
    {
        array4.pushBack(4);
    }
    // 打印数组
    printInArray(array4);

    cout << array4.getCapcity() << endl;
    cout << array4.getSize() << endl;
    // 尾删法
    array4.popBack();

    cout << array4.getCapcity() << endl;
    cout << array4.getSize() << endl;
}
// --------------------------------------------------------------------------
// 测试3：自定义数据类型在数组中插入与删除
class Person
{
public:
    Person(){}; // 无参构造的声明，例子中未进行实现
    Person(string name, int age)  // 有参构造的实现，初始化
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};
// 打印的是自定义数据类型Person的数组
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
    Person p1("孙悟空", 30);
    Person p2("韩信", 20);
    Person p3("妲己", 18);
    Person p4("王昭君", 15);
    Person p5("赵云", 24);

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