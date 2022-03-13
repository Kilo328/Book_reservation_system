#pragma once
#include"Ordermanage.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Bookmanage.h"
using namespace std;
//构造函数
Ordermanage::Ordermanage() {}
//查看所有预约情况
void Ordermanage::checkall()
{
	//使用迭代器遍历容器，如果审核状态为0就打印
	Loadorder();
	int num = 0;
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		if (it->status == 0)
		{
			cout << "预约人学号：" << it->account << " 预约书编号：" << it->num << " 预约书名称：" << it->bookname << " 预约书作者：" << it->aname << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "暂无待审核的预约!" << endl;
}
//查看指定人的预约情况
void Ordermanage::checkperson()
{
	string account_;
	cout << "请输入被查找者的学号:" << endl;
	cin >> account_;
	Loadorder();
	int num = 0;
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		if (it->account == account_)
		{
			cout << "预约人学号：" << it->account << " 预约书编号：" << it->num << " 预约书名称：" << it->bookname << " 预约书作者：" << it->aname << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "该学生暂无预约情况!" << endl;
}
//查看指定书的预约情况
void Ordermanage::checkbook()
{
	string num_;
	cout << "请输入被查找书的编号:" << endl;
	cin >> num_;
	Loadorder();
	int num = 0;
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		if (it->num == num_)
		{
			cout << "预约人学号：" << it->account << " 预约书编号：" << it->num << " 预约书名称：" << it->bookname << " 预约书作者：" << it->aname << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "该书暂无预约情况!" << endl;
}
//预约申请
void Ordermanage::applyorder()
{
	string num_;
	Student s;
	cout << "请输入预约人的学号:" << endl;
	cin >> s.account;
	cout << "请输入预约人的密码:" << endl;
	cin >> s.password;
	Usermanage um;
	um.Loadstudent();
	if (um.find_student(s))
	{
		cout << "验证成功！" << endl;
		system("cls");
		cout << "请输入预约书的编号" << endl;
		cin >> num_;
		Bookmanage m;
		m.Loadbook();
		ofstream ofs;
		for (vector<Book>::iterator it = m.book_.begin(); it != m.book_.end(); it++)
		{
			if (it->num == num_)
			{
				if (it->size == 0)
				{
					cout << "该书容量已空，无法预约!" << endl;
				}
				else
				{
					ofs.open("order.txt", ios::out | ios::app);
					if (!ofs.is_open())
					{
						cout << "文件打开失败!";
						return;
					}
					ofs <<s.account<<" " << it->num << " " << it->name << " " << it->aname << " " << 0 << endl;
					ofs.close();
					//预约成功后将book文本中对应书的容量减1
					Book b;
					b.name = it->name;
					b.num = it->num;
					b.aname = it->aname;
					b.size = (it->size) - 1;
					it = m.book_.erase(it);
					m.book_.push_back(b);
					m.Savebook();
					cout << "预约成功!" << endl;
					break;
				}
			}
			if (it + 1 == m.book_.end() && it->num != num_)
			{
				cout << "图书馆内无此编号的书!" << endl;
			}
		}
	}
	else
	{
		cout << "账号或密码错误！" << endl;
	}

}
//预约审核
void Ordermanage::examineorder()
{
	int num = 0;
	Loadorder();
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		if (it->status == 0)
		{
			num++;
			cout << "预约人学号：" << it->account << " 预约书编号：" << it->num << " 预约书名称：" << it->bookname << " 预约书作者：" << it->aname << endl;
			int key = 0;
			cout << "是否同意该预约?(同意输入‘1’，拒绝输入‘2’)" << endl;
			cin >> key;
			if (key == 1)
			{
				it->status=true;
				Saveorder();
			}
			else if(key==2)
			{
				string num_ = it->num;
				//将预约减少的容量加回来
				Bookmanage m;
				m.Loadbook();
				for (vector<Book>::iterator its = m.book_.begin(); its != m.book_.end(); its++)
				{
					if (its->num == num_)
					{
						Book b;
						b.name = its->name;
						b.num = its->num;
						b.aname = its->aname;
						b.size = (its->size) + 1;
						its = m.book_.erase(its);
						m.book_.push_back(b);
						m.Savebook();
						break;
					}
				}
				it = order_.erase(it);//迭代器指向位置不变，下一个元素前移，相当于迭代器指向被删除的下一个元素，因此做it--
				Saveorder();
				if (it == order_.end())
					break;
				else if (it == order_.begin())
				{
					if (it->status == 0)
					{
						num++;
						cout << "预约人学号：" << it->account << " 预约书编号：" << it->num << " 预约书名称：" << it->bookname << " 预约书作者：" << it->aname << endl;
						int key = 0;
						cout << "是否同意该预约?(同意输入‘1’，拒绝输入‘2’)" << endl;
						cin >> key;
						if (key == 1)
						{
							it->status = true;
							Saveorder();
						}
						else if (key == 2)
						{
							string num_ = it->num;
							//将预约减少的容量加回来
							Bookmanage m;
							m.Loadbook();
							for (vector<Book>::iterator its = m.book_.begin(); its != m.book_.end(); its++)
							{
								if (its->num == num_)
								{
									Book b;
									b.name = its->name;
									b.num = its->num;
									b.aname = its->aname;
									b.size = (its->size) + 1;
									its = m.book_.erase(its);
									m.book_.push_back(b);
									m.Savebook();
									break;
								}
							}
							it = order_.erase(it);
							Saveorder();
							if (it == order_.end())
								break;
						}
						else
						{
							cout << "输入有误!" << endl;
						}
					}
				}
				it--;
			}

		}
		if (num == 0)
			cout << "暂无待审核预约!" << endl;
		system("cls");
	}
}
//从文本中读入预约容器
void Ordermanage::Loadorder()
{
	order_.clear();
	ifstream ifs;
	Order o;
	ifs.open("order.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (ifs>>o.account&&ifs >> o.num && ifs >> o.bookname && ifs >> o.aname && ifs >> o.status)
	{
		order_.push_back(o);
	}
	ifs.close();
}
//从容器中写入文本
void  Ordermanage::Saveorder()
{
	ofstream ofs;
	ofs.open("order.txt", ios::trunc | ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		ofs << it->account << " " << it->num << " " <<it->bookname<<" " << it->aname << " " << it->status << endl;
	}
	ofs.close();
}