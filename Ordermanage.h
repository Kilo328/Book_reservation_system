#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"Order.h"
#include"Student.h"
using namespace std;
class Ordermanage
{
public:
	//构造函数
	Ordermanage() ;
	//查看所有预约情况
	void checkall();
	//查看指定人的预约情况
	void checkperson();
	//查看指定书的预约情况
	void checkbook();
	//预约申请
	void applyorder();
	//预约审核
	void examineorder();
	//从文本中读入预约容器
	void Loadorder();
	//从容器中写入文本
	void Saveorder();
	//预约容器
	vector<Order>order_;
	//预约人账号
	string orderacc;
};