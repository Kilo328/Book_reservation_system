#pragma once
#include"Book.h"
using namespace std;
//���캯��
Book::Book(string _name, string _num, int _size)
{
	name = _name;
	num = _num;
	size = _size;
}
//��������
void Book::addsize(int _size)
{
	size += _size;
}
//��������
void Book::delsize(int _size)
{
	size -= size;
}