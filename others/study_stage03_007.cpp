#include <iostream>
#include <string>
using namespace std;

// C++核心编程
int main(){
    cout << "hello " << endl;

}

/*
3.函数提高

默认参数：在自定义函数中提前传入的参数，如果有默认值，必须从右边开始满足
    如果函数声明有默认值，那么函数实现就不能有默认值，只能活一个
    函数声明：类型 函数名（参数）；
    函数实现：类型 函数名（参数）{语句代码}

函数占位参数：返回值类型 函数名 （数据类型）{}，占位参数还可以有默认参数
    void func (int a, int(占位参数)){}
    感觉没有什么用？？？

函数重载：函数名可以相同，提高复用性
    满足重载条件：同一个作用域之下，
                 函数名称相同，
                 函数参数类型不同或者个数不同或者顺序不同
    注意事项：
                引用作为函数重载的条件
                当函数重载又碰到默认参数会出现二义性
    void fun(){}
    void fun(int a, int b){}
    void fun(int b, int a){}
    void fun(int b, int a, int c){}
    void fun(char a, float b){}

*/