#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"User.h"
#include<fstream>
#include"Usermanage.h"
using namespace std;
class admin :public User
{
public:
	//���캯��
	admin(string _account, string _pasw);
    admin() {}
	//��¼����
	bool login();
	//����=�����
	bool operator==(const admin &adm);
	//���溯������
	void menu();
	//����û�
	void adduser();
	//ɾ���û�
	void deluser();

private:

};