#include <list>
#include "iostream"
using namespace std;
void printList(const list<int>& L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//插入和删除
void test()
{
    list<int> L;
    //尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    //头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L); // 300 200 100 10 20 30

    //尾删
    L.pop_back();
    printList(L); // 300 200 100 10 20

    //头删
    L.pop_front();
    printList(L); // 200 100 10 20

    //插入
    list<int>::iterator it = L.begin();
    L.insert(++it, 66);  // 从第二个位置开始插入数据
    printList(L);  // 200 66 100 10 20

    //删除
    it = L.begin();
    L.erase(++it); // 从第二个位置开始插入数据
    printList(L);   // 200 100 10 20

    //添加
    L.push_back(10000);
    L.push_back(10000);
    L.push_back(10000);
    printList(L);  // 200 100 10 20 10000 10000 10000
    L.remove(10000);  // 移除容器中所有相同数值的元素
    printList(L);  // 200 100 10 20

    //清空
    L.clear();
    printList(L);  // 清空所有内容
}
int main()
{
    test();
}