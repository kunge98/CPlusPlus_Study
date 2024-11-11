#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;


// 系统类
class WorkerManager
{
public:

    WorkerManager();

    ~WorkerManager();

    //展示菜单
    void show_menu();
    // 退出系统
    void exit_system();

    // 记录文件中人数的个数
    int m_EmpNum;

    // 员工数组指针
    Worker ** m_EmpArray;

    // 添加成员
    void Add_Emp();

    // 保存文件
    void save();

    // 标志位，判断文件是否为空
    bool m_FileIsEmpty;

    // 获取人员数量
    int getWorkerNum();

};

