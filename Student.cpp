#pragma once
#include"Student.h"
using namespace std;
//构造函数
Student::Student(string _account, string _pasw, string _name):User(_account, _pasw,_name)
{
	account = _account;
	password = _pasw;
	name = _name;
}

//登录函数
bool Student::login()
{
	Student s;
	cout << "请输入您的学号:" << endl;
	cin >> s.account;
	cout << "请输入您的密码:" << endl;
	cin >> s.password;
	Usermanage m;
	m.Loadstudent();
	if (m.find_student(s))
	{
		cout << "登录成功！" << endl;
		account = s.account;
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
bool Student::operator==(const Student& s)
{
	if ((s.account == account) && (s.password == password))
		return true;
	else
		return false;

}
//界面函数
void Student::menu()
{
	while (true)
	{
		int key = 0;
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                         学生菜单                             |" << endl;
		cout << "|请输入您的操作：                                              |" << endl;
		cout << "|            1、查找图书                                       |" << endl;
		cout << "|            2、预约管理                                       |" << endl;
		cout << "|            0、退出                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)//查找图书
		{
			system("cls");
			//图书管理类操作
			Bookmanage bm;
			bm.Loadbook();
			bm.findbook();
			system("pause");
			system("cls");
		}
		else if (key == 2)//预约管理
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
				cout << "|            1、图书预约                                       |" << endl;
				cout << "|            2、查看自己预约情况                               |" << endl;
				cout << "|            3、取消审核中的预约                               |" << endl;
				cout << "|            0、退出                                           |" << endl;
				cout << "|                                                              |" << endl;
				cout << "|                                                              |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cin >> key;
				if (key == 1)
				{
					system("cls");
					Ordermanage om;
					om.orderacc = account;
					om.applyorder();
					system("pause");
					system("cls");
				}
				else if (key == 2)
				{
					system("cls");
					Usermanage m;
					m.Loadstudent();
					Ordermanage om;
					om.Loadorder();
					int num = 0;
					for (vector<Order>::iterator it = om.order_.begin(); it != om.order_.end(); it++)
					{
						if (it->account == account)
						{
							cout << "预约人学号：" << it->account << " 预约书编号：" << it->num << " 预约书名称：" << it->bookname << " 预约书作者：" << it->aname << endl;
							num++;
						}
					}
					if (num == 0)
					{
						cout << "该学生暂无预约情况!" << endl;
					}
					system("pause");
					system("cls");
				}
				else if (key == 3)
				{
					system("cls");
					Ordermanage om;
					om.Loadorder();
					int num = 0;
					for (vector<Order>::iterator it = om.order_.begin(); it != om.order_.end(); )
					{
						if (it->account == account)
						{
							num++;
							cout << "预约人学号：" << it->account << " 预约书编号：" << it->num << " 预约书名称：" << it->bookname << " 预约书作者：" << it->aname << endl;
							cout << "是否取消该预约?(是输入‘1’,否则输入其他)" << endl;
							int key_ = 0;
							cin >> key_;
							if (key_ == 1)
							{
								cout << "取消预约成功!" << endl;
								//将预定书容量加1
								Bookmanage bm;
								bm.Loadbook();
								for (vector<Book>::iterator its = bm.book_.begin(); its != bm.book_.end(); its++)
								{
									if (its->num == it->num)
									{
										Book b;
										b.name = its->name;
										b.num = its->num;
										b.aname = its->aname;
										b.size = (its->size) + 1;
										its = bm.book_.erase(its);
										bm.book_.push_back(b);
										bm.Savebook();
										break;
									}
								}
								it = om.order_.erase(it);
								om.Saveorder();
								if (it == om.order_.end())
									break;
							}
							else
							{
								it++;
								continue;
							}
						}

						if (num == 0)
							cout << "该学生暂无预约情况!" << endl;
					}
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
		}
		else if (key == 0)//退出
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
}
