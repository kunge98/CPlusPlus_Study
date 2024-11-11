#include <iostream>
#include <string>
using namespace std;
#define max_size 1000

// ����C++����֪ʶ��ͨѶ¼����ϵͳ

// �û��ṹ��
struct Person
{
    string m_name;
    // 01��ʾ��Ů
    int m_sex;
    int m_age;
    string m_phone;
    string m_addr;

};
// ͨѶ¼�ṹ��
struct AddressBooks
{
    // ������ϵ�˵�����
    struct Person pArray [max_size];
    // ��ǰ��ϵ�˵ĸ���
    int m_size;
};
// ��ʾ�˵�����
void show_menu(){
    cout << "***********************" << endl;
    cout << "***** 1.�����ϵ�� *****" << endl;
    cout << "***** 2.��ʾ��ϵ�� *****" << endl;
    cout << "***** 3.ɾ����ϵ�� *****" << endl;
    cout << "***** 4.������ϵ�� *****" << endl;
    cout << "***** 5.�޸���ϵ�� *****" << endl;
    cout << "***** 6.�����ϵ�� *****" << endl;
    cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
    cout << "***********************" << endl;
}
// 1.�����ϵ��
// ��Ϣ�����������Ա����䡢��ϵ�绰����ͥסַ���ṹ��
void addPerson(struct AddressBooks *abs){
    // ���ͨѶ¼��
    if (abs->m_size == max_size)
    {
        cout << "ͨѶ¼����������ɾ��" << endl;
    }
    else{
        // ����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->pArray[abs->m_size].m_name = name;
        // �Ա�
        cout << "�������Ա�1��0Ů" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 0 || sex == 1)
            {
                abs->pArray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "�����������Ա�" << endl;
        }
        // �������
        int age;
        cout << "����������" << endl;
        while (true)
        {
            cin >> age;
            if(age < 0 || age > 120)
            {
                cout << "������Ϸ�����" << endl;
            }
            else{
                abs->pArray[abs->m_size].m_age = age;
                break;
            }
        }
        // ��ӵ绰
        string phone;
        cout << "������绰" << endl;
        while (true)
        {
            cin >> phone;
            // ����ط��Ϳ�����У���ˣ��е㸴��
            if(phone[0]=='1')
            {
                abs->pArray[abs->m_size].m_phone;
                break;
            }
            else
            {
                cout << "������Ϸ��ֻ���" << endl;
            }
        }
        // ��ӵ�ַ
        string address;
        cout << "�������ַ" << endl;
        cin >> address;
        abs->pArray[abs->m_size].m_addr = address;
        // ����ͨѶ¼������
        abs->m_size++;
        cout << "��ӳɹ���" << endl;
        system("pause");
        // ����
        system("cls");
    }
}
// 2.չʾ��ϵ��
void show_person(struct AddressBooks *abs){
    if (abs->m_size == 0)
    {
        cout << "ͨѶ¼Ϊ�գ����������ϵ�ˣ�" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            // �Ż��������Ա���Ȼ������10���������Ҫ���Ǻ���
            // �Ż���ʹ��\t �Ʊ����ˮƽһ�д�ӡ��ϵ����Ϣ
            cout << "����" << abs->pArray[i].m_name << endl;
            cout << "�Ա�" << (abs->pArray[i].m_sex == 1?"��":"Ů") << endl;
            cout << "����" << abs->pArray[i].m_age << endl;
            cout << "�绰" << abs->pArray[i].m_phone << endl;
            cout << "��ַ" << abs->pArray[i].m_addr << endl;
        }
    }
    system("pause");
    system("cls");
}
// �����ϵ���Ƿ���ڣ�����ɾ�������ҡ��޸ĵȹ��ܣ�
// ����ͨѶ¼��Ҫ��������
int is_exist(struct AddressBooks *abs, string name){
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->pArray[i].m_name == name)
        {
            // �ҵ�����ϵ�˷���������
            return i;
        }
    }
    // û�д��ˣ�����-1
    return -1;
}
// 3.ɾ����ϵ��
void del_person(struct AddressBooks *abs){
    string name;
    cout << "��������ɾ������ϵ��" << endl;
    cin >> name;
    // �ж�ɾ�������Ƿ����
    int res = is_exist(abs, name);
    //
    if(res != -1)
    {
        // �ҵ�������λ�ã�ɾ������������ǰ��
        for (int i = res; i < abs->m_size; i++)
        {
            abs->pArray[i] = abs->pArray[i+1];
        }
        // ɾ��֮����ϵ����������
        abs->m_size--;
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
}
// 4.������ϵ��
void select_person(struct AddressBooks *abs){
    string name;
    cout << "����������ҵ���ϵ��" << endl;
    cin >> name;
    // �жϲ��ҵ����Ƿ����
    int res = is_exist(abs, name);
    // �������飬����ϵ��
    for (int i = 0; i < abs->m_size; i++)
    {
        if (res != -1)
        {
            cout << "����" << abs->pArray[res].m_name << endl;
            cout << "�Ա�" << abs->pArray[res].m_sex << endl;
            cout << "����" << abs->pArray[res].m_age << endl;
            cout << "�绰" << abs->pArray[res].m_phone << endl;
            cout << "��ַ" << abs->pArray[res].m_addr << endl;
        }
        else
        {
            cout << "���޴���" << endl;
        }
    }
    system("pause");
    system("cls");
}
// 05.�޸���ϵ��
void modify_person(struct AddressBooks *abs){
    string name;
    int sex;
    int age;
    string phone;
    string addr;
    cout << "���������޸ĵ���ϵ��" << endl;
    cin >> name;
    // �жϲ��ҵ����Ƿ����
    int res = is_exist(abs, name);
    // �������飬����ϵ��
    for (int i = 0; i < abs->m_size; i++)
    {
        if (res != -1)
        {
            cout << "������" << endl;
            cin >> name;
            abs->pArray[res].m_name = name;

            cout << "�Ա�" << endl;
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
                    cout << "����������" << endl;
                }
            }

            cout << "���䣺" << endl;
            cin >> age;
            abs->pArray[res].m_age = age;

            cout << "�绰��" << endl;
            cin >> phone;
            abs->pArray[res].m_phone = phone;

            cout << "��ַ��" << endl;
            cin >> addr;
            abs->pArray[res].m_addr = addr;
        }
        else
        {
            cout << "���޴���" << endl;
        }
    }
    system("pause");
    system("cls");
}
// 06.�����ϵ��(������չ���ڳ����Ƿ������Ҫ���)
void clean_allperson(struct AddressBooks *abs){
    // ��ϵ��������Ϊ0����һ���߼��ϵ����
    abs->m_size = 0;
    system("pause");
    system("cls");

}
// ͨѶ¼����ϵͳ
int main()
{
    // �����û�����ı���
    int select = 0;
    // �����ṹ�����
    struct AddressBooks abs;
    // ��ʼ��ͨѶ¼����
    abs.m_size = 0;


    while (true)
    {
        // չʾ�˵���Ŀ
        show_menu();

        // �û�ѡ��
        cin >> select;
        switch (select)
        {
            // 1.�����ϵ��
            case 1:
                // ��ַ����
                addPerson(&abs);
                break;
                // 2.��ʾ��ϵ��
            case 2:
                show_person(&abs);
                break;
                // 3.ɾ����ϵ��
            case 3:
                del_person(&abs);
                break;
                // 4.������ϵ��
            case 4:
                select_person(&abs);
                break;
                // 5.�޸���ϵ��
            case 5:
                modify_person(&abs);
                break;
                // 6.�����ϵ��
            case 6:
                clean_allperson(&abs);
                break;

                // �˳�ͨѶ¼
            case 0:
                cout << "���˳�����ӭ�´�ʹ�ã�" << endl;
                system("pause");
                break;

            default:break;
        }

    }

    return 0;
}