// ����ͷ�ļ�
#include "WorkManager.h"
#include "Worker.h"
#include <fstream>

// �궨��
#define  FILENAME "111.txt"


// �ϰ����ʵ��
Boss::Boss(int m_id, std::string m_name, int m_department_id)
{
    this->m_id = m_id;
    this->m_name = m_name;
    this->m_department_id = m_department_id;
}
void Boss::showInfo()
{
    cout << "ְ�����" << this->m_id
         << "\tְ������" << this->m_name
         << "\tְ�����ű��" << this->getDepartmentName()
         << "\t��λְ��" << this->showDuty() << endl;
}
string Boss::getDepartmentName()
{
    return ("�ϰ�");
}
// չʾְ��
string Boss::showDuty()
{
    return ("����˾һ�����񣬸������Ա��������");
}

//---------------------------------------------------------------------------------------
// �������ʵ��
Manager::Manager(int m_id, string m_name, int m_department_id)
{
    this->m_id = m_id;
    this->m_name = m_name;
    this->m_department_id = m_department_id;
};
void Manager::showInfo()
{
    cout << "ְ�����" << this->m_id
         << "\tְ������" << this->m_name
         << "\tְ�����ű��" << this->getDepartmentName()
         << "\t��˾ְ��"<< this->showDuty() << endl;
};
string Manager::getDepartmentName()
{
    return ("����");
};
// չʾְ��
string Manager::showDuty()
{
    return ("����ϰ彻��������,���·������Ա��");
}
//---------------------------------------------------------------------------------------

// Ա�����ʵ��
Employee::Employee(int m_id, string m_name, int m_department_id)
{
    this->m_id = m_id;
    this->m_name = m_name;
    this->m_department_id = m_department_id;
}
// ��ȡְ����Ϣ
void Employee::showInfo()
{
    cout << "ְ�����" << this->m_id
         << "\tְ������" << this->m_name
         << "\tְ�����ű��" << this->getDepartmentName()
         << "\tԱ��ְ��" << this->showDuty() << endl;
}
// ��ȡ��λ����
string Employee::getDepartmentName()
{
    return string("Ա��");
}
// չʾְ��
string Employee::showDuty()
{
    return ("��ɾ����·�������");
}

// ���캯����ʼ��
WorkerManager::WorkerManager()
{
    // ��ʼ����Ҫ�жϱ��ص����ݿ��Ƿ��Ѿ���ȡ��ʹ��txt���־λ���д��棩
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // 1.�ļ������ڵ����
    if(! ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 2.�ļ����ڵ����������Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 3.�ļ������ұ���ְ������




}
// չʾ�˵���
void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "***********  ��ӭʹ��ְ������ϵͳ�� ***********" << endl;
    cout << "*************  0.�˳��������  **************" << endl;
    cout << "*************  1.����ְ����Ϣ  **************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  **************" << endl;
    cout << "*************  3.ɾ����ְְ��  **************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  **************" << endl;
    cout << "*************  5.����ְ����Ϣ  **************" << endl;
    cout << "*************  6.���ձ������  **************" << endl;
    cout << "*************  7.��������ĵ�  **************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

// ��������
WorkerManager::~ WorkerManager()
{
    // �ͷŶ�������
    delete[] this->m_EmpArray;

}

// �˳�ϵͳ
void WorkerManager::exit_system()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

// �����ļ�Ϊtxt
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

//���ְ��
void WorkerManager::Add_Emp()
{
    cout << "���������ְ�������� " << endl;

    int addNum = 0; //�����û�����������
    cin >> addNum;

    if (addNum > 0)
    {
        //���
        //��������¿ռ��С
        int newSize = this->m_EmpNum + addNum; // �¿ռ����� = ԭ����¼���� + ��������

        //�����¿ռ�
        Worker ** newSpace = new Worker*[newSize];

        //��ԭ���ռ������ݣ��������¿ռ���
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //�������������
        for (int i = 0; i < addNum; i++)
        {
            int id; //ְ�����
            string name; //ְ������
            int dSelect; // ����ѡ��

            cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
            cin >> id;

            cout << "������� " << i + 1 << " ����ְ�������� " << endl;
            cin >> name;

            cout << "��ѡ���ְ����λ�� " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
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
            //������ְ��ְ�� �����浽������
            newSpace[this->m_EmpNum + i] = worker;

        }

        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;

        //�����¿ռ��ָ��
        this->m_EmpArray = newSpace;

        //�����µ�ְ������
        this->m_EmpNum = newSize;

        // ����ְ����Ϊ�ձ�־
        this->m_FileIsEmpty = false;

        //��ʾ��ӳɹ�
        cout << "�ɹ����" << addNum << "����ְ��!" << endl;

        //�������ݵ��ļ���
        this->save();

        cout << "�ɹ����������ݿ�" << endl;

    }
    else
    {
        cout << "������������" << endl;
    }

    //��������� �����ص��ϼ�Ŀ¼
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

        cout << "���������ѡ��" << endl;

        cin >> choice;

        switch (choice)
        {
            case 0: // �˳�ϵͳ
                workerManager.exit_system();
                break;
            case 1: //����ְ��
                workerManager.Add_Emp();
                break;
            case 2: //��ʾְ��
                workerManager.getWorkerNum();
                break;
            case 3: //ɾ��ְ��
                break;
            case 4: //�޸�ְ��
                break;
            case 5: //����ְ��
                break;
            case 6: //����ְ��
                break;
            case 7: //����ĵ�
                break;
            default:
                system("cls");  // ����
        }
        system("pause");
        return 0;
    };
}