#pragma once
#include"Ordermanage.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Bookmanage.h"
using namespace std;
//���캯��
Ordermanage::Ordermanage() {}
//�鿴����ԤԼ���
void Ordermanage::checkall()
{
	//ʹ�õ���������������������״̬Ϊ0�ʹ�ӡ
	Loadorder();
	int num = 0;
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		if (it->status == 0)
		{
			cout << "ԤԼ��ѧ�ţ�" << it->account << " ԤԼ���ţ�" << it->num << " ԤԼ�����ƣ�" << it->bookname << " ԤԼ�����ߣ�" << it->aname << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "���޴���˵�ԤԼ!" << endl;
}
//�鿴ָ���˵�ԤԼ���
void Ordermanage::checkperson()
{
	string account_;
	cout << "�����뱻�����ߵ�ѧ��:" << endl;
	cin >> account_;
	Loadorder();
	int num = 0;
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		if (it->account == account_)
		{
			cout << "ԤԼ��ѧ�ţ�" << it->account << " ԤԼ���ţ�" << it->num << " ԤԼ�����ƣ�" << it->bookname << " ԤԼ�����ߣ�" << it->aname << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "��ѧ������ԤԼ���!" << endl;
}
//�鿴ָ�����ԤԼ���
void Ordermanage::checkbook()
{
	string num_;
	cout << "�����뱻������ı��:" << endl;
	cin >> num_;
	Loadorder();
	int num = 0;
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		if (it->num == num_)
		{
			cout << "ԤԼ��ѧ�ţ�" << it->account << " ԤԼ���ţ�" << it->num << " ԤԼ�����ƣ�" << it->bookname << " ԤԼ�����ߣ�" << it->aname << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "��������ԤԼ���!" << endl;
}
//ԤԼ����
void Ordermanage::applyorder()
{
	string num_;
	Usermanage um;
	um.Loadstudent();
	system("cls");
	cout << "������ԤԼ��ı��" << endl;
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
				cout << "���������ѿգ��޷�ԤԼ!" << endl;
			}
			else
			{
				ofs.open("order.txt", ios::out | ios::app);
				if (!ofs.is_open())
				{
					cout << "�ļ���ʧ��!";
					return;
				}
				ofs << orderacc << " " << it->num << " " << it->name << " " << it->aname << " " << 0 << endl;
				ofs.close();
				//ԤԼ�ɹ���book�ı��ж�Ӧ���������1
				Book b;
				b.name = it->name;
				b.num = it->num;
				b.aname = it->aname;
				b.size = (it->size) - 1;
				it = m.book_.erase(it);
				m.book_.push_back(b);
				m.Savebook();
				cout << "ԤԼ�ɹ�!" << endl;
				break;
			}
		}
		if (it + 1 == m.book_.end() && it->num != num_)
		{
			cout << "ͼ������޴˱�ŵ���!" << endl;
		}
	}
}
//ԤԼ���
void Ordermanage::examineorder()
{
	int num = 0;
	Loadorder();
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); )
	{
		if (it->status == 0)
		{
			num++;
			cout << "ԤԼ��ѧ�ţ�" << it->account << " ԤԼ���ţ�" << it->num << " ԤԼ�����ƣ�" << it->bookname << " ԤԼ�����ߣ�" << it->aname << endl;
			int key = 0;
			cout << "�Ƿ�ͬ���ԤԼ?(ͬ�����롮1�����ܾ����롮2��)" << endl;
			cin >> key;
			//key==1ʱ��״̬��Ϊtrue������
			if (key == 1)
			{
				it->status=true;
				Saveorder();
				it++;
				continue;
			}
			else if(key==2)
			{
				string num_ = it->num;
				//��ԤԼ���ٵ������ӻ���
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
				//ɾ��������ָ������ݲ�д���ĵ�
				it = order_.erase(it);
				Saveorder();
				if (it == order_.end())//�����ѱ���
					break;
				
					continue;
			}

		}
		it++;
	}
	if (num == 0)
		cout << "���޴����ԤԼ!" << endl;
}
//���ı��ж���ԤԼ����
void Ordermanage::Loadorder()
{
	order_.clear();
	ifstream ifs;
	Order o;
	ifs.open("order.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	while (ifs>>o.account&&ifs >> o.num && ifs >> o.bookname && ifs >> o.aname && ifs >> o.status)
	{
		order_.push_back(o);
	}
	ifs.close();
}
//��������д���ı�
void  Ordermanage::Saveorder()
{
	ofstream ofs;
	ofs.open("order.txt", ios::trunc | ios::out);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	for (vector<Order>::iterator it = order_.begin(); it != order_.end(); it++)
	{
		ofs << it->account << " " << it->num << " " <<it->bookname<<" " << it->aname << " " << it->status << endl;
	}
	ofs.close();
}