#include <iostream>
#include <string>
using namespace std;
//
/*
 * 4.类与对象，接下来的cpp文件会是大量的类与对象
 * 4.1封装：将属性和行为作为一个整体，并加以权限和控制
 * 语法：class 类名 {访问权限：属性/行为};
 * 类中的属性和成员成为成员，
 *
 * 三种访问权限：
 *      公共权限：public 类内类外都可以访问
 *      保护权限 protected 类内可以访问类外不可以访问
 *      私有权限 private 类内可以访问类外不可以访问，谁都不可以，权限最高
 *
 * struct 与 class唯一区别：默认的成员权限不一样
 *      struct默认权限为公共public
 *      class默认权限为私有private
 * 成员属性私有：（封装的核心）
 *      将成员属性设置为私有，可以自己控制读写权限
 *      通过设置其他的公共的接口来实现封装，（修改和获取，set和 get方法）
 * 类--分文件编写：
 *      在.h文件中需要写上类的声明，只需要声明(函数声明和变量声明)就可以例如 void setName();
 *      在.cpp文件中只需要实现具体的函数，在函数的名字前面加上 void Person::setName(){};私有变量也不要了
 *      在.h文件中写上 #program once防止重复引用
 *      记得在 cpp文件引入#include "xxx.h"
 *
 * */
class Person{
public:
//    set设置姓名
    void set_name(string name){
        p_name = name;
    }
//    get获取姓名
//    其他的变量也是如此，根据实际的项目需要来设置
    string get_name(){
        return p_name;
    }

private:
    string p_name;
    int password;
//    三种权限在类内都可以访问到,但是在类外创建实例化对象之后只可以访问public的属性
    void show(){
        p_name = "abc";
        password = 123;
    }
};

int main(){

    Person p;
}

