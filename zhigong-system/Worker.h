#pragma once
#include <iostream>
#include <string>
using namespace std;

// 抽象职工类，包括员工、经理、老板
class Worker
{
public:
    //编号、姓名、部门编号
    int m_id;
    string m_name;
    int m_department_id;

    // 显示个人信息、岗位名称
    virtual void showInfo() = 0;

    virtual string getDepartmentName() = 0;

    virtual string showDuty() = 0;
};

// 老板类的声明
class Boss : public Worker
{
public:
    Boss(int m_id, string m_name, int m_department_id);

    void showInfo();

    string getDepartmentName();

    string showDuty();

};

//---------------------------------------------------------------------------------------
// 经理类的声明
class Manager : public Worker
{
public:
    Manager(int m_id, string m_name, int m_department_id);

    void showInfo();

    string getDepartmentName();

    string showDuty();

};

//---------------------------------------------------------------------------------------
// 员工类的声明
class Employee : public Worker
{
public:
    Employee(int m_id, string m_name, int m_department_id);

    // 显示个人信息、岗位名称
    void showInfo();

    string getDepartmentName();

    string showDuty();

};
