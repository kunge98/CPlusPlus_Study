#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct student
{
    string name;
    int age;
    float score;
};
// 值传递
void printStudent1(struct student s){
    cout << s.name << "\n" << s.age << "\n" << s.score << endl;
}
// 地址传递,需要指针，和->操作符号
// 加入const，会将传递的地址不会修改
void printStudent2(const struct student *p){
    cout << p->name << "\n" << p->age << "\n" << p->score << endl;
}


// 结构体案例（1）
// 学生
struct students
{
    string sName;
    float score;
};
// 老师
struct teachers
{
    string tName;
    struct students sArray [5];
};
// 给老师带的学生赋值的函数
void allocateSpace(struct teachers tArray[], int length){
    for (int i = 0; i < length; i++)
    {
        // 姓名种子
        string nameSeed = "ABCDE";
        // 给老师赋值
        tArray[i].tName = "teacher_";
        tArray[i].tName += nameSeed[i];
        // 老师结构体中还有学生结构体
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].sName = "student_";
            tArray[i].sArray[j].sName += nameSeed[j];

            int random = rand() % 61 + 40;
            tArray[i].sArray[j].score = random;
        }
    }
}
// 打印学生与老师所有信息
void printAllInfo(struct teachers tArray[], int length){
    for (int i = 0; i < length; i++)
    {
        cout << "老师的名字为:" << tArray[i].tName << endl;
        // 打印老师带的5个学生
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生姓名为:" << tArray[i].sArray[j].sName
                 << ",考试分数为:" << tArray[i].sArray[j].score << endl;
        }
    }
}


// 结构体案例（2）
struct heros
{
    string name;
    int age;
    string sex;
};
// 冒泡排序
// 传入的是结构体数组
void bubble_sort(struct heros arr[], int length){
    for (int i = 0; i < length-1; i++)
    {
        for (int j = 0; j < length-i-1; j++)
        {
            // 调用的是年龄
            if (arr[j].age > arr[j+1].age)
            {
                // 定义结构体变量，而不是int
                struct heros temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
// 打印输出
// 传入的是结构体数组
void print_all_sort(struct heros arr[], int length){
    for (int i = 0; i < length; i++)
    {
        cout << arr[i].name << arr[i].age << arr[i].sex << endl;
    }


}
int main(){

    // 25.结构体
    // 结构体需要定义在main外面，许多函数因为写在main中方便
    // 结构体是属于用户自定义的数据类型，允许用户存储不同的数据类型
    // 语法： struct 结构体名 { 结构体成员列表 };
    // 创建学生结构体,包含了姓名、年龄、分数
    // struct student
    // {
    //     string name;
    //     int age;
    //     float score;
    //     float high;
    // };

    // 创建方式三种：
    // 1.struct 结构体名 变量名
    // 通过结构体创建具体的学生
    // struct student s1;
    // s1.name = "张三";
    // s1.age = 24;
    // s1.score = 66.4;
    // s1.high = 188.3;
    // cout << s1.name << "\n" << s1.age << "\n" << s1.score << "\n" << s1.score << endl;

    // 2.struct 结构提名 变量名={成员值1，成员值2...}
    // struct student s2 = {"李四",30,99,164.2};
    // cout << s2.name << "\n" << s2.age << "\n" << s2.score << "\n" << s2.score << endl;

    // 3.定义结构体时顺便创建变量
    // struct student2
    // {
    //     string name = "王五";
    //     int age = 20;
    //     float score = 66.6;
    //     float high = 180.4;
    // };
    // struct student2 s3;
    // cout << s3.name << "\n" << s3.age << "\n" << s3.score << "\n" << s3.score << endl;


    // 结构体数组
    // 定义
    // struct student
    // {
    //     string name;
    //     int age;
    //     float score;
    // };
    // // 创建结构体数组
    // struct student stuArray[3] = {
    //     {"张三",18,66},
    //     {"李四",24,88},
    //     {"王五",72,37}
    // };
    // // 赋值
    // stuArray[2].name = "xx";
    // stuArray[2].age = 27;
    // stuArray[2].score = 91;
    // // 遍历
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << stuArray[i].name << "\n" << stuArray[i].age << "\n" << stuArray[i].score << endl;
    // }


    // 结构体指针
    // 利用操作符 -> 可以通过结构体指针可以访问结构体属性
    // 创建结构体
    // struct student
    // {
    //     string name;
    //     int age;
    //     float score;
    // };
    // // 创建变量
    // struct student s = {"张三",18,87};
    // // 指针指向结构体变量
    // struct student *p = &s;
    // // 通过指针访问结构体变量中的数据
    // cout <<"姓名" << p->name << "年龄" << p->age << "分数" << p->score << endl;



    // 结构体嵌套
    // 结构体中包含了结构体
    // 嵌套的结构体在使用时和类的调用很像
    // struct student
    // {
    //     string name;
    //     int age;
    //     float score;
    // };
    // 在老师结构体中嵌套了学生结构体
    // struct teacher
    // {
    //     int id;
    //     string name;
    //     int age;
    //     struct student stu;
    // };

    // 定义结构变量
    // struct teacher t;
    // // 赋值
    // t.id = 2022001;
    // t.name = "xxx";
    // t.age = 50;
    // t.stu.name = "stu";
    // t.stu.age = 18;
    // t.stu.score = 60;


    // 结构体作为函数参数
    // 值传递，不会改变原值
    // 地址传递，会改变原值
    // 如果想修改主函数中的数据，用地址传递，反之使用值传递
    // 创建学生变量
    // struct student stu;
    // stu.name = "三张";
    // stu.age = 18;
    // stu.score = 66;
    // // 值传递
    // printStudent1(stu);
    // // 地址传递
    // printStudent2(&stu);


    // 结构体中const
    // struct student stu = {"三张",18,62};
    // // 使用地址传递的好处：可以节省内存，因为指针只占4个字节，结构体占据的就多了
    // // 缺点：容易修改原本的数值，所以引入const来修饰指针，在函数的参数前面写上const
    // printStudent2(&stu);


    // 结构体案例(1)
    // 每个老师带5个学生，总计3名老师
    // 设计学生和老师的结构体，在老师结构体中，有姓名和一个存放5名学生的数组成员变量
    // 学生结构体有姓名、分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
    // 最终打印出老师数据以及老师所带的学生数据
    // 随机数种子
    // srand((unsigned int)time(NULL));
    // // 创建3名老师的数组
    // struct teachers tArray [3];
    // // 通过函数给3名老师赋值，并给老师带的学生信息赋值
    // int length = sizeof(tArray) / sizeof(tArray[0]);
    // // 赋值
    // allocateSpace(tArray, length);
    // // 打印老师与学生的信息
    // printAllInfo(tArray, length);


    // 结构体案例（2）
    // 设计一个英雄结构体，包括姓名、年龄、性别，数组中存放5名英雄，通过冒泡排序按照年龄最小升序排序
    struct heros heroArray [5]= {
            {"刘备",23,"男"},
            {"关羽",22,"男"},
            {"张飞",20,"男"},
            {"赵云",21,"男"},
            {"貂蝉",19,"女"},
    };
    // 求出数组的长度
    int length = sizeof(heroArray) / sizeof(heroArray[0]);
    // 冒泡排序
    bubble_sort(heroArray, length);
    // 打印输出
    print_all_sort(heroArray, length);

































    system("pause");
}