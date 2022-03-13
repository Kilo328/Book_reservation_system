#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"Student.h"
using namespace std;
class Student;
class Book
{
public:
	//构造函数
	Book(string _name,string _num,int _size=0);
	Book() {}
	//扩大容量
	void addsize(int _size);
	//减少容量
	void delsize(int _size);
	//容量
	int size = 0;
	//图书名称
	string name;
	//图书编号
	string num;
	//作者名称
	string aname;

};