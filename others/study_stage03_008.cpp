#include <iostream>
#include <string>
using namespace std;
//
/*
 * 4.������󣬽�������cpp�ļ����Ǵ������������
 * 4.1��װ�������Ժ���Ϊ��Ϊһ�����壬������Ȩ�޺Ϳ���
 * �﷨��class ���� {����Ȩ�ޣ�����/��Ϊ};
 * ���е����Ժͳ�Ա��Ϊ��Ա��
 *
 * ���ַ���Ȩ�ޣ�
 *      ����Ȩ�ޣ�public �������ⶼ���Է���
 *      ����Ȩ�� protected ���ڿ��Է������ⲻ���Է���
 *      ˽��Ȩ�� private ���ڿ��Է������ⲻ���Է��ʣ�˭�������ԣ�Ȩ�����
 *
 * struct �� classΨһ����Ĭ�ϵĳ�ԱȨ�޲�һ��
 *      structĬ��Ȩ��Ϊ����public
 *      classĬ��Ȩ��Ϊ˽��private
 * ��Ա����˽�У�����װ�ĺ��ģ�
 *      ����Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
 *      ͨ�����������Ĺ����Ľӿ���ʵ�ַ�װ�����޸ĺͻ�ȡ��set�� get������
 * ��--���ļ���д��
 *      ��.h�ļ�����Ҫд�����������ֻ��Ҫ����(���������ͱ�������)�Ϳ������� void setName();
 *      ��.cpp�ļ���ֻ��Ҫʵ�־���ĺ������ں���������ǰ����� void Person::setName(){};˽�б���Ҳ��Ҫ��
 *      ��.h�ļ���д�� #program once��ֹ�ظ�����
 *      �ǵ��� cpp�ļ�����#include "xxx.h"
 *
 * */
class Person{
public:
//    set��������
    void set_name(string name){
        p_name = name;
    }
//    get��ȡ����
//    �����ı���Ҳ����ˣ�����ʵ�ʵ���Ŀ��Ҫ������
    string get_name(){
        return p_name;
    }

private:
    string p_name;
    int password;
//    ����Ȩ�������ڶ����Է��ʵ�,���������ⴴ��ʵ��������֮��ֻ���Է���public������
    void show(){
        p_name = "abc";
        password = 123;
    }
};

int main(){

    Person p;
}

