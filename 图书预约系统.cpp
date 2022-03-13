#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"User.h"
#include"Order.h"
#include"Bookmanage.h"
#include"Teacher.h"
#include"Student.h"
#include"Book.h"
#include"admin.h"
#include"Usermanage.h"
using namespace std;
//生成菜单
void createmenu()
{
	int key = 0;
	while (true)
	{
		cout << "  --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                   欢迎进入图书预约系统                       |" << endl;
		cout << "|请输入您的身份：                                              |" << endl;
		cout << "|            1、学生                                           |" << endl;
		cout << "|            2、老师                                           |" << endl;
		cout << "|            3、管理员                                         |" << endl;
		cout << "|            0、退出                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		switch (key)
		{
		case 1://学生
		{
			Student s;
			if (s.login())
			{
				system("pause");
				system("cls");
				s.menu();
			}
			system("cls");
		    break; 
		}
		case 2://老师
		{
			Teacher t;
			if (t.login())
			{
				system("pause");
				system("cls");
				t.menu();
			}
			system("cls");
			break;
		}
		case 3://管理员
		{
			admin adm;
			if (adm.login())
			{
				system("pause");
				system("cls");
				adm.menu();
			}
			system("cls");
			break;
		}
		case 0://退出
			cout<<"欢迎您再次使用，再见！"<<endl;
			system("pause");
			return;
		default://其他
			cout << "输入有误，请重新输入。" <<endl;
			system("pause");
			system("cls");
			break;
		}
	}

}
int main()
{
    createmenu();
	return 0;
}