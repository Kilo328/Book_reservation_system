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
	//���캯��
	Ordermanage() ;
	//�鿴����ԤԼ���
	void checkall();
	//�鿴ָ���˵�ԤԼ���
	void checkperson();
	//�鿴ָ�����ԤԼ���
	void checkbook();
	//ԤԼ����
	void applyorder();
	//ԤԼ���
	void examineorder();
	//���ı��ж���ԤԼ����
	void Loadorder();
	//��������д���ı�
	void Saveorder();
	//ԤԼ����
	vector<Order>order_;
	//ԤԼ���˺�
	string orderacc;
};