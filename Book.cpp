#pragma once
#include"Book.h"
using namespace std;
//构造函数
Book::Book(string _name, string _num, int _size)
{
	name = _name;
	num = _num;
	size = _size;
}
//扩大容量
void Book::addsize(int _size)
{
	size += _size;
}
//减少容量
void Book::delsize(int _size)
{
	size -= size;
}