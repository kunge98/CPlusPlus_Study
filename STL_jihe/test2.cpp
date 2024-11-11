#include <vector>
#include <algorithm>
#include "iostream"
using namespace std;
class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);  // 0 - 9
        v2.push_back(i+5);  // 5 - 14
    }

    vector<int> vTarget;

    vTarget.resize(v1.size()+v2.size());

    // 返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myPrint());  // 0 - 14
    cout << endl;
}
int main()
{
    test01();
}