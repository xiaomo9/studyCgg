/*
通讯录管理系统
实现主要功能如下：
1、添加联系人：包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人。
2、显示联系人：显示通讯录中所有联系人信息。
3、删除联系人：按照姓名删除指定联系人。
4、查找联系人：按照姓名查找指定联系人信息。
5、修改联系人：按照姓名重新修改指定联系人信息。
6、清空联系人：清空通讯录中所有信息。
7、退出通讯录：退出当前使用的通讯录。
*/

# include <iostream>
# include<string>
using namespace std;
# define MAX 1000
# define password "123456"
// 定义联系人结构体
struct person
{
    string name;
    int sex; // 1、男  2、女
    int age;
    string phone;
    string address;
};

// 定义通讯录结构体
struct AddressBook
{
    // 定义联系人结构体数组
    struct person personArray[MAX];
    int add_size; // 通讯录实际人数
};

// 定义功能菜单函数
void showmenu()
{
    cout << "***** 通讯录管理系统 *****" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

// 定义添加联系人函数
void addperson(struct AddressBook * abs)
{
    if (abs->add_size == 1000)
    {
        cout << "人数已经超过最大限制" << endl;
        return;
    }
    else
    {
        // 姓名
        string name;
        cout << "输入姓名：" << endl;
        cin >> name;
        abs -> personArray[abs->add_size].name = name;
        // 性别
        int sex; // 1、男  2、女
        while (true) //判断是否输入有误
        {   
            cout << "输入性别：  1--男   2--女" << endl;
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs ->personArray[abs->add_size].sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！" << endl;
            }
        }
        // 年龄
        int age;
        cout << "输入年龄：" << endl;
        while (true)// 判断输入类型是否正确
        {   
            cin >> age;
            if (cin.good())
            {
                abs ->personArray[abs->add_size].age = age;
                break;
            }
            else
            {
                cout << "请输入正确的格式：" << endl;
                cin.clear(); // 这一句很总要，将cin重新标记为正确，以达到重新输入的目的 	
                while (cin.get() != '\n')		//这里清空之前cin缓冲区的数据 ,就是将缓冲区里的数据都消耗掉
			    {
                    continue;
                }
            }
        }
        //电话
        string phone;
        cout << "输入电话话码：" << endl;
        cin >> phone;
        abs ->personArray[abs->add_size].phone = phone;
        // 家庭住址
        string address;
        cout << "输入家庭住址：" << endl;
        cin >> address;
        abs ->personArray[abs ->add_size].address = address;
        abs ->add_size ++;
        cout << "联系人添加成功！" << endl;
        system("pause");
        system("cls");
    }
}


// 定义显示联系人函数
void showperson(struct AddressBook *abs)
{
    if(abs->add_size == 0)
    {
        cout << " 记录为空，无联系人信息" << endl;
    }
    else
    {
        for(int i = 0; i< abs->add_size; i++ )
        {
            cout << "姓名：" << abs->personArray[i].name << "\t"
            << "  年龄：" << abs->personArray[i].age << "\t"
            << "  性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t"//将数字性别转化为对应的男女
            << "  电话：" << abs->personArray[i].phone << "\t"
            << "  家庭地址：" << abs->personArray[i].address <<endl;
        }
    }
    system("pause");
    system("cls");
}


// 定义检测联系人是否存在函数
int Isexist(struct AddressBook *abs, string name)
{
    for (int i = 0; i< abs->add_size; i++)
    {
        if(abs->personArray[i].name == name)
        {
            return i; //返回指定联系人下标
        }
    }
    
    return -1; // 若全部遍历完还是没有找到则返回-1
}


