#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"User.h"
#include"Usermanage.h"
#include"Bookmanage.h"
#include"Ordermanage.h"
using namespace std;
class Student:public User
{
public:
	//���캯��
	Student(string _account,string _pasw,string _name);
	Student() {}
	//��¼����
	bool login();
	//����=�����
	bool operator==(const Student &s);
	//���溯��
	void menu();
	//ͼ�����ͼ���������в�����

	//ԤԼ����(ԤԼ��������в���)

private:
};