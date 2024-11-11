#include <iostream>
#include <string>
using namespace std;
#include "study_stage03_009.h"

// 分文件编写的cpp文件中，需要是把函数的具体实现写上
//在引用方面上面需要引入头文件，在实现方法上要加上  class::
//    get、set方法
int Cube::getLen() {
    return m_len;
}

int Cube::getWidth() {
    return m_width;
}

int Cube::getHigh() {
    return m_high;
}

void Cube::setLen(int len) {
    m_len = len;
}

void Cube::setWidth(int width) {
    m_width = width;
}

void Cube::setHigh(int high) {
    m_high = high;
}

//面积
int Cube::calcS() {
    return 2 * (m_high * m_width + m_high * m_len + m_len * m_width);
}

//体积
int Cube::calcV() {
    return m_high * m_width * m_len;
}

//判断是否相等
bool Cube::is_same(Cube &c) {
    if (m_len == c.getLen() && m_width == c.getWidth() && m_high == c.getHigh()) {
        return true;
    } else {
        return false;
    }
}


// 立方体类案例
int main(){
    Cube cube;
    cube.setLen(10);
    cube.setHigh(10);
    cube.setWidth(10);

    cout << cube.calcS() << endl;
    cout << cube.calcV() << endl;

    Cube cube2;
    cube2.setLen(10);
    cube2.setHigh(10);
    cube2.setWidth(10);
//判断两个立方体是否相等
    bool res = cube.is_same(cube2);
    cout << res << endl;

}