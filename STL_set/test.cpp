#include <set>
#include "iostream"
using namespace std;
void printSet(set<int> & s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//构造和赋值
void test()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1); // 10 20 30 40

    //拷贝构造
    set<int>s2(s1);
    printSet(s2); // 10 20 30 40

    //赋值
    set<int>s3;
    s3 = s2;
    printSet(s3); // 10 20 30 40
}
int main()
{
    test();
}