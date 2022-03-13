#pragma once
#include"Teacher.h"
using namespace std;
//构造函数
Teacher::Teacher(string _account, string _pasw, string _name):User(_account, _pasw, _name)
{
	account = _account;
	password = _pasw;
	name = _name;
}
//登录函数
bool Teacher::login()
{
	Teacher t;
	cout << "请输入您的职工号:" << endl;
	cin >> t.account;
	cout << "请输入您的密码:" << endl;
	cin >> t.password;
	Usermanage m;
	m.Loadteacher();
	if (m.find_teacher(t))
	{
		cout << "登录成功！" << endl;
		return true;
	}
	else
	{
		cout << "账号或密码错误！" << endl;
		system("pause");
		return false;
	}
}
//重载=运算符
bool Teacher::operator==(const Teacher& t)
{
	if ((t.account == account) && (t.password == password))
		return true;
	else
		return false;

}
//界面函数
void Teacher::menu() 
{
	while (true)
	{
		int key = 0;
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                         老师菜单                             |" << endl;
		cout << "|请输入您的操作：                                              |" << endl;
		cout << "|            1、图书管理                                       |" << endl;
		cout << "|            2、预约管理                                       |" << endl;
		cout << "|            0、退出                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)//图书管理
		{
			system("cls");
			Bookmanage bm;
			//图书管理类操作
			bm.menu();
			system("pause");
			system("cls");
		}
		if (key == 2)//预约管理
		{
			system("cls");
			//预约管理类操作
			while (true)
			{
				int key = 0;
				cout << " --------------------------------------------------------------" << endl;
				cout << "|                                                              |" << endl;
				cout << "|                         预约管理                             |" << endl;
				cout << "|请输入您的操作：                                              |" << endl;
				cout << "|            1、查看所有预约情况                               |" << endl;
				cout << "|            2、查看指定人的预约情况                           |" << endl;
				cout << "|            3、查看指定书的预约情况                           |" << endl;
				cout << "|            4、预约审核                                       |" << endl;
				cout << "|            0、退出                                           |" << endl;
				cout << "|                                                              |" << endl;
				cout << "|                                                              |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cin >> key;
				if (key == 1)
				{
					system("cls");
					Ordermanage om;
					om.checkall();
					system("pause");
					system("cls");
				}
				else if (key == 2)
				{
					system("cls");
					Ordermanage om;
					om.checkperson();
					system("pause");
					system("cls");
				}
				else if (key == 3)
				{
					system("cls");
					Ordermanage om;
					om.checkbook();
					system("pause");
					system("cls");
				}
								
				else if (key == 4)
				{
					system("cls");
					Ordermanage om;
					om.examineorder();
					system("pause");
					system("cls");
				}
				else if (key == 0)
				{
					cout << "欢迎下次使用！" << endl;
					system("pause");
					system("cls");
					return;
				}
				else//输入错误
				{
					cout << "输入有误！请重新输入！" << endl;
					system("pause");
					system("cls");
				}
			}
			system("pause");
			system("cls");
		}
		if (key == 0)//退出
		{
			cout << "欢迎下次使用！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//图书管理（图书管理类进行操作）

//预约管理(预约管理类进行操作)