#include <algorithm>
#include <vector>
using namespace std;
#include "iostream"
void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(7);
    v.push_back(7);
    v.push_back(3);

    //���������ظ�Ԫ��
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end()) {
        cout << "�Ҳ���!" << endl;
    }
    else {
        cout << "�ҵ������ظ�Ԫ��Ϊ:" << *it << endl;
    }
}
int main()
{
    test01();
}