#pragma once
#include"Order.h"
using namespace std;
Order::Order(string bookname_, string num_, string aname_,string account_)
{
	bookname = bookname_;
	num = num_;
	aname = aname_;
	account = account_;
}
Order::Order()
{

}