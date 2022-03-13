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
	//构造函数
	admin(string _account, string _pasw);
    admin() {}
	//登录函数
	bool login();
	//重载=运算符
	bool operator==(const admin &adm);
	//界面函数重载
	void menu();
	//添加用户
	void adduser();
	//删除用户
	void deluser();

private:

};