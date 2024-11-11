#include <set>
#include "iostream"
using namespace std;
//查找和统计
void test()
{
    set<int> s1;
    //插入
    s1.insert(1);
    s1.insert(3);
    s1.insert(2);
    s1.insert(4);
    //查找
    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
    {
        cout << "找到了元素 ： " << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }
    //统计
    int num = s1.count(4);
    cout << "num = " << num << endl;
    cout << s1.size() << endl;
}
int main()
{
    test();
}