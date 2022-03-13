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
//���캯��
Usermanage::Usermanage()
{

}

//��ȡ�û��ı���������
void Usermanage::Loadstudent()
{
	Student s;
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
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
		cout << "�ļ���ʧ��" << endl;
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
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	while ( ifs >> adm.account && ifs >> adm.password)
	{
		admin_.push_back(adm);
	}
}

//���õ�����++�ķ�ʽ����
void Usermanage::printf_student()
{
	for (vector<Student>::iterator it = student_.begin(); it != student_.end(); it++)
	{
		cout << it->name << " " << it->account << " " << it->password << endl;
	}
}

//���÷º������㷨for_each����
void Usermanage::printf_teacher() 
{
	for_each(teacher_.begin(), teacher_.end(), print());
}

//���õ�����++�ķ�ʽ����
void Usermanage::printf_admin()
{
	for (vector<admin>::iterator it = admin_.begin(); it != admin_.end(); it++)
	{
		cout << it->account << " " << it->password << endl;
	}
}

//���Һ��������ڲ����û�������˺������Ƿ��������е�Ԫ��ƥ��
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

//ɾ��������ָ���û�
void Usermanage::del_student() 
{
	Student s;
	cout << "������ɾ��ѧ����ѧ��:" << endl;
	cin >> s.account;
	vector<Student>::iterator it = student_.begin();
	for (; it!= student_.end(); it++)
	{
		if (it->account == s.account)
		{
			it=student_.erase(it);
			cout << "ɾ���ɹ���" << endl;
			break;
		}
	}
	if (it == student_.end())
	  cout << "���޴��ˣ�"<<endl;
	Savestudent();
}
void Usermanage::del_teacher() 
{
	Teacher t;
	cout << "������ɾ����ʦ��ְ����:" << endl;
	cin >> t.account;
	vector<Teacher>::iterator it = teacher_.begin();
	for (; it != teacher_.end(); it++)
	{
		if (it->account == t.account)
		{
			it = teacher_.erase(it);
			cout << "ɾ���ɹ���" << endl;
			break;
		}
	}
	if (it == teacher_.end())
		cout << "���޴��ˣ�" << endl;
	Saveteacher();
}
//������д���ı�
void Usermanage::Savestudent()
{
	ofstream ofs;
	ofs.open("student.txt",ios::trunc|ios::out);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
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
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	for (vector<Teacher>::iterator it = teacher_.begin(); it != teacher_.end(); it++)
	{
		ofs << it->name << " " << it->account << " " << it->password << endl;
	}
	ofs.close();
}