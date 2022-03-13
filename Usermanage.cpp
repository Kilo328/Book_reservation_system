#pragma once
#include"Usermanage.h"
using namespace std;
class print
{
public:
	void operator()(Teacher t)
	{
		cout << t.name << " " << t.account << " " <<t.password << endl;
	}
};
//构造函数
Usermanage::Usermanage()
{

}

//读取用户文本至容器中
void Usermanage::Loadstudent()
{
	Student s;
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (ifs >> s.name && ifs >> s.account && ifs >> s.password)
	{
		student_.push_back(s);
	}
}
void Usermanage::Loadteacher()
{
	Teacher t;
	ifstream ifs;
	ifs.open("teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (ifs >> t.name && ifs >> t.account && ifs >> t.password)
	{
		teacher_.push_back(t);
	}
}
void Usermanage::Loadadmin()
{
	admin adm;
	ifstream ifs;
	ifs.open("admin.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while ( ifs >> adm.account && ifs >> adm.password)
	{
		admin_.push_back(adm);
	}
}

//利用迭代器++的方式遍历
void Usermanage::printf_student()
{
	for (vector<Student>::iterator it = student_.begin(); it != student_.end(); it++)
	{
		cout << it->name << " " << it->account << " " << it->password << endl;
	}
}

//利用仿函数和算法for_each遍历
void Usermanage::printf_teacher() 
{
	for_each(teacher_.begin(), teacher_.end(), print());
}

//利用迭代器++的方式遍历
void Usermanage::printf_admin()
{
	for (vector<admin>::iterator it = admin_.begin(); it != admin_.end(); it++)
	{
		cout << it->account << " " << it->password << endl;
	}
}

//查找函数，用于查找用户输入的账号密码是否与容器中的元素匹配
bool Usermanage::find_student(const Student &s)
{
	vector<Student>::iterator it=find(student_.begin(), student_.end(), s);
	if (it == student_.end())
		return false;
	else
		return true;
}
bool Usermanage::find_teacher(const Teacher &t)
{
	vector<Teacher>::iterator it = find(teacher_.begin(), teacher_.end(), t);
	if (it == teacher_.end())
		return false;
	else
		return true;
}
bool Usermanage::find_admin(const admin &adm)
{
	vector<admin>::iterator it = find(admin_.begin(), admin_.end(), adm);
	if (it == admin_.end())
		return false;
	else
		return true;
}

//删除容器内指定用户
void Usermanage::del_student() 
{
	Student s;
	cout << "请输入删除学生的学号:" << endl;
	cin >> s.account;
	vector<Student>::iterator it = student_.begin();
	for (; it!= student_.end(); it++)
	{
		if (it->account == s.account)
		{
			it=student_.erase(it);
			cout << "删除成功！" << endl;
			break;
		}
	}
	if (it == student_.end())
	  cout << "查无此人！"<<endl;
	Savestudent();
}
void Usermanage::del_teacher() 
{
	Teacher t;
	cout << "请输入删除老师的职工号:" << endl;
	cin >> t.account;
	vector<Teacher>::iterator it = teacher_.begin();
	for (; it != teacher_.end(); it++)
	{
		if (it->account == t.account)
		{
			it = teacher_.erase(it);
			cout << "删除成功！" << endl;
			break;
		}
	}
	if (it == teacher_.end())
		cout << "查无此人！" << endl;
	Saveteacher();
}
//将容器写入文本
void Usermanage::Savestudent()
{
	ofstream ofs;
	ofs.open("student.txt",ios::trunc|ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	for (vector<Student>::iterator it = student_.begin(); it != student_.end(); it++)
	{
		ofs << it->name << " " << it->account << " " << it->password << endl;
	}
	ofs.close();
}
void Usermanage::Saveteacher()
{
	ofstream ofs;
	ofs.open("teacher.txt", ios::trunc | ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	for (vector<Teacher>::iterator it = teacher_.begin(); it != teacher_.end(); it++)
	{
		ofs << it->name << " " << it->account << " " << it->password << endl;
	}
	ofs.close();
}