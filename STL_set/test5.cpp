#include <set>
#include "iostream"
using namespace std;
void test()
{
    set<int> s;
    pair<set<int>::iterator, bool>  ret = s.insert(10);
    if (ret.second)
    {
        cout << "��һ�β���ɹ�!" << endl;
    }
    else
    {
        cout << "��һ�β���ʧ��!" << endl;
    }

    ret = s.insert(10);
    if (ret.second)
    {
        cout << "�ڶ��β���ɹ�!" << endl;
    }
    else
    {
        cout << "�ڶ��β���ʧ��!" << endl;
    }
    //multiset
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    test();
}