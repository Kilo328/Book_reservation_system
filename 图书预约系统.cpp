#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"User.h"
#include"Order.h"
#include"Bookmanage.h"
#include"Teacher.h"
#include"Student.h"
#include"Book.h"
#include"admin.h"
#include"Usermanage.h"
using namespace std;
//���ɲ˵�
void createmenu()
{
	int key = 0;
	while (true)
	{
		cout << "  --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                   ��ӭ����ͼ��ԤԼϵͳ                       |" << endl;
		cout << "|������������ݣ�                                              |" << endl;
		cout << "|            1��ѧ��                                           |" << endl;
		cout << "|            2����ʦ                                           |" << endl;
		cout << "|            3������Ա                                         |" << endl;
		cout << "|            0���˳�                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		switch (key)
		{
		case 1://ѧ��
		{
			Student s;
			if (s.login())
			{
				system("pause");
				system("cls");
				s.menu();
			}
			system("cls");
		    break; 
		}
		case 2://��ʦ
		{
			Teacher t;
			if (t.login())
			{
				system("pause");
				system("cls");
				t.menu();
			}
			system("cls");
			break;
		}
		case 3://����Ա
		{
			admin adm;
			if (adm.login())
			{
				system("pause");
				system("cls");
				adm.menu();
			}
			system("cls");
			break;
		}
		case 0://�˳�
			cout<<"��ӭ���ٴ�ʹ�ã��ټ���"<<endl;
			system("pause");
			return;
		default://����
			cout << "�����������������롣" <<endl;
			system("pause");
			system("cls");
			break;
		}
	}

}
int main()
{
    createmenu();
	return 0;
}