#pragma once
#include "iostream"
using namespace std;
template<class T>
class MyArray
{
public:
    // 有参构造函数，将私有的三个变量初始化
    MyArray(int capacity)
    {
        //  cout << "有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        // 深拷贝
        this->pAddress = new T[this->m_Capacity];
    }
    // 拷贝构造函数,深拷贝，同样需要初始化
    MyArray(const MyArray & myArray)
    {
        this->m_Capacity = myArray.m_Capacity;
        this->m_Size = myArray.m_Size;
        // 深拷贝
        this->pAddress = new T[myArray.m_Capacity];

        // 遍历数组，将数组中的数值都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = myArray.pAddress[i];
        }
    }

    // 定义operator=，同样为了防止浅拷贝的问题
    MyArray & operator=(const MyArray & myArray)
    {
        // 先判断原来堆区是否有数据
        if(this->pAddress != NULL)
        {
            //  cout << "运算符重载调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        this->m_Capacity = myArray.m_Capacity;
        this->m_Size = myArray.m_Size;
        // 深拷贝
        this->pAddress = new T[myArray.m_Capacity];
        // 遍历数组，将数组中的数值都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = myArray.pAddress[i];
        }
        return *this;
    }

    // 尾插法
    void pushBack(const T & val)
    {
        // 数组没满
        if(this->m_Capacity == this->m_Size)
        {
            cout << "数组已经满了，塞不下了！" << endl;
            return;
        }
        // 最后一个元素就是数组的size大小，作为索引就可以
        this->pAddress[this->m_Size] = val;
        // 更新数组的大小
        this->m_Size ++;
    }

    // 尾删法
    void popBack()
    {
        // 让用户访问不到最后一个元素就可以了！
        if(this->m_Size == 0)
        {
            cout << "数组都空了" << endl;
            return;
        }
        this->m_Size--;
    }

    // 通过下标的方式访问数组元素
    T & operator[](int index)
    {
        return this->pAddress[index];
    }

    // 返回数组的容量
    int getCapcity()
    {
        return this->m_Capacity;
    }

    // 返回数组的大小
    int getSize()
    {
        return this->m_Size;
    }

    // 析构，进行堆区数据的销毁
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            //  cout << "析构函数调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
    }
private:
    T * pAddress; // T类型的指针，堆区指向堆区真实的数组
    int m_Capacity; // 数组的容量
    int m_Size; // 数组大小
};