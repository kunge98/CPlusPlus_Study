#include <set>
#include "iostream"
using namespace std;
//���Һ�ͳ��
void test()
{
    set<int> s1;
    //����
    s1.insert(1);
    s1.insert(3);
    s1.insert(2);
    s1.insert(4);
    //����
    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
    {
        cout << "�ҵ���Ԫ�� �� " << *pos << endl;
    }
    else
    {
        cout << "δ�ҵ�Ԫ��" << endl;
    }
    //ͳ��
    int num = s1.count(4);
    cout << "num = " << num << endl;
    cout << s1.size() << endl;
}
int main()
{
    test();
}