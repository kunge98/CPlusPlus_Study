#include <algorithm>
#include <vector>
#include "iostream"
using namespace std;
void test()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //���ֲ���
    bool ret = binary_search(v.begin(), v.end(),2);
    if (ret)
    {
        cout << "�ҵ���" << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}
int main()
{
    test();
}