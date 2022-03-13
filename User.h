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
	//构造函数
	User(string _account, string _pasw, string _name);
	User() {};
	//账号
	string account;
	//密码
	string password;
	//姓名
	string name;
};