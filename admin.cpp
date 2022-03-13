#pragma once
#include"admin.h"
using namespace std;
//构造函数
admin::admin(string _account, string _pasw):User(_account, _pasw, "管理员")
{
	account = _account;
	password = _pasw;
}

//添加用户
void admin::adduser()
{
	int key = 0;
	while (true)
	{
		cout << "  --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|  请输入添加用户的身份：                                      |" << endl;
		cout << "|            1、学生                                           |" << endl;
		cout << "|            2、老师                                           |" << endl;
		cout << "|            0、退出                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)//学生
		{
			string account_t;
			string pasw_t;
			string name_t;
			cout << "请输入姓名" << endl;
			cin >> name_t;
			cout << "请输入学号" << endl;
			cin >> account_t;
			//查重
			Usermanage um;
			um.Loadstudent();
			for (vector<Student>::iterator it = um.student_.begin(); it != um.student_.end(); it++)
			{
				if (it->account == account_t)
				{
					cout << "该学号已存在!" << endl;
					return;
				}
			}
			cout << "请输入密码" << endl;
			cin >> pasw_t;
			ofstream ofs;
			ofs.open("student.txt", ios::out | ios::app);
			if (!ofs.is_open())
			{
				cout << "文件打开失败" << endl;
				return;
			}
			ofs <<name_t<<" " << account_t << " " << pasw_t << endl;
			cout << "添加成功！" << endl;
			ofs.close();
			system("pause");
			system("cls");
		}
		else if (key == 2)//老师
		{
			string account_t;
			string pasw_t;
			string name_t;
			cout << "请输入姓名" << endl;
			cin >> name_t;
			cout << "请输入学工号" << endl;
			cin >> account_t;
			//查重
			Usermanage um;
			um.Loadteacher();
			for (vector<Teacher>::iterator it = um.teacher_.begin(); it != um.teacher_.end(); it++)
			{
				if (it->account == account_t)
				{
					cout << "该学工号已存在!" << endl;
					return;
				}
			}
			cout << "请输入密码" << endl;
			cin >> pasw_t;
			ofstream ofs;
			ofs.open("teacher.txt", ios::out | ios::app);
			if (!ofs.is_open())
			{
				cout << "文件打开失败" << endl;
				return;
			}
			ofs << name_t << " " << account_t << " " << pasw_t << endl;
			cout << "添加成功！" << endl;
			ofs.close();
			system("pause");
			system("cls");
		}
		else if (key == 0)//退出
		{
			cout << "欢迎下次使用！" << endl;
			return;
		}
		else//输入错误
		{
			cout << "输入有误！请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
}

//登录函数
bool admin::login()
{
	admin adm;
	cout << "请输入您的账号:" << endl;
	cin >> adm.account;
	cout << "请输入您的密码:" << endl;
	cin >> adm.password;
	Usermanage m;
	m.Loadadmin();
	if (m.find_admin(adm))
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
bool admin::operator==(const admin &adm)
{
	if ((adm.account == account) && (adm.password == password))
		return true;
	else
		return false;

}
//界面函数重载
void admin::menu()
{
	while (true)
	{
		int key = 0;
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                         管理员菜单                           |" << endl;
		cout << "|请输入您的操作：                                              |" << endl;
		cout << "|            1、添加用户                                       |" << endl;
		cout << "|            2、删除用户                                       |" << endl;
		cout << "|            0、退出                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)
		{
			system("cls");
			adduser();
			system("pause");
			system("cls");
		}
		if (key == 2)
		{
			system("cls");
			deluser();
			system("pause");
			system("cls");
		}
		if (key == 0)
		{
			cout << "欢迎下次使用！" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//删除用户利用用户管理系统
	void admin::deluser() 
	{
		int key = 0;
		while (true)
		{
			cout << "  --------------------------------------------------------------" << endl;
			cout << "|                                                              |" << endl;
			cout << "|  请输入删除用户的身份：                                      |" << endl;
			cout << "|            1、学生                                           |" << endl;
			cout << "|            2、老师                                           |" << endl;
			cout << "|            0、退出                                           |" << endl;
			cout << "|                                                              |" << endl;
			cout << " --------------------------------------------------------------" << endl;
			cin >> key;
			if (key == 1)//学生
			{
				Usermanage m;
				m.Loadstudent();
				m.del_student();
				system("pause");
				system("cls");
			}
			else if (key == 2)//老师
			{

				Usermanage m;
				m.Loadteacher();
				m.del_teacher();
				system("pause");
				system("cls");
			}
			else if (key == 0)//退出
			{
				cout << "欢迎下次使用！" << endl;
				return;
			}
			else//输入错误
			{
				cout << "输入有误！请重新输入！" << endl;
				system("pause");
				system("cls");
			}
		}
	}