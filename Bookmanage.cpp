#include"Bookmanage.h"
using namespace std;
//增加图书
void Bookmanage::addbook()
{
	Loadbook();
	string num_;
	string name_;
	string size_;
	string aname_;
	ofstream ofs;
	cout << "请输入添加图书编号:" << endl;
	cin >> num_;
	//查重
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		if (it->num == num_)
		{
			cout << "编号已存在!" << endl;
			return;
		}
	}
	cout << "请输入添加图书名称:" << endl;
	cin >> name_;
	cout << "请输入添加图书作者名称:" << endl;
	cin >> aname_;
	//查重
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		if (it->name == name_&&it->aname==aname_)
		{
			cout << "该书已存在!" << endl;
			return;
		}
	}
	cout << "请输入添加图书容量:" << endl;
	cin >> size_;
	ofs.open("book.txt",ios::out|ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	ofs << num_ << " " << name_ << " " << aname_<<" " << size_ << " " << endl;
	ofs.close();
	cout << "添加成功!" << endl;
}
//删除图书
void  Bookmanage::delbook()
{
	Loadbook();
	Book b;
	cout << "请输入删除图书的编号:" << endl;
	cin >> b.num;
	vector<Book>::iterator it = book_.begin();
	for (; it != book_.end(); it++)
	{
		if (it->num == b.num)
		{
			it = book_.erase(it);
			cout << "删除成功！" << endl;
			break;
		}
	}
	if (it == book_.end())
		cout << "查无此书！" << endl;
	Savebook();
}
//查找图书
void  Bookmanage::findbook()
{
	Loadbook();
	Book b;
	cout << "请输入查找图书的书名:" << endl;
	cin >> b.name;
	int n = 0;
	system("cls");
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		if (it->name == b.name)
		{
			cout << "图书馆内收录有此书，编号：" <<it->num<<" 书名:" <<it->name<<" 作者:"<<it->aname << " 容量:" << it->size << endl;
			n++;
		}
	}
	if (n==0)
		cout << "查无此书！" << endl;
}
//修改图书
void  Bookmanage::resetbook()
{
	Loadbook();
	Book b;
	cout << "请输入修改图书的名称:" << endl;;
	cin >> b.name;
	cout << "请输入修改图书的作者名称:" << endl;
	cin >> b.aname;
	cout << "请输入新的编号:" << endl;
	cin >> b.num;
    cout << "请输入新的容量:" << endl;
	cin >> b.size;
	vector<Book>::iterator it = book_.begin();
	for (; it != book_.end(); it++)
	{
		if ((it->name == b.name)&&(it->aname==b.aname))
		{
			it = book_.erase(it);
			break;
		}
	}
	book_.push_back(b);
	Savebook();
	cout << "修改成功！" << endl;
}
//从文件中读入书本容器
void  Bookmanage::Loadbook()
{
	book_.clear();
	ifstream ifs;
	Book b;
	ifs.open("book.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (ifs >> b.num && ifs >> b.name && ifs >> b.aname && ifs >> b.size)
	{
		book_.push_back(b);
	}
	ifs.close();
}
//从容器中写入文件
void  Bookmanage::Savebook()
{
	ofstream ofs;
	ofs.open("book.txt", ios::trunc | ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		ofs << it->num << " " << it->name << " " <<it->aname << " " << it->size << endl;
	}
	ofs.close();
}
//图书管理菜单
void Bookmanage::menu()
{
	int key = 0;
	while (true)
	{
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                       图书管理菜单                           |" << endl;
		cout << "|   请输入您的操作：                                           |" << endl;
		cout << "|            1、增加图书                                       |" << endl;
		cout << "|            2、删除图书                                       |" << endl;
		cout << "|            3、查找图书                                       |" << endl;
		cout << "|            4、修改图书                                       |" << endl;
		cout << "|            0、退出                                           |" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                                                              |" << endl;
		cout << " --------------------------------------------------------------" << endl;
		cin >> key;
		if (key == 1)
		{
			addbook();
			system("pause");
			system("cls");
		}
		else if (key == 2)
		{
			delbook();
			system("pause");
			system("cls");
		}
		else if (key == 3)
		{
			findbook();
			system("pause");
			system("cls");
		}
		else if (key == 4)
		{
			resetbook();
			system("pause");
			system("cls");
		}
		else if (key == 0)//退出
		{
			cout << "欢迎下次使用！" << endl;
			return;
		}
		else//输入错误
		{
			cout << "输入有误！请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
}