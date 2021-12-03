#ifndef FEATURES_H
#define FEATURES_H

/*
该头文件用于定义功能函数
*/
#include "addressBook.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool addPerson(addressBook * pAB);  //添加联系人函数

bool showPersons(const addressBook * pAB);  //显示联系人功能

int isPersonExist(const addressBook * pAB, const string & name);   //确认某个联系人是否存在

bool queryPerson(const addressBook * pAB);     //查找联系人信息功能

bool deletePerson(addressBook * pAB);   //删除联系人功能

bool modifyPerson(addressBook * pAB);   //修改联系人功能

bool cleanPersons(addressBook * pAB);   //清空联系人功能

#endif