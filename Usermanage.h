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
	//构造函数
	Usermanage();
	//读取用户文本至容器中
	void Loadstudent();
	void Loadteacher();
	void Loadadmin();
	//遍历容器
	void printf_student();
	void printf_teacher();
	void printf_admin();
	//查找函数，用于查找用户输入的账号密码是否与容器中的元素匹配
	bool find_student(const Student &s);
	bool find_teacher(const Teacher &t);
	bool find_admin(const admin &adm);
	//删除容器内指定用户
	void del_student();
	void del_teacher();
	//将容器写入文本
	void Savestudent();
	void Saveteacher();
	//各用户容器
	vector<Student> student_;
	vector<Teacher> teacher_;
	vector<admin> admin_;
};