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
	//���캯��
	Book(string _name,string _num,int _size=0);
	Book() {}
	//��������
	void addsize(int _size);
	//��������
	void delsize(int _size);
	//����
	int size = 0;
	//ͼ������
	string name;
	//ͼ����
	string num;
	//��������
	string aname;

};