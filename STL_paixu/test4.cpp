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
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "��תǰ�� " << endl;
    for_each(v.begin(), v.end(), myPrint());  // 10 30 50 20 40
    cout << endl;

    cout << "��ת�� " << endl;

    reverse(++v.begin(), --v.end());  // ָ����ת�ķ�Χ
    for_each(v.begin(), v.end(), myPrint());  // 10 20 50 30 40
    cout << endl;
}
int main()
{
    test();
}