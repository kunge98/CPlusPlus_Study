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
void test()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    vector<int> v2;
    v2.resize(v1.size());  // 同样也需要提前开辟空间
    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), myPrint());  // 1 2 3 4 5 6 7 8 9 10
    cout << endl;
}
int main()
{
    test();
}