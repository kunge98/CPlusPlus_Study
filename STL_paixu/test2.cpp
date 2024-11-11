#include <algorithm>
#include <vector>
#include <ctime>
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
//    srand((unsigned int)time(NULL));
    vector<int> v;
    for(int i = 0 ; i < 10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint());  // 0 1 2 3 4 5 6 7 8 9
    cout << endl;

    //打乱顺序
    random_shuffle(v.begin(), v.end());  //  1 9 4 8 0 7 3 2 5 6
    for_each(v.begin(), v.end(), myPrint());
    random_shuffle(v.begin(), v.end());  // 0 1 9 4 3 2 5 8 6 7
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}
int main()
{
    test();
}