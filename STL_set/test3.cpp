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
//插入和删除
void test()
{
    set<int> s1;
    //插入
    s1.insert(1);
    s1.insert(3);
    s1.insert(2);
    s1.insert(4);
    printSet(s1);  // 1 2 3 4

    //删除
    s1.erase(s1.begin());
    printSet(s1);  // 2 3 4

    s1.erase(3);
    printSet(s1);  // 2 4

    //清空
    //s1.erase(s1.begin(), s1.end());
    s1.clear();
    printSet(s1);  // 全部清空
}
int main()
{
    test();
}