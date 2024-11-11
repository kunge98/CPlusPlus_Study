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
void test()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);  // 0 - 9
        v2.push_back(i+5);  // 5 - 14
    }

    vector<int> vTarget;
    vector<int> vTarget2;

    vTarget.resize(max(v1.size(), v2.size()));
    vTarget2.resize(max(v1.size(), v2.size()));

    // 返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget2.begin());

    for_each(vTarget.begin(), itEnd, myPrint());  // 0 1 2 3 4
    cout << endl;
    for_each(vTarget2.begin(), itEnd2, myPrint());  // 10 - 14
    cout << endl;
}
int main()
{
    test();
}