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
	//构造函数
	Teacher(string _account, string _pasw, string _name);
	Teacher() {}
	//登录函数
	bool login();
	//重载=运算符
	bool operator==(const Teacher &t);
	//界面函数
	void menu();
	//图书管理（图书管理类进行操作）

	//预约管理(预约管理类进行操作)

private:

};