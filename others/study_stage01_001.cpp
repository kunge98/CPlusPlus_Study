#include <iostream>
// C++风格的字符串
#include <string>
using namespace std;

//  C++基础知识

int main(){

    // 03.注释
    // 04.变量
    // 数据类型，变量名，变量初始值
    // int a = 10;
    // cout << "a = " << a << endl;


    // 05.常量。不可以修改
    // (1)#define, (2)const
    // 两者区别：const计算机可以检查出来，define不可以
    // # define Day 7
    // cout << "共计多少天" << Day << "天" << endl;
    // const int month = 30;
    // cout << "共计多少个" << month << "月份" << endl;

    // 06.关键字，标识符
    // 标识符规则：
    // 不可以是关键字
    // 字母、数字、下划线，
    // 第一个必须是字母或者下划线，
    // 区分大小写


    // 数据类型：给变量分配一个合适的内存空间
    // 07 整型
    // short 2 (-32768 ~ 32767)
    // int 4 (-2**31 ~ 2**31)
    // long win:4; linux(32):4; linux(64):8
    // long long 8


    // 08 sizeof，利用他求出占用内存空间大小
    // 语法： sizeof( 数据类型 或者是 变量)
    // short a = 10;
    // int b = 10;
    // cout << "xx" << sizeof(a) << endl;
    // cout << "xx" << sizeof(b) << endl;
    // cout << "xx" << sizeof(long) << endl;
    // cout << "xx" << sizeof(long long) << endl;


    // 09 浮点型
    // float   4 (7位有效数字)
    // double  8 (15-16位有效数字，更精准)
    // 系统默认是double，写上f代表类型转换为float
    // float a = 3.141592655587f;
    // double b = 3.14;
    // cout << "xx" << a << "xx" << b << endl;
    // cout << "xx" << sizeof(a) << "xx" << sizeof(b) << endl;


    // 10.字符型
    // 只能使用单引号，而且里面只有一个
    // 占用1个字节内存，将对应的ASCII值存放到内存中,查看ASCII值使用int强转，A：65，a：97
    // char a = 'a';
    // cout << "xx" << sizeof(a) << endl;
    // cout << "xx" << (int)a << endl;


    // 11.转义字符
    // \n 换行,
    // \\ 代表一个反斜杠
    // \t 水平制表tab键,整齐的输出数据
    // int a = 10;
    // cout << "hello world \n \\ \n" << a << endl;


    // 12.字符串,两种风格,前者为C，后者为C++
    // C注意：中括号，双引号
    // char a[] = "hello world";
    // C++注意：需要导入头文件  #include <string>
    // string b = "hello world";


    // 13.布尔，True 非0，False 0
    // 占用1个字节内存
    // bool flag = true;
    // bool flag2 = false;


    // 14.数据输入，其他类型的数值都是一样的
    // cin >>
    // int a = 0;
    // cout << "原本a的数值为" << a << endl;
    // cout << "请输入a的数值" << endl;
    // cin >> a;
    // cout << "a的数值为" << a << endl;


    // 15.运算符
    // 算术运算、赋值运算、比较运算、逻辑运算
    // 算术： +  -  *  /(整除，除数不可为0)  %（取余，两个小数不可以取余）  x++  ++x  x--  --x
    // 赋值： =  +=  -=  *=  /=  %=
    // 比较： ==  !=  <  >  <=  >= （返回布尔值）
    // 逻辑： ！（相反）    &&（同真则真，其余为假）  ||（同假为假假，其余为真）


    // 16.流程结构
    // 三种结构：顺序结构、选择结构、循环结构
    // 选择结构
    // 01.if语句（三种）：
    // 单行：if(){}
    // 多行：if(){}  else{}
    // 多条件: if(){}  eles if(){}  else{}
    // 嵌套if语句


    // 17.三目运算符
    // 为真表示2，为假表达3
    // 表达式1 ? 表达2 : 表达3


    // 18.选择结构
    // 02.switch语句:判断时只能是整形或者字符型，不可以是一个区间
    // int a = 10
    // switch(){
    //     case1 10: break;
    //     case2 9: break;
    //     default:break;}


    // 19.循环结构
    // while (条件) {循环语句}
    // do{循环语句} while(循环条件)---最少执行一次
    // for(起始表达式(可以写在for上面);条件表达式;末尾循环体) {循环语句}
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << i << endl;
    // }

    // 案例：99乘法表
    // for (int i = 1; i <=9 ; i++)
    // {
    //     for(int j = 1; j<=i ;j++)
    //     {
    //         cout << j << "*" << i << "=" << j*i <<"    ";
    //     }
    //     cout << endl;
    // }


    // 20.跳转语句
    // continue：跳出本次循环
    // break：跳出循环
    // goto：无条件跳转语句，不建议使用


    // 21.数组
    // 一维数组的3种定义：
    // （1）数据类型 数组名 [长度];
    // int arr [5];
    // // （2）数据类型 数组名 [长度] = {xx, xx, xx, xx};
    // int arr2 [5] = {1,2,3,4,5};
    // // （3）数据类型 数组名 [] = {xx, xx, xx, xx};
    // int arr3 [] = {1,2,3,4,5};
    // // 统计数组在内存中的长度
    // cout << sizeof(arr) << endl;
    // cout << sizeof(arr2[3]) << endl;
    // // 可以花去数组在内存中的首地址
    // cout << arr3 << endl;
    // cout << (long long)arr2 << endl;
    // // 将内存转成具体的数值，在内存中占用的位置，使用int强转会报错
    // cout << (long long)&arr2[0] << endl;
    // cout << (long long)&arr2[1] << endl;


    // 案例：实现数组的倒叙
    // 核心思想：使用双指针，交换左右指针，使用temp保存被覆盖的值
    // 数组的末尾指针可以使用 sizeof(arr) / sizeof(arr[0]) - 1 实现


    // 案例：冒泡排序
    // 双层循环，第一个数字比第二个数字大，交换两个数字，还是要使用temp
    // 主要是两层循环的循环次数，
    // 外层排序总论数：         元素个数-1
    // 内层循环每轮对比次数：   元素个数-排序轮数-1


    // 22.二维数组
    // 推荐方式：数据类型 数组名 [][] = {{xx, xx, xx}, {xx, xx, xx}}
    // int arr [2][3] = {{1,2,3}, {4,5,6}};
    // // 查看数组所占空间大小
    // cout << sizeof(arr) << endl;
    // // 查看某一行所占用空间大小
    // cout << sizeof(arr[0]) << endl;
    // cout << sizeof(arr[0][0]) << endl;
    // // 查看数组的地址和一维数组的操作一致
    // cout << (long long)arr << endl;
    // cout << (long long)&arr[0] << endl;
    // cout << (long long)&arr[1] << endl;
    // cout << (long long)&arr[0][0] << endl;
    // cout << (long long)&arr[0][1] << endl;


    // 23.函数
    // 返回值类型，函数名，参数列表，函数体语句，return
    // 函数需要写在main外面，这里为了方便写在了里面
    // 值传递：     形参（函数）里面的数值变化不会影响到实参（main里面）的数值变化
    // 常见样式：   无参无返，有参无返，无参有返，有参有返
    // 函数声明：   可以先把自定义函数写在main前面
    // int add(int num1, int num2){
    //     int sum = num1 + num2;
    //     return sum;
    // }
    // int a = 2;
    // int b = 3;
    // int res = add(a, b);
    // cout << res << endl;


    // 分文件编写就是把多的函数写到外部文件中，具体在stage02中实现了
    // 安装了插件ctrl + shift +p先搜索
    // 再输入create C++ project就可以了
    // 分文件编写： .h的头文件  .cpp的源文件  在头文件中写函数的声明  在源文件中写函数的定义

    system("pause");

}
