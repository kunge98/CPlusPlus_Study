#include <algorithm>
#include <vector>
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
class ReplaceGreater30
{
public:
    bool operator()(int val)
    {
        return val >= 30;
    }
};
void test()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), myPrint());  // 20 30 20 40 50 10 20
    cout << endl;

    //将容器中大于等于的30 替换成 3000
    cout << "替换后：" << endl;
    replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
    for_each(v.begin(), v.end(), myPrint());  // 20 3000 20 3000 3000 10 20
    cout << endl;
}
int main()
{
    test();
}