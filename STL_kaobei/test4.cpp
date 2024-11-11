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
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+100);
    }

    cout << "交换前： " << endl;
    for_each(v1.begin(), v1.end(), myPrint());  // 0 1 2 3 4 5 6 7 8 9
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint());  // 100 - 109
    cout << endl;

    cout << "交换后： " << endl;
    swap(v1, v2);
    for_each(v1.begin(), v1.end(), myPrint());  // 100 - 109
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint());  // 0 1 2 3 4 5 6 7 8 9
    cout << endl;
}
int main()
{
    test();
}