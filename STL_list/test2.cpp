#include <list>
#include "iostream"
using namespace std;
//���ݴ�ȡ
void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //cout << L1.at(0) << endl;//���� ��֧��at��������
    //cout << L1[0] << endl; //����  ��֧��[]��ʽ��������
    cout << "��һ��Ԫ��Ϊ�� " << L1.front() << endl;
    cout << "���һ��Ԫ��Ϊ�� " << L1.back() << endl;

    //list�����ĵ�������˫�����������֧���������
    list<int>::iterator it = L1.begin();
    list<int>::iterator it2 = L1.end();
    //it = it + 1;//���󣬲�������Ծ���ʣ���ʹ��+1
    cout << *it << " " << *it2 << endl;
}
int main()
{
    test01();
}