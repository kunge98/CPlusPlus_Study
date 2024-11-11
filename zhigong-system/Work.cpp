////#include "Worker.h"
//
//// 老板类的实现
//Boss::Boss(int m_id, std::string m_name, int m_department_id)
//{
//    this->m_id = m_id;
//    this->m_name = m_name;
//    this->m_department_id = m_department_id;
//}
//void Boss::showInfo()
//{
//    cout << "职工编号" << this->m_id
//         << "\t职工名字" << this->m_name
//         << "\t职工部门编号" << this->getDepartmentName()
//         << "\t岗位职责" << this->showDuty() << endl;
//}
//string Boss::getDepartmentName()
//{
//    return ("老板");
//}
//// 展示职责
//string Boss::showDuty()
//{
//    return ("管理公司一切事务，给经理和员工发工资");
//}
//
////---------------------------------------------------------------------------------------
//// 经理类的实现
//Manager::Manager(int m_id, string m_name, int m_department_id)
//{
//    this->m_id = m_id;
//    this->m_name = m_name;
//    this->m_department_id = m_department_id;
//};
//void Manager::showInfo()
//{
//    cout << "职工编号" << this->m_id
//         << "\t职工名字" << this->m_name
//         << "\t职工部门编号" << this->getDepartmentName()
//         << "\t公司职责"<< this->showDuty() << endl;
//};
//string Manager::getDepartmentName()
//{
//    return ("经理");
//};
//// 展示职责
//string Manager::showDuty()
//{
//    return ("完成老板交给的任务,并下发任务给员工");
//}
////---------------------------------------------------------------------------------------
//
//// 员工类的实现
//Employee::Employee(int m_id, string m_name, int m_department_id)
//{
//    this->m_id = m_id;
//    this->m_name = m_name;
//    this->m_department_id = m_department_id;
//}
//// 获取职工信息
//void Employee::showInfo()
//{
//    cout << "职工编号" << this->m_id
//         << "\t职工名字" << this->m_name
//         << "\t职工部门编号" << this->getDepartmentName()
//         << "\t员工职责" << this->showDuty() << endl;
//}
//// 获取岗位名称
//string Employee::getDepartmentName()
//{
//    return string("员工");
//}
//// 展示职责
//string Employee::showDuty()
//{
//    return ("完成经理下发的任务");
//}
