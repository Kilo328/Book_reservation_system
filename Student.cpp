#pragma once
#include"Student.h"
using namespace std;
//���캯��
Student::Student(string _account, string _pasw, string _name):User(_account, _pasw,_name)
{
	account = _account;
	password = _pasw;
	name = _name;
}

//��¼����
bool Student::login()
{
	Student s;
	cout << "����������ѧ��:" << endl;
	cin >> s.account;
	cout << "��������������:" << endl;
	cin >> s.password;
	Usermanage m;
	m.Loadstudent();
	if (m.find_student(s))
	{
		cout << "��¼�ɹ���" << endl;
		account = s.account;
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
bool Student::operator==(const Student& s)
{
	if ((s.account == account) && (s.password == password))
		return true;
	else
		return false;

}
//���溯��
void Student::menu()
{
	while (true)
	{
		int key = 0;
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                         ѧ���˵�                             |" << endl;
		cout << "|���������Ĳ�����                                              |" << endl;
		cout << "|            1������ͼ��                                       |" << endl;
		cout << "|            2��ԤԼ����                                       |" << endl;
		cout << "|            0���˳�                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)//����ͼ��
		{
			system("cls");
			//ͼ����������
			Bookmanage bm;
			bm.Loadbook();
			bm.findbook();
			system("pause");
			system("cls");
		}
		else if (key == 2)//ԤԼ����
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
				cout << "|            1��ͼ��ԤԼ                                       |" << endl;
				cout << "|            2���鿴�Լ�ԤԼ���                               |" << endl;
				cout << "|            3��ȡ������е�ԤԼ                               |" << endl;
				cout << "|            0���˳�                                           |" << endl;
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
							cout << "ԤԼ��ѧ�ţ�" << it->account << " ԤԼ���ţ�" << it->num << " ԤԼ�����ƣ�" << it->bookname << " ԤԼ�����ߣ�" << it->aname << endl;
							num++;
						}
					}
					if (num == 0)
					{
						cout << "��ѧ������ԤԼ���!" << endl;
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
							cout << "ԤԼ��ѧ�ţ�" << it->account << " ԤԼ���ţ�" << it->num << " ԤԼ�����ƣ�" << it->bookname << " ԤԼ�����ߣ�" << it->aname << endl;
							cout << "�Ƿ�ȡ����ԤԼ?(�����롮1��,������������)" << endl;
							int key_ = 0;
							cin >> key_;
							if (key_ == 1)
							{
								cout << "ȡ��ԤԼ�ɹ�!" << endl;
								//��Ԥ����������1
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
							cout << "��ѧ������ԤԼ���!" << endl;
					}
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
		}
		else if (key == 0)//�˳�
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
}
