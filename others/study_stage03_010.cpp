#include <iostream>
#include <string>
using namespace std;

class Person{
private:
//    指针变量，用于深拷贝
    int* id;
    int age;
    string name;
public:
//  静态成员变量，在类内声明，初始化赋值需要在类外进行
    static int sex;
    Person(){
        cout << "这是无参构造函数" << endl;
    }
    Person(int a){
        cout << "这是有参构造函数" << endl;
    }
//    传递拷贝的地址，浅拷贝
//    Person(const Person &p){
//        cout << "这是拷贝构造函数" << endl;
//        id = id;
//    }
//    传递拷贝的地址，深拷贝
    Person(const Person &p){
        cout << "这是拷贝构造函数" << endl;
//    浅拷贝默认对值进行简单复制，容易造成内存非法操作，需要使用深拷贝
        age = p.age;
        id = new int(*p.id);
    }
    ~Person(){
        cout << "这是析构函数" << endl;
    }
//    列表初始化，创建对象时传入的参数作为类中属性的初始化值
    Person(string a, int b):name(a),age(b){
    }
//    静态函数
    static void func(){
        cout << "静态函数的调用" << endl;
    }
};
//静态成员类外初始化，需要加上 class:: 防止重复
int Person::sex = 1;
//静态成员函数的调用
void test01(){
    Person::func();
};
int main(){
//    括号法：推荐
//    普通，调用默认的不需要括号
//    Person p;
//    有参构造
//    Person p2(10);
//    拷贝构造，把对象p的所有属性拷贝到p3中
//    Person p3(p);
//    Person（10）---匿名函数，运行完就销毁，不要使用匿名函数来初始化对象，会报错

//    显示法：
//    普通，调用默认的不需要括号
//    Person p;
//    有参构造
//    Person p2 = Person(10);
//    拷贝构造，把对象p的所有属性拷贝到p3中
//    Person p3 = Person(p);


//    隐式转换法：
//    普通，调用默认的不需要括号
//    Person p;
//    有参构造
//    Person p2 = 10;
//    拷贝构造，把对象p的所有属性拷贝到p3中
//    Person p3 = p;

//    访问静态成员变量，可以直接使用 Class::xxx
//    cout << Person::sex << endl;
//    test01();

}
/* 4.2对象的初始化和清理
 * 构造函数和析构函数，编译器会提供，但是是空的
 * 构造函数：
 *      类名(){},不需要返回值，也不需要void，函数名称与类名相同，
 *      可以有参数，因此可以发生重载，自动调用，只会调用一次
 *      不写时相当于系统给你实现了该方法，只不过里面是空的内容
 * 析构函数：
 *      ~类名（）{}，不需要返回值，也不需要void，函数名称与类名相同，前面加上~
 *      不可以有参数，因此不可以发生重载，只会调用一次
 *      作用：可以将堆区的数据进行销毁
 *
 * 构造函数的分类和使用：
 *      按照参数分类：
 *          有参构造和无参构造（构造函数中有无参数区分）
 *      按照类型分类：
 *          普通构造和拷贝构造
 *      三种调用方式：括号法、（根据不同的参数调用不同的构造函数，推荐）
 *                  显示法、(等号右侧创建对象)
 *                  隐式转换法
 * 拷贝构造的调用时机：
 *      1.使用一个已经创建完毕的对象来初始化一个新对象，与之前那个一样，创建一个对象，再使用这个对象作为拷贝函数的变量传入
 *          Person p; Person p2(p);
 *      2.值传递的方式给函数参数传值
 *          Person p; func(p); void func(Person p){};  此时会通过值传递的方式调用拷贝构造函数
 *      3.以值的方式返回局部对象
 *
 * 构造函数构造规则：
 *      默认编译器会创建3个函数：构造函数（空实现）、析构函数（空实现）、拷贝构造函数（值拷贝）
 *      如果用户提供了有参构造函数，编译器不会提供无参构造函数，但是会提供拷贝构造函数
 *      如果用户提供了拷贝构造函数，编译器不会提供其他构造函数
 *
 * 深浅拷贝：（原理和 py一样）
 *      浅拷贝问题：堆区的内存重复释放
 *      使用深拷贝解决以上问题，地址不一样
 *      系统默认的拷贝构造函数是浅拷贝。所以为避免出现内存非法操作问题，需要对拷贝构造函数进行深拷贝
 *      需要在堆区开辟一块内存，见study_stage03_005,在析构函数中对堆区的深拷贝数据进行delete销毁
 *
 * 初始化列表：
 *      构造函数():属性1（值1），属性2（值2），属性3（值3）
 *      写在类中，在创建对象时，传入三个参数abc，
 *      然后这三个参数又分别赋值给类中的属性m_A,m_B,m_C
 *      Person(int a, int b, int c):m_A(a),m_B(b),m_C(c){}
 *      一定要注意冒号的位置！！！
 *
 * 类对象作为类成员：
 *      class A {};
 *      class B { A a };
 *      构造函数时现有A类，再有B类；
 *      析构函数时先有B类，再有A类，顺序相反，栈结构！
 *
 * 静态成员static：
 *      静态成员变量：（也有public、private权限）
 *          所有对象共享同一份数据，修改也是修改原数值,在编译阶段分配内存
 *          类内声明，类外初始化
 *          静态成员访问的时候有两种选择:
 *              一个原本的创建对象访问， Obj.xxx
 *              一种是可以直接使用 Class::xxx 进行访问，因为它是在类外进行初始化的
 *      静态成员函数：（也有public、private权限）
 *          所有对象共享一个函数
 *          静态成员函数只能访问静态成员变量,非静态不能访问
 *          静态成员函数访问的时候有两种选择:
 *              一个原本的创建对象访问， Obj.func
 *              一种是可以直接使用 Class::func 进行访问，因为它是在类外进行初始化的
 *
 * */