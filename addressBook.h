#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <string>

using namespace std;

/*
该头文件用于定义联系人和通讯录结构体
通讯录限定最大人数1000
*/

const int MAX_SIZE = 1000;

enum Sex {Male, Female};    //使用枚举类型来限定性别的取值

struct Person{
    string name;   //姓名
    Sex sex;    //性别，m男f女
    int age;    //年龄
    string phoneNumber; //电话号码
    string address;     //住址
    //重载一个比较函数
    bool operator<(const Person & anotherPerson) const{
        return name < anotherPerson.name;
    };
    bool operator==(const Person & anotherPerson) const{
        return name == anotherPerson.name || sex == anotherPerson.sex || age == anotherPerson.age || phoneNumber == anotherPerson.phoneNumber || address == anotherPerson.address;
    }
};

struct addressBook{
    Person persons[MAX_SIZE];
    int nowCount = 0;   //当前人数值，给定了默认人数
};

#endif