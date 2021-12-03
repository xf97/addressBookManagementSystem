#include "features.h"

bool addPerson(addressBook * pAB){
    //返回值用来表示功能执行是否正确
    //先判断是否添加人数达到了上限
    if(pAB->nowCount > MAX_SIZE){
        cout<<"exceed the max size limit! Now the max size is "<<MAX_SIZE<<", please clean space first.";
        return false;
    }
    //姓名，性别，年龄，电话和住址
    string name;
    cout<<"please input the person's name: ";
    cin>>name;
    //性别
    int sex;
    cout<<"please input "<<name<<"'s sex (0-Male, 1-Female): ";
    cin>>sex;
    while(sex != 0 && sex != 1){
        cout<<"You enter the wrong sex code, please re-enter the correct sex code (0-Male, 1-Female): ";
        cin>>sex;
    }
    //年龄
    int age;
    cout<<"please input "<<name<<"'s age: ";
    cin>>age;
    //电话
    string phoneNumber;
    cout<<"please input "<<name<<"'s phone number: ";
    cin>>phoneNumber;
    //住址
    string address;
    cout<<"please input "<<name<<"'s address: ";
    cin>>address;
    //写入
    pAB->persons[pAB->nowCount].name = name;
    pAB->persons[pAB->nowCount].sex = Sex(sex);
    pAB->persons[pAB->nowCount].age = age;
    pAB->persons[pAB->nowCount].phoneNumber = phoneNumber;
    pAB->persons[pAB->nowCount].address = address;
    pAB->nowCount ++;
    //输出正确信息
    cout<<name<<"'s info is saved!\n";
    return true;
}

//该函数用于显示联系人
bool showPersons(const addressBook * pAB){
    if(pAB->nowCount <= 0){
        cout<<"Now this address book is empty, no one is recorded\n";
    }
    else{
        //sort(pAB->persons, pAB->persons + pAB->nowCount);
        for(int i = 0; i < pAB->nowCount; ++ i){
            string sex = (pAB->persons[i].sex == 0) ? "Male" : "Female";
            cout<<"#Number "<<(i + 1)<<":\n";
            cout<<pAB->persons[i].name<<"'s age is "<<pAB->persons[i].age<<", sex is "<<sex<<", ";
            cout<<"and his/her phone number is "<<pAB->persons[i].phoneNumber<<", address is "<<pAB->persons[i].address<<endl;
        }
    }
    return true;
}

//-1表示不在，否则返回下标
int isPersonExist(const addressBook * pAB, const string & name){
    if(pAB->nowCount <= 0){
        return -1;
    }
    else{
        for(int i = 0; i < pAB->nowCount; ++ i){
            if(pAB->persons[i].name == name){
                return i;
            }
        }
        return -1;
    }
}

bool queryPerson(const addressBook * pAB){
    string name = "";
    cout<<"please enter the target name: ";
    cin>>name;
    int personIndex = isPersonExist(pAB, name);
    if(personIndex == -1){
        cout<<"No one in this address book is named "<<name<<", please make sure you enter the correct name.\n";
    }
    else{
        string sex = (pAB->persons[personIndex].sex == 0) ? "Male" : "Female";
        cout<<"You applied information is shown below:\n";
        cout<<pAB->persons[personIndex].name<<"'s age is "<<pAB->persons[personIndex].age<<", sex is "<<sex<<", ";
        cout<<"and his/her phone number is "<<pAB->persons[personIndex].phoneNumber<<", address is "<<pAB->persons[personIndex].address<<endl;
    }
    return true;
}

/*
该函数用于删除联系人
*/
bool deletePerson(addressBook * pAB){
    string name = "";
    cout<<"please enter the target name: ";
    cin>>name;
    int personIndex = isPersonExist(pAB, name);
    if(personIndex == -1){
        cout<<"No one in this address book is named "<<name<<", please make sure you enter the correct name.\n";
    }
    else{
        //把要删除的哥们用最后的直接覆盖，然后--就行了
        pAB->persons[personIndex] = pAB->persons[pAB->nowCount - 1];   
        pAB->nowCount --;    
        cout<<"Already delete "<<name<<"'s record.\n";    
    }
    return true;
}

bool modifyPerson(addressBook * pAB){
    string name = "";
    cout<<"please enter the target name: ";
    cin>>name;
    int personIndex = isPersonExist(pAB, name);
    if(personIndex == -1){
        cout<<"No one in this address book is named "<<name<<", please make sure you enter the correct name.\n";
    }
    else{
        //更新姓名，性别，年龄，电话和住址
        string name;
        cout<<"please input the new person's name: ";
        cin>>name;
        //性别
        int sex;
        cout<<"please input "<<name<<"'s sex (0-Male, 1-Female): ";
        cin>>sex;
        while(sex != 0 && sex != 1){
            cout<<"You enter the wrong sex code, please re-enter the correct sex code (0-Male, 1-Female): ";
            cin>>sex;
        }
        //年龄
        int age;
        cout<<"please input "<<name<<"'s age: ";
        cin>>age;
        //电话
        string phoneNumber;
        cout<<"please input "<<name<<"'s phone number: ";
        cin>>phoneNumber;
        //住址
        string address;
        cout<<"please input "<<name<<"'s address: ";
        cin>>address;
        //写入
        pAB->persons[personIndex].name = name;
        pAB->persons[personIndex].sex = Sex(sex);
        pAB->persons[personIndex].age = age;
        pAB->persons[personIndex].phoneNumber = phoneNumber;
        pAB->persons[personIndex].address = address;
        //输出正确信息
        cout<<name<<"'s info is changed!\n";
    }
    return true;
}

bool cleanPersons(addressBook * pAB){
    pAB->nowCount = 0;  //逻辑置空，并不实际上抹除信息
    cout<<"All records have been deleted!\n";
    return true;
}