#include"Bookmanage.h"
using namespace std;
//����ͼ��
void Bookmanage::addbook()
{
	Loadbook();
	string num_;
	string name_;
	string size_;
	string aname_;
	ofstream ofs;
	cout << "���������ͼ����:" << endl;
	cin >> num_;
	//����
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		if (it->num == num_)
		{
			cout << "����Ѵ���!" << endl;
			return;
		}
	}
	cout << "���������ͼ������:" << endl;
	cin >> name_;
	cout << "���������ͼ����������:" << endl;
	cin >> aname_;
	//����
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		if (it->name == name_&&it->aname==aname_)
		{
			cout << "�����Ѵ���!" << endl;
			return;
		}
	}
	cout << "���������ͼ������:" << endl;
	cin >> size_;
	ofs.open("book.txt",ios::out|ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	ofs << num_ << " " << name_ << " " << aname_<<" " << size_ << " " << endl;
	ofs.close();
	cout << "��ӳɹ�!" << endl;
}
//ɾ��ͼ��
void  Bookmanage::delbook()
{
	Loadbook();
	Book b;
	cout << "������ɾ��ͼ��ı��:" << endl;
	cin >> b.num;
	vector<Book>::iterator it = book_.begin();
	for (; it != book_.end(); it++)
	{
		if (it->num == b.num)
		{
			it = book_.erase(it);
			cout << "ɾ���ɹ���" << endl;
			break;
		}
	}
	if (it == book_.end())
		cout << "���޴��飡" << endl;
	Savebook();
}
//����ͼ��
void  Bookmanage::findbook()
{
	Loadbook();
	Book b;
	cout << "���������ͼ�������:" << endl;
	cin >> b.name;
	int n = 0;
	system("cls");
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		if (it->name == b.name)
		{
			cout << "ͼ�������¼�д��飬��ţ�" <<it->num<<" ����:" <<it->name<<" ����:"<<it->aname << " ����:" << it->size << endl;
			n++;
		}
	}
	if (n==0)
		cout << "���޴��飡" << endl;
}
//�޸�ͼ��
void  Bookmanage::resetbook()
{
	Loadbook();
	Book b;
	cout << "�������޸�ͼ�������:" << endl;;
	cin >> b.name;
	cout << "�������޸�ͼ�����������:" << endl;
	cin >> b.aname;
	cout << "�������µı��:" << endl;
	cin >> b.num;
    cout << "�������µ�����:" << endl;
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
	cout << "�޸ĳɹ���" << endl;
}
//���ļ��ж����鱾����
void  Bookmanage::Loadbook()
{
	book_.clear();
	ifstream ifs;
	Book b;
	ifs.open("book.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	while (ifs >> b.num && ifs >> b.name && ifs >> b.aname && ifs >> b.size)
	{
		book_.push_back(b);
	}
	ifs.close();
}
//��������д���ļ�
void  Bookmanage::Savebook()
{
	ofstream ofs;
	ofs.open("book.txt", ios::trunc | ios::out);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	for (vector<Book>::iterator it = book_.begin(); it != book_.end(); it++)
	{
		ofs << it->num << " " << it->name << " " <<it->aname << " " << it->size << endl;
	}
	ofs.close();
}
//ͼ�����˵�
void Bookmanage::menu()
{
	int key = 0;
	while (true)
	{
		cout << " --------------------------------------------------------------" << endl;
		cout << "|                                                              |" << endl;
		cout << "|                       ͼ�����˵�                           |" << endl;
		cout << "|   ���������Ĳ�����                                           |" << endl;
		cout << "|            1������ͼ��                                       |" << endl;
		cout << "|            2��ɾ��ͼ��                                       |" << endl;
		cout << "|            3������ͼ��                                       |" << endl;
		cout << "|            4���޸�ͼ��                                       |" << endl;
		cout << "|            0���˳�                                           |" << endl;
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
		else if (key == 0)//�˳�
		{
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return;
		}
		else//�������
		{
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
		}
	}
}