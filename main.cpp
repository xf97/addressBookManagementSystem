#include "headsFile.h"

/*
通讯录管理系统，该案例用于联系之前学过的C++基础
包含新建、查看、删除、查询、清空、退出等功能
*/

int main(){
    //cout<<"Hello world.\n";
    int choice = -1; //用户选择
    //创建通讯录
    addressBook ab;
    while(choice != 0){
        showMenu(); //显示菜单
        cin>>choice;
        bool result = false;
        if(choice == 0){
            break;
        }
        switch(choice){
            case 1:
                result = addPerson(&ab);   //添加联系人
                break;
            case 2:
                result = showPersons(&ab);  //显示联系人
                break;
            case 3:
                result = deletePerson(&ab);    //删除联系人
                break;
            case 4:
                result = queryPerson(&ab);     //查询联系人
                break;
            case 5:
                result = modifyPerson(&ab);    //修改联系人
                break;
            case 6:
                result = cleanPersons(&ab);     //清空联系人
                break;
            default:
                cout<<"you enter wrong number, please re-enter number\n";
                break;
        };
        if(result == false && choice != 0){
            cout<<"Something wrong.\n";
        }
        system("pause");
        system("cls");
    }
    cout<<"Now you have quitted the system.\n";
    system("pause");
    return 0;
}