// 定义删除联系人函数
void delperson(struct AddressBook *abs)
{
    string name;
    cout << "输入要删除联系人的姓名：" << endl;
    cin >> name;
    int idx = Isexist(abs, name);
    if (idx != -1)
    {
        for (int i = idx; i<abs->add_size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->add_size--;
        cout << "删除成功" << endl;
    }
    else 
    {
        cout << "该联系人不存在！" << endl;
    }
    system("pause");
    system("cls");
}


// 定义查找联系人函数
void findperson(struct AddressBook *abs)
{
    cout << "输入要查找联系人姓名：" << endl;
    string name;
    cin >> name;
    int idx = Isexist(abs,name);

    if (idx != -1)
    {
        cout << "姓名：" << abs->personArray[idx].name 
        << "  年龄：" << abs->personArray[idx].age
        << "  性别：" << (abs->personArray[idx].sex == 1 ? "男" : "女")
        << "  电话：" << abs->personArray[idx].phone 
        << "  家庭地址：" << abs->personArray[idx].address <<endl;
    }
    else 
    {
        cout << "该联系人不存在！" << endl;
    }
    system("pause");
    system("cls");
}


// 定义修改联系人函数
void editperson(struct AddressBook * abs)
{
    cout << "输入要修改联系人姓名：" << endl;
    string name;
    cin >> name;
    int idx = Isexist(abs,name);

    if (idx!=-1)
    {
        // 姓名
        string name;
        cout << "输入姓名：" << endl;
        cin >> name;
        abs -> personArray[idx].name = name;
        // 性别
        int sex; // 1、男  2、女
        while (true) //判断是否输入有误
        {   
            cout << "输入性别：  1--男   2--女" << endl;
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs ->personArray[idx].sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！" << endl;
            }
        }
        // 年龄
        int age;
        cout << "输入年龄：" << endl;
        while (true)// 判断输入类型是否正确
        {   
            cin >> age;
            if (cin.good())
            {
                abs ->personArray[idx].age = age;
                break;
            }
            else
            {
                cout << "请输入正确的格式：" << endl;
                cin.clear(); // 这一句很总要，将cin重新标记为正确，以达到重新输入的目的 	
                while (cin.get() != '\n')		//这里清空之前cin缓冲区的数据 ,就是将缓冲区里的数据都消耗掉
			    {
                    continue;
                }
            }
        }
        //电话
        string phone;
        cout << "输入电话话码：" << endl;
        cin >> phone;
        abs ->personArray[idx].phone = phone;
        // 家庭住址
        string address;
        cout << "输入家庭住址：" << endl;
        cin >> address;
        abs ->personArray[idx].address = address;
        cout << "修改成功！" << endl;
    }
        else 
    {
        cout << "该联系人不存在！" << endl;
    }
    system("pause");
    system("cls");
}


//定义清空函数
void clearperson(struct AddressBook *abs)
{
    cout << "请输入boot密码："<< endl;
    string numid;
    cin >> numid;

    if (numid == password)
    {
        abs->add_size = 0;
        cout << " 通讯录已经清空啦！" << endl;
    }
    else
    {
        cout << "抱歉密码错误，您没有权限执行此操作！";
    }
    system("pause");
    system("cls");

}


// 主函数
int main ()
{
    int select;
    // 初始化通讯录结构体
    struct AddressBook abs;
    abs.add_size = 0;
    while (true)
    {
        showmenu();
        cout << "输入要选择的功能：" << endl;
        cin >> select;

        //功能分支
        switch (select)
        {
        case 1: // 1、添加联系人
            addperson(&abs);
            break;
        case 2: // 2、显示联系人
            showperson(&abs);
            break;
        case 3: // 3、删除联系人
            delperson(&abs);
            break;
        case 4: // 4、查找联系人
            findperson(&abs);
            break;
        case 5: // 5、修改联系人
            editperson(&abs);
            break;
        case 6: // 6、清空联系人
            clearperson(&abs);
            break;
        case 0: // 0、退出通讯录
            cout << "欢迎您下次使用！" << endl;
            system("pause");
            return 0 ;
            break;
        default:
            break;
        }

    }
    
    system("pause");
    return 0 ;
}


