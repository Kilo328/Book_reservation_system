#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
#include"User.h"
#include"admin.h"
#include"Student.h"
#include"Teacher.h"
using namespace std;
class Student;
class Teacher;
class admin;
class Usermanage 
{
public:
	//���캯��
	Usermanage();
	//��ȡ�û��ı���������
	void Loadstudent();
	void Loadteacher();
	void Loadadmin();
	//��������
	void printf_student();
	void printf_teacher();
	void printf_admin();
	//���Һ��������ڲ����û�������˺������Ƿ��������е�Ԫ��ƥ��
	bool find_student(const Student &s);
	bool find_teacher(const Teacher &t);
	bool find_admin(const admin &adm);
	//ɾ��������ָ���û�
	void del_student();
	void del_teacher();
	//������д���ı�
	void Savestudent();
	void Saveteacher();
	//���û�����
	vector<Student> student_;
	vector<Teacher> teacher_;
	vector<admin> admin_;
};