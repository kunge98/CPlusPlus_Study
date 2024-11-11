#include <algorithm>
#include <vector>
#include "iostream"
using namespace std;
void myPrint(int val)
{
    cout << val << " ";
}
void test()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    // sort默认从小到大排序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);  // 10 20 30 40 50
    cout << endl;

    // 从大到小排序
    sort(v.begin(), v.end(), greater<int>());  // 使用内置的关系仿函数
    for_each(v.begin(), v.end(), myPrint);  // 50 40 30 20 10
    cout << endl;
}
int main()
{
    test();
}