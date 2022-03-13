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
	//预约的书名
	string bookname;
	//预约书的编号
	string num;
	//预约书的作者名
	string aname;
	// 预约人账号
	string account;
	//预约状态
	bool status;
};