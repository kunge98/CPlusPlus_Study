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
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "�滻ǰ��" << endl;
    for_each(v.begin(), v.end(), myPrint());  // 20 30 20 40 50 10 20
    cout << endl;

    // �������е�20 �滻�� 2000
    cout << "�滻��" << endl;
    replace(v.begin(), v.end(), 20,2000);
    for_each(v.begin(), v.end(), myPrint());  // 2000 30 2000 40 50 10 2000
    cout << endl;
}
int main()
{
    test();
}