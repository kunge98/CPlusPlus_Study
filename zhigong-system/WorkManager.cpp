// 引入头文件
#include "WorkManager.h"
#include "Worker.h"
#include <fstream>

// 宏定义
#define  FILENAME "111.txt"


// 老板类的实现
Boss::Boss(int m_id, std::string m_name, int m_department_id)
{
    this->m_id = m_id;
    this->m_name = m_name;
    this->m_department_id = m_department_id;
}
void Boss::showInfo()
{
    cout << "职工编号" << this->m_id
         << "\t职工名字" << this->m_name
         << "\t职工部门编号" << this->getDepartmentName()
         << "\t岗位职责" << this->showDuty() << endl;
}
string Boss::getDepartmentName()
{
    return ("老板");
}
// 展示职责
string Boss::showDuty()
{
    return ("管理公司一切事务，给经理和员工发工资");
}

//---------------------------------------------------------------------------------------
// 经理类的实现
Manager::Manager(int m_id, string m_name, int m_department_id)
{
    this->m_id = m_id;
    this->m_name = m_name;
    this->m_department_id = m_department_id;
};
void Manager::showInfo()
{
    cout << "职工编号" << this->m_id
         << "\t职工名字" << this->m_name
         << "\t职工部门编号" << this->getDepartmentName()
         << "\t公司职责"<< this->showDuty() << endl;
};
string Manager::getDepartmentName()
{
    return ("经理");
};
// 展示职责
string Manager::showDuty()
{
    return ("完成老板交给的任务,并下发任务给员工");
}
//---------------------------------------------------------------------------------------

// 员工类的实现
Employee::Employee(int m_id, string m_name, int m_department_id)
{
    this->m_id = m_id;
    this->m_name = m_name;
    this->m_department_id = m_department_id;
}
// 获取职工信息
void Employee::showInfo()
{
    cout << "职工编号" << this->m_id
         << "\t职工名字" << this->m_name
         << "\t职工部门编号" << this->getDepartmentName()
         << "\t员工职责" << this->showDuty() << endl;
}
// 获取岗位名称
string Employee::getDepartmentName()
{
    return string("员工");
}
// 展示职责
string Employee::showDuty()
{
    return ("完成经理下发的任务");
}

// 构造函数初始化
WorkerManager::WorkerManager()
{
    // 初始化需要判断本地的数据库是否已经读取（使用txt与标志位进行代替）
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // 1.文件不存在的情况
    if(! ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 2.文件存在的情况，但是为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 3.文件存在且保存职工数据




}
// 展示菜单栏
void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "***********  欢迎使用职工管理系统！ ***********" << endl;
    cout << "*************  0.退出管理程序  **************" << endl;
    cout << "*************  1.增加职工信息  **************" << endl;
    cout << "*************  2.显示职工信息  **************" << endl;
    cout << "*************  3.删除离职职工  **************" << endl;
    cout << "*************  4.修改职工信息  **************" << endl;
    cout << "*************  5.查找职工信息  **************" << endl;
    cout << "*************  6.按照编号排序  **************" << endl;
    cout << "*************  7.清空所有文档  **************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// 析构函数
WorkerManager::~ WorkerManager()
{
    // 释放堆区数据
    delete[] this->m_EmpArray;

}

// 退出系统
void WorkerManager::exit_system()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

// 保存文件为txt
void WorkerManager::save()
{
    ofstream ofs;

    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_id << " "
            << this->m_EmpArray[i]->m_name << " "
            << this->m_EmpArray[i]->m_department_id << endl;
    }
    ofs.close();
}

//添加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入添加职工数量： " << endl;

    int addNum = 0; //保存用户的输入数量
    cin >> addNum;

    if (addNum > 0)
    {
        //添加
        //计算添加新空间大小
        int newSize = this->m_EmpNum + addNum; // 新空间人数 = 原来记录人数 + 新增人数

        //开辟新空间
        Worker ** newSpace = new Worker*[newSize];

        //将原来空间下数据，拷贝到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id; //职工编号
            string name; //职工姓名
            int dSelect; // 部门选择

            cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
            cin >> name;

            cout << "请选择该职工岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }
            //将创建职工职责 ，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;

        }

        //释放原有空间
        delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray = newSpace;

        //更新新的职工人数
        this->m_EmpNum = newSize;

        // 更新职工不为空标志
        this->m_FileIsEmpty = false;

        //提示添加成功
        cout << "成功添加" << addNum << "名新职工!" << endl;

        //保存数据到文件中
        this->save();

        cout << "成功保存至数据库" << endl;

    }
    else
    {
        cout << "输入数据有误" << endl;
    }

    //按任意键后 清屏回到上级目录
    system("pause");
    system("cls");
}

int WorkerManager::getWorkerNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int departid;
    int num;

    while (ifs >> id && ifs >> name && ifs >> departid)
    {
        num ++;
    }

    ifs.close();

    return num;

}



int main()
{

    int choice = 0;
    while (true)
    {
        WorkerManager workerManager;
        workerManager.show_menu();

        cout << "请输入你的选择" << endl;

        cin >> choice;

        switch (choice)
        {
            case 0: // 退出系统
                workerManager.exit_system();
                break;
            case 1: //增加职工
                workerManager.Add_Emp();
                break;
            case 2: //显示职工
                workerManager.getWorkerNum();
                break;
            case 3: //删除职工
                break;
            case 4: //修改职工
                break;
            case 5: //查找职工
                break;
            case 6: //排序职工
                break;
            case 7: //清空文档
                break;
            default:
                system("cls");  // 清屏
        }
        system("pause");
        return 0;
    };
}