#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Order 
{
public:
	Order(string bookname_, string num_, string aname,string account_);
	Order();
	//ԤԼ������
	string bookname;
	//ԤԼ��ı��
	string num;
	//ԤԼ���������
	string aname;
	// ԤԼ���˺�
	string account;
	//ԤԼ״̬
	bool status;
};