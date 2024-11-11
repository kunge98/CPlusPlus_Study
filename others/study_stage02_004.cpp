#include <iostream>
#include <string>
using namespace std;
#define max_size 1000

// 基于C++基础知识的通讯录管理系统

// 用户结构体
struct Person
{
    string m_name;
    // 01表示男女
    int m_sex;
    int m_age;
    string m_phone;
    string m_addr;

};
// 通讯录结构体
struct AddressBooks
{
    // 保存联系人的数组
    struct Person pArray [max_size];
    // 当前联系人的个数
    int m_size;
};
// 显示菜单界面
void show_menu(){
    cout << "***********************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "***********************" << endl;
}
// 1.添加联系人
// 信息包括姓名、性别、年龄、联系电话、家庭住址，结构体
void addPerson(struct AddressBooks *abs){
    // 如果通讯录满
    if (abs->m_size == max_size)
    {
        cout << "通讯录已满，请先删除" << endl;
    }
    else{
        // 姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->pArray[abs->m_size].m_name = name;
        // 性别
        cout << "请输入性别：1男0女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 0 || sex == 1)
            {
                abs->pArray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "请重新输入性别" << endl;
        }
        // 添加年龄
        int age;
        cout << "请输入年龄" << endl;
        while (true)
        {
            cin >> age;
            if(age < 0 || age > 120)
            {
                cout << "请输入合法年龄" << endl;
            }
            else{
                abs->pArray[abs->m_size].m_age = age;
                break;
            }
        }
        // 添加电话
        string phone;
        cout << "请输入电话" << endl;
        while (true)
        {
            cin >> phone;
            // 这个地方就可以做校验了，有点复杂
            if(phone[0]=='1')
            {
                abs->pArray[abs->m_size].m_phone;
                break;
            }
            else
            {
                cout << "请输入合法手机号" << endl;
            }
        }
        // 添加地址
        string address;
        cout << "请输入地址" << endl;
        cin >> address;
        abs->pArray[abs->m_size].m_addr = address;
        // 更新通讯录的人数
        abs->m_size++;
        cout << "添加成功！" << endl;
        system("pause");
        // 清屏
        system("cls");
    }
}
// 2.展示联系人
void show_person(struct AddressBooks *abs){
    if (abs->m_size == 0)
    {
        cout << "通讯录为空，请先添加联系人！" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            // 优化：对于性别虽然输入是10，但是输出要求是汉字
            // 优化：使用\t 制表符来水平一行打印联系人信息
            cout << "姓名" << abs->pArray[i].m_name << endl;
            cout << "性别" << (abs->pArray[i].m_sex == 1?"男":"女") << endl;
            cout << "年龄" << abs->pArray[i].m_age << endl;
            cout << "电话" << abs->pArray[i].m_phone << endl;
            cout << "地址" << abs->pArray[i].m_addr << endl;
        }
    }
    system("pause");
    system("cls");
}
// 检测联系人是否存在（用于删除、查找、修改等功能）
// 传入通讯录和要检测的姓名
int is_exist(struct AddressBooks *abs, string name){
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->pArray[i].m_name == name)
        {
            // 找到的联系人返回其索引
            return i;
        }
    }
    // 没有此人，返回-1
    return -1;
}
// 3.删除联系人
void del_person(struct AddressBooks *abs){
    string name;
    cout << "请输入想删除的联系人" << endl;
    cin >> name;
    // 判断删除的人是否存在
    int res = is_exist(abs, name);
    //
    if(res != -1)
    {
        // 找到该索引位置，删除并进行数据前移
        for (int i = res; i < abs->m_size; i++)
        {
            abs->pArray[i] = abs->pArray[i+1];
        }
        // 删除之后联系人数量变少
        abs->m_size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "差无此人" << endl;
    }
}
// 4.查找联系人
void select_person(struct AddressBooks *abs){
    string name;
    cout << "请输入想查找的联系人" << endl;
    cin >> name;
    // 判断查找的人是否存在
    int res = is_exist(abs, name);
    // 遍历数组，找联系人
    for (int i = 0; i < abs->m_size; i++)
    {
        if (res != -1)
        {
            cout << "姓名" << abs->pArray[res].m_name << endl;
            cout << "性别" << abs->pArray[res].m_sex << endl;
            cout << "年龄" << abs->pArray[res].m_age << endl;
            cout << "电话" << abs->pArray[res].m_phone << endl;
            cout << "地址" << abs->pArray[res].m_addr << endl;
        }
        else
        {
            cout << "查无此人" << endl;
        }
    }
    system("pause");
    system("cls");
}
// 05.修改联系人
void modify_person(struct AddressBooks *abs){
    string name;
    int sex;
    int age;
    string phone;
    string addr;
    cout << "请输入想修改的联系人" << endl;
    cin >> name;
    // 判断查找的人是否存在
    int res = is_exist(abs, name);
    // 遍历数组，找联系人
    for (int i = 0; i < abs->m_size; i++)
    {
        if (res != -1)
        {
            cout << "姓名：" << endl;
            cin >> name;
            abs->pArray[res].m_name = name;

            cout << "性别：" << endl;
            while (true)
            {
                cin >> sex;
                if(sex == 1 || sex == 0)
                {
                    abs->pArray[res].m_sex = sex;
                    break;
                }
                else
                {
                    cout << "请重新输入" << endl;
                }
            }

            cout << "年龄：" << endl;
            cin >> age;
            abs->pArray[res].m_age = age;

            cout << "电话：" << endl;
            cin >> phone;
            abs->pArray[res].m_phone = phone;

            cout << "地址：" << endl;
            cin >> addr;
            abs->pArray[res].m_addr = addr;
        }
        else
        {
            cout << "查无此人" << endl;
        }
    }
    system("pause");
    system("cls");
}
// 06.清空联系人(可以拓展，在出来是否真的需要清空)
void clean_allperson(struct AddressBooks *abs){
    // 联系人数量置为0，做一个逻辑上的清空
    abs->m_size = 0;
    system("pause");
    system("cls");

}
// 通讯录管理系统
int main()
{
    // 创建用户输入的变量
    int select = 0;
    // 创建结构体变量
    struct AddressBooks abs;
    // 初始化通讯录人数
    abs.m_size = 0;


    while (true)
    {
        // 展示菜单栏目
        show_menu();

        // 用户选择
        cin >> select;
        switch (select)
        {
            // 1.添加联系人
            case 1:
                // 地址传递
                addPerson(&abs);
                break;
                // 2.显示联系人
            case 2:
                show_person(&abs);
                break;
                // 3.删除联系人
            case 3:
                del_person(&abs);
                break;
                // 4.查找联系人
            case 4:
                select_person(&abs);
                break;
                // 5.修改联系人
            case 5:
                modify_person(&abs);
                break;
                // 6.清空联系人
            case 6:
                clean_allperson(&abs);
                break;

                // 退出通讯录
            case 0:
                cout << "已退出，欢迎下次使用！" << endl;
                system("pause");
                break;

            default:break;
        }

    }

    return 0;
}