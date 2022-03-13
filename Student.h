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
	//构造函数
	Student(string _account,string _pasw,string _name);
	Student() {}
	//登录函数
	bool login();
	//重载=运算符
	bool operator==(const Student &s);
	//界面函数
	void menu();
	//图书管理（图书管理类进行操作）

	//预约管理(预约管理类进行操作)

private:
};