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
	//����ͼ��
	void addbook();
	//����ͼ��
	void delbook();
	//����ͼ��
	void findbook();
	//�޸�ͼ��
	void resetbook();
	//���ļ��ж����鱾����
	void Loadbook();
	//��������д���ļ�
	void Savebook();
	//ͼ�����˵�
	void menu();
	vector<Book>book_;
};