#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
#include"Book.h"
class Book;
using namespace std;
class Bookmanage 
{
public:
	//增加图书
	void addbook();
	//减少图书
	void delbook();
	//查找图书
	void findbook();
	//修改图书
	void resetbook();
	//从文件中读入书本容器
	void Loadbook();
	//从容器中写入文件
	void Savebook();
	//图书管理菜单
	void menu();
	vector<Book>book_;
};