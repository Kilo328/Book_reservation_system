#pragma once
#include"Teacher.h"
using namespace std;
//���캯��
Teacher::Teacher(string _account, string _pasw, string _name):User(_account, _pasw, _name)
{
	account = _account;
	password = _pasw;
	name = _name;
}
//��¼����
bool Teacher::login()
{
	Teacher t;
	cout << "����������ְ����:" << endl;
	cin >> t.account;
	cout << "��������������:" << endl;
	cin >> t.password;
	Usermanage m;
	m.Loadteacher();
	if (m.find_teacher(t))
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
bool Teacher::operator==(const Teacher& t)
{
	if ((t.account == account) && (t.password == password))
		return true;
	else
		return false;

}
//���溯��
void Teacher::menu() 
{
	while (true)
	{
		int key = 0;
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                         ��ʦ�˵�                             |" << endl;
		cout << "|���������Ĳ�����                                              |" << endl;
		cout << "|            1��ͼ�����                                       |" << endl;
		cout << "|            2��ԤԼ����                                       |" << endl;
		cout << "|            0���˳�                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)//ͼ�����
		{
			system("cls");
			Bookmanage bm;
			//ͼ����������
			bm.menu();
			system("pause");
			system("cls");
		}
		if (key == 2)//ԤԼ����
		{
			system("cls");
			//ԤԼ���������
			while (true)
			{
				int key = 0;
				cout << " --------------------------------------------------------------" << endl;
				cout << "|                                                              |" << endl;
				cout << "|                         ԤԼ����                             |" << endl;
				cout << "|���������Ĳ�����                                              |" << endl;
				cout << "|            1���鿴����ԤԼ���                               |" << endl;
				cout << "|            2���鿴ָ���˵�ԤԼ���                           |" << endl;
				cout << "|            3���鿴ָ�����ԤԼ���                           |" << endl;
				cout << "|            4��ԤԼ���                                       |" << endl;
				cout << "|            0���˳�                                           |" << endl;
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
					cout << "��ӭ�´�ʹ�ã�" << endl;
					system("pause");
					system("cls");
					return;
				}
				else//�������
				{
					cout << "�����������������룡" << endl;
					system("pause");
					system("cls");
				}
			}
			system("pause");
			system("cls");
		}
		if (key == 0)//�˳�
		{
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//ͼ�����ͼ���������в�����

//ԤԼ����(ԤԼ��������в���)