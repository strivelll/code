#include "workermanager.h"
workermanager::workermanager(){
	ifstream ifs;
	this->emparray = new worker*[100];
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		this->emparray = NULL;
		this->empnum = 0;
		ifs.close();
		return;
	}
	if (ifs.eof()) {
		cout << "�ļ�Ϊ�գ�" << endl;
		this->emparray = NULL;
		this->empnum = 0;
		ifs.close();
		return;
	}
	int pnum = 0,id,did;
	string name;
	int i = 0;
	worker* w ;
	while (ifs >> id && ifs >> name && ifs >> did) {
		pnum++;
		if (did == 1) {
			 w = new common_worker(id, name, did);
		}
		else if (did == 2) {
			 w = new manager_worker(id, name, did);
		}
		else {
			 w = new boss_worker(id, name, did);
		}
		if(i<=100)
		this->emparray[i] = w;
		else {
			worker** wk = new worker * [100 + i];
			for (int j = 0; j < i; j++) {
				wk[j] = this->emparray[j];
			}
		}
		i++;
	}
	this->empnum = pnum;
	return;
}
void workermanager::show_menu() {
	cout << "****************************************" << endl;
	cout << "*********��ӭʹ��ְ������ϵͳ��*********" << endl;
	cout << "************0.�˳��������**************" << endl;
	cout << "************1.����ְ����Ϣ**************" << endl;
	cout << "************2.��ʾְ����Ϣ**************" << endl;
	cout << "************3.ɾ����ְְ��**************" << endl;
	cout << "************4.�޸�ְ����Ϣ**************" << endl;
	cout << "************5.����ְ����Ϣ**************" << endl;
	cout << "************6.���ձ������**************" << endl;
	cout << "************7.��������ĵ�**************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
void common_worker::showinfo() {
	cout << "ְ����ţ�" << this->mid
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ����ɾ��������" << endl;
}
string common_worker::getdeptname() {
	return string("Ա��");
}
common_worker::common_worker(int id, string name, int did){
	this->mid = id;
	this->name = name;
	this->mdeptid = did;
}
void manager_worker:: showinfo() {
	cout << "ְ����ţ�" << this->mid
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ������ϰ��µ����񣬸�Ա��������" << endl;
}
string manager_worker::getdeptname() {
	return string("����");
}
manager_worker::manager_worker(int id, string name, int did) {
	this->mid = id;
	this->name = name;
	this->mdeptid = did;
}
void boss_worker::showinfo() {
	cout << "ְ����ţ�" << this->mid
		<< " \tְ��������" << this->name
		<< " \t��λ��" << this->getdeptname()
		<< " \t��λְ�𣺹������е�����" << endl;
}
boss_worker::boss_worker(int id, string name, int did) {
	this->mid = id;
	this->name = name;
	this->mdeptid = did;
}
string boss_worker::getdeptname() {
	return string("�ϰ�");
}
void workermanager::add_worker() {
	int num,i;
	cout << "����������Ҫ���ӵ�����:>" << endl;
	cin >> num;
	if (num > 0) {
		int newnum = this->empnum + num;
		worker** wk = new worker*[newnum];
		for (i = 0; i < this->empnum; i++) {
			wk[i] = this->emparray[i];
		}
		for (int j = 0; j < num; j++) {
			int id,did;
			string name1;
			cout << "�������" << j + 1 << "λ��ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << j + 1 << "λ��ְ��������" << endl;
			cin >> name1;
			cout << "���������λ��" << endl;
			cin >> did;
			switch (did)
			{
			case 1:
			{
				wk[i++] = new common_worker(id, name1, did);
				break;
			}
			case 2:
			{
				wk[i++] = new manager_worker(id, name1, did);
				break;
			}
			case 3:
			{
				wk[i++] = new boss_worker(id, name1, did);
				break;
			}
			default:
				break;
			}
		}
		if (this->emparray != NULL) {
			delete[] this->emparray;
			this->emparray = NULL;
		}
		this->emparray = wk;
		this->empnum = newnum;
		cout << "�ɹ����" << num << "����Ա��" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
}
void workermanager::save() {
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	for (int i = 0; i < this->empnum; i++) {
		ofs << this->emparray[i]->mid<<"  "
			<< this->emparray[i]->name<<"  "
			<< this->emparray[i]->mdeptid << endl;
	}
	ofs.close();
}
void workermanager::look_workers() {
	if (this->empnum <= 0) {
		cout << "���ļ������ݣ�" << endl;
		return;
	}
	for (int i = 0; i < this->empnum; i++) {
		this->emparray[i]->showinfo();
	}
}
workermanager::~workermanager() {
	if (this->emparray != NULL) {
		delete[] this->emparray;
		this->emparray = NULL;
	}
}
void workermanager::del_workers() {
	int select;
	cout << "��ѡ�����Ҫɾ��Ա���ķ�ʽ��" << endl;
	cout << "1.��������" << endl;
	cout << "2.ְ����Ų���" << endl;
	cin >> select;
	if (select == 2) {
		int del_id;
		cout << "������Ҫɾ����Ա����ţ�" << endl;
		cin >> del_id;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->mid == del_id) {
				for (int j = i; j < this->empnum - 1; j++) {
					this->emparray[j] = this->emparray[j + 1];
				}
				this->empnum--;
				cout << "ɾ���ɹ���" << endl;
				this->look_workers();
				return;
			}
		}
	}
	if (select == 1) {
		string name;
		cout << "������Ҫɾ����Ա��������" << endl;
		cin >> name;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->name == name) {
				for (int j = i; j < this->empnum - 1; j++) {
					this->emparray[j] = this->emparray[j + 1];
				}
				this->empnum--;
				cout << "ɾ���ɹ���" << endl;
				this->look_workers();
				return;
			}
		}
	}
	else {
		cout << "�������" << endl;
		return;
	}
	cout << "�����ڸñ�ŵ�Ա��" << endl;
}
void workermanager::mod_worker() {
	int mod_id;
	cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
	cin >> mod_id;
	for (int i = 0; i < this->empnum; i++) {
		if (this->emparray[i]->mid == mod_id) {
			worker* w=NULL;
			int id, did;
			string name1;
			cout << "�������޸ĺ�ı��" << endl;
			cin >> id;
			cout << "�������޸ĺ������" << endl;
			cin >> name1;
			cout << "�������޸ĺ�ĸ�λ��" << endl;
			cin >> did;
			switch (did)
			{
			case 1:
			{
				w = new common_worker(id, name1, did);
				break;
			}
			case 2:
			{
				w = new manager_worker(id, name1, did);
				break;
			}
			case 3:
			{
				w = new boss_worker(id, name1, did);
				break;
			}
			}
			this->emparray[i] = w;
			cout << "�޸ĳɹ�" << endl;
			return;
		}
	}
	cout << "�����ڸñ�ŵ�Ա��" << endl;
}
void workermanager::find_worker() {
	int select;
	cout << "��ѡ����ҷ�ʽ��" << endl;
	cout << "1.��������" << endl;
	cout << "2.ְ����Ų���" << endl;
	cin >> select;
	if (select == 2) {
		cout << "������Ҫ���ҵ�Ա����ţ�" << endl;
		int find_id;
		cin >> find_id;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->mid == find_id) {
				cout << "�ҵ��ˣ�����" << endl;
				this->emparray[i]->showinfo();
				return;
			}
		}
	}
	if (select == 1) {
		string name;
		cout << "������Ҫ���ҵ�Ա��������" << endl;
		cin >> name;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->name == name) {
				cout << "�ҵ��ˣ�����" << endl;
				this->emparray[i]->showinfo();
				return;
			}
		}
	}
	else {
		cout << "�������" << endl;
		return;
	}
	cout << "δ�ҵ���Ա��" << endl;
}
void workermanager::sort_worker() {
	if (this->empnum == 0) {
		cout << "�ļ�û������" << endl;
		return;
	}
	int select;
	cout << "��ѡ������ʽ��" << endl;
	cout << "1.��������" << endl;
	cout << "2.���Ž���" << endl;
	cin >> select;
	switch (select)
	{
	case 1 : {
		for (int i = 0; i < this->empnum; i++) {
			int min = i;
			for (int j = i ; j < this->empnum; j++) {
				if (this->emparray[min]->mid > this->emparray[j]->mid) {
					min = j;
				}
			}
			if (min != i) {
				worker* w = this->emparray[i];
				this->emparray[i] = this->emparray[min];
				this->emparray[min] = w;
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < this->empnum; i++) {
			int max = i;
			for (int j = i ; j < this->empnum; j++) {
				if (this->emparray[max]->mid < this->emparray[j]->mid) {
					max = j;
				}
			}
			if (max != i) {
				worker* w = this->emparray[i];
				this->emparray[i] = this->emparray[max];
				this->emparray[max] = w;
			}
		}
		break;
	}
	default:
		cout << "ѡ�����" << endl;
		return;
	}
	this->save();
	cout << "����ɹ�"<<endl;
}
void workermanager::clear_worker() {
	int s;
	cout << "ȷ��ɾ������������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	cin >> s;
	if (s == 2) {
		cout << "ȡ���ɹ�" << endl;
		return;
	}
	if (s == 1) {
		ofstream ofs;
		ofs.open("test.txt", ios::trunc);
		ofs.close();
		for (int i = 0; i < this->empnum; i++) {
			if(this->emparray[i]!=NULL)
			delete this->emparray[i];
		}
		delete[] this->emparray;
		this->emparray=NULL;
		this->empnum = 0;
		cout << "��ճɹ�" << endl;
	}
	else {
		cout << "�������" << endl;
	}
}