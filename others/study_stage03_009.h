#pragma once
#include <iostream>
#include <string>
using namespace std;

//需要加上  #pragma once  防止重复引用
//分文件编写需要在.h文件中声明所有的函数和属性，但是不需要实现

//立方体类设计
class Cube {
private:
    int m_len;
    int m_width;
    int m_high;
public:
//    get、set方法
    int getLen();

    int getWidth();

    int getHigh();

    void setLen(int len);

    void setWidth(int width);

    void setHigh(int high);
//面积
    int calcS();

//体积
    int calcV();
//判断是否相等
    bool is_same(Cube &c);
};
