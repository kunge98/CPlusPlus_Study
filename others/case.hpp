#pragma once
#include "iostream"
using namespace std;
template<class T>
class MyArray
{
public:
    // �вι��캯������˽�е�����������ʼ��
    MyArray(int capacity)
    {
        //  cout << "�вι������" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        // ���
        this->pAddress = new T[this->m_Capacity];
    }
    // �������캯��,�����ͬ����Ҫ��ʼ��
    MyArray(const MyArray & myArray)
    {
        this->m_Capacity = myArray.m_Capacity;
        this->m_Size = myArray.m_Size;
        // ���
        this->pAddress = new T[myArray.m_Capacity];

        // �������飬�������е���ֵ����������
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = myArray.pAddress[i];
        }
    }

    // ����operator=��ͬ��Ϊ�˷�ֹǳ����������
    MyArray & operator=(const MyArray & myArray)
    {
        // ���ж�ԭ�������Ƿ�������
        if(this->pAddress != NULL)
        {
            //  cout << "��������ص���" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        this->m_Capacity = myArray.m_Capacity;
        this->m_Size = myArray.m_Size;
        // ���
        this->pAddress = new T[myArray.m_Capacity];
        // �������飬�������е���ֵ����������
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = myArray.pAddress[i];
        }
        return *this;
    }

    // β�巨
    void pushBack(const T & val)
    {
        // ����û��
        if(this->m_Capacity == this->m_Size)
        {
            cout << "�����Ѿ����ˣ��������ˣ�" << endl;
            return;
        }
        // ���һ��Ԫ�ؾ��������size��С����Ϊ�����Ϳ���
        this->pAddress[this->m_Size] = val;
        // ��������Ĵ�С
        this->m_Size ++;
    }

    // βɾ��
    void popBack()
    {
        // ���û����ʲ������һ��Ԫ�ؾͿ����ˣ�
        if(this->m_Size == 0)
        {
            cout << "���鶼����" << endl;
            return;
        }
        this->m_Size--;
    }

    // ͨ���±�ķ�ʽ��������Ԫ��
    T & operator[](int index)
    {
        return this->pAddress[index];
    }

    // �������������
    int getCapcity()
    {
        return this->m_Capacity;
    }

    // ��������Ĵ�С
    int getSize()
    {
        return this->m_Size;
    }

    // ���������ж������ݵ�����
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            //  cout << "������������" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
    }
private:
    T * pAddress; // T���͵�ָ�룬����ָ�������ʵ������
    int m_Capacity; // ���������
    int m_Size; // �����С
};