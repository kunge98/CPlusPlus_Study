#include "iostream"
#include "list"
using namespace std;
void printList(const list<int>& L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
bool myCompare(int val1, int val2)
{
    return val1 > val2;
}
// 反转和排序
void test()
{
    list<int> L;
    L.push_back(9);
    L.push_back(3);
    L.push_back(2);
    L.push_back(7);
    printList(L);  // 9 3 2 7

    //反转容器的元素
    L.reverse();
    printList(L); // 7 2 3 9

    //排序
    L.sort(); //默认的排序规则 从小到大
    printList(L);  // 2 3 7 9

    L.sort(myCompare); //指定规则，从大到小
    printList(L);  // 9 7 3 2
}
int main()
{
    test();
}