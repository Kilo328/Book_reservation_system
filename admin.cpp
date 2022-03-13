#pragma once
#include"admin.h"
using namespace std;
//���캯��
admin::admin(string _account, string _pasw):User(_account, _pasw, "����Ա")
{
	account = _account;
	password = _pasw;
}

//����û�
void admin::adduser()
{
	int key = 0;
	while (true)
	{
		cout << "  --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|  ����������û�����ݣ�                                      |" << endl;
		cout << "|            1��ѧ��                                           |" << endl;
		cout << "|            2����ʦ                                           |" << endl;
		cout << "|            0���˳�                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)//ѧ��
		{
			string account_t;
			string pasw_t;
			string name_t;
			cout << "����������" << endl;
			cin >> name_t;
			cout << "������ѧ��" << endl;
			cin >> account_t;
			//����
			Usermanage um;
			um.Loadstudent();
			for (vector<Student>::iterator it = um.student_.begin(); it != um.student_.end(); it++)
			{
				if (it->account == account_t)
				{
					cout << "��ѧ���Ѵ���!" << endl;
					return;
				}
			}
			cout << "����������" << endl;
			cin >> pasw_t;
			ofstream ofs;
			ofs.open("student.txt", ios::out | ios::app);
			if (!ofs.is_open())
			{
				cout << "�ļ���ʧ��" << endl;
				return;
			}
			ofs <<name_t<<" " << account_t << " " << pasw_t << endl;
			cout << "��ӳɹ���" << endl;
			ofs.close();
			system("pause");
			system("cls");
		}
		else if (key == 2)//��ʦ
		{
			string account_t;
			string pasw_t;
			string name_t;
			cout << "����������" << endl;
			cin >> name_t;
			cout << "������ѧ����" << endl;
			cin >> account_t;
			//����
			Usermanage um;
			um.Loadteacher();
			for (vector<Teacher>::iterator it = um.teacher_.begin(); it != um.teacher_.end(); it++)
			{
				if (it->account == account_t)
				{
					cout << "��ѧ�����Ѵ���!" << endl;
					return;
				}
			}
			cout << "����������" << endl;
			cin >> pasw_t;
			ofstream ofs;
			ofs.open("teacher.txt", ios::out | ios::app);
			if (!ofs.is_open())
			{
				cout << "�ļ���ʧ��" << endl;
				return;
			}
			ofs << name_t << " " << account_t << " " << pasw_t << endl;
			cout << "��ӳɹ���" << endl;
			ofs.close();
			system("pause");
			system("cls");
		}
		else if (key == 0)//�˳�
		{
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return;
		}
		else//�������
		{
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
		}
	}
}

//��¼����
bool admin::login()
{
	admin adm;
	cout << "�����������˺�:" << endl;
	cin >> adm.account;
	cout << "��������������:" << endl;
	cin >> adm.password;
	Usermanage m;
	m.Loadadmin();
	if (m.find_admin(adm))
	{
		cout << "��¼�ɹ���" << endl;
		return true;
	}
	else
	{
		cout << "�˺Ż��������" << endl;
		system("pause");
		return false;
	}
}
//����=�����
bool admin::operator==(const admin &adm)
{
	if ((adm.account == account) && (adm.password == password))
		return true;
	else
		return false;

}
//���溯������
void admin::menu()
{
	while (true)
	{
		int key = 0;
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                         ����Ա�˵�                           |" << endl;
		cout << "|���������Ĳ�����                                              |" << endl;
		cout << "|            1������û�                                       |" << endl;
		cout << "|            2��ɾ���û�                                       |" << endl;
		cout << "|            0���˳�                                           |" << endl;
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//ɾ���û������û�����ϵͳ
	void admin::deluser() 
	{
		int key = 0;
		while (true)
		{
			cout << "  --------------------------------------------------------------" << endl;
			cout << "|                                                              |" << endl;
			cout << "|  ������ɾ���û�����ݣ�                                      |" << endl;
			cout << "|            1��ѧ��                                           |" << endl;
			cout << "|            2����ʦ                                           |" << endl;
			cout << "|            0���˳�                                           |" << endl;
			cout << "|                                                              |" << endl;
			cout << " --------------------------------------------------------------" << endl;
			cin >> key;
			if (key == 1)//ѧ��
			{
				Usermanage m;
				m.Loadstudent();
				m.del_student();
				system("pause");
				system("cls");
			}
			else if (key == 2)//��ʦ
			{

				Usermanage m;
				m.Loadteacher();
				m.del_teacher();
				system("pause");
				system("cls");
			}
			else if (key == 0)//�˳�
			{
				cout << "��ӭ�´�ʹ�ã�" << endl;
				return;
			}
			else//�������
			{
				cout << "�����������������룡" << endl;
				system("pause");
				system("cls");
			}
		}
	}