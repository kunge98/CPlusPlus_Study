#include <numeric>
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
    vector<int> v;
    v.resize(10);
    // 填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), myPrint());  // 输出10个100
    cout << endl;
}
int main()
{
    test();
}