#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"User.h"
#include"Usermanage.h"
#include"Bookmanage.h"
using namespace std;
class Teacher :public User
{
public:
	//���캯��
	Teacher(string _account, string _pasw, string _name);
	Teacher() {}
	//��¼����
	bool login();
	//����=�����
	bool operator==(const Teacher &t);
	//���溯��
	void menu();
	//ͼ�����ͼ���������в�����

	//ԤԼ����(ԤԼ��������в���)

private:

};