#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class User
{
public:
	//���캯��
	User(string _account, string _pasw, string _name);
	User() {};
	//�˺�
	string account;
	//����
	string password;
	//����
	string name;
};