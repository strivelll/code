#include "workermanager.h"
workermanager::workermanager(){
	ifstream ifs;
	this->emparray = new worker*[100];
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在：" << endl;
		this->emparray = NULL;
		this->empnum = 0;
		ifs.close();
		return;
	}
	if (ifs.eof()) {
		cout << "文件为空：" << endl;
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
	cout << "*********欢迎使用职工管理系统！*********" << endl;
	cout << "************0.退出管理程序**************" << endl;
	cout << "************1.增加职工信息**************" << endl;
	cout << "************2.显示职工信息**************" << endl;
	cout << "************3.删除离职职工**************" << endl;
	cout << "************4.修改职工信息**************" << endl;
	cout << "************5.查找职工信息**************" << endl;
	cout << "************6.按照编号排序**************" << endl;
	cout << "************7.清空所有文档**************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
void common_worker::showinfo() {
	cout << "职工编号：" << this->mid
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：完成经理的任务" << endl;
}
string common_worker::getdeptname() {
	return string("员工");
}
common_worker::common_worker(int id, string name, int did){
	this->mid = id;
	this->name = name;
	this->mdeptid = did;
}
void manager_worker:: showinfo() {
	cout << "职工编号：" << this->mid
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：完成老板下的任务，给员工下任务" << endl;
}
string manager_worker::getdeptname() {
	return string("经理");
}
manager_worker::manager_worker(int id, string name, int did) {
	this->mid = id;
	this->name = name;
	this->mdeptid = did;
}
void boss_worker::showinfo() {
	cout << "职工编号：" << this->mid
		<< " \t职工姓名：" << this->name
		<< " \t岗位：" << this->getdeptname()
		<< " \t岗位职责：管理所有的事务" << endl;
}
boss_worker::boss_worker(int id, string name, int did) {
	this->mid = id;
	this->name = name;
	this->mdeptid = did;
}
string boss_worker::getdeptname() {
	return string("老板");
}
void workermanager::add_worker() {
	int num,i;
	cout << "请输入您需要增加的人数:>" << endl;
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
			cout << "请输入第" << j + 1 << "位新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << j + 1 << "位新职工姓名：" << endl;
			cin >> name1;
			cout << "请输入其岗位：" << endl;
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
		cout << "成功添加" << num << "名新员工" << endl;
	}
	else
	{
		cout << "输入错误：" << endl;
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
		cout << "该文件无内容：" << endl;
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
	cout << "请选择查找要删除员工的方式：" << endl;
	cout << "1.姓名查找" << endl;
	cout << "2.职工编号查找" << endl;
	cin >> select;
	if (select == 2) {
		int del_id;
		cout << "请输入要删除的员工编号：" << endl;
		cin >> del_id;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->mid == del_id) {
				for (int j = i; j < this->empnum - 1; j++) {
					this->emparray[j] = this->emparray[j + 1];
				}
				this->empnum--;
				cout << "删除成功：" << endl;
				this->look_workers();
				return;
			}
		}
	}
	if (select == 1) {
		string name;
		cout << "请输入要删除的员工姓名：" << endl;
		cin >> name;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->name == name) {
				for (int j = i; j < this->empnum - 1; j++) {
					this->emparray[j] = this->emparray[j + 1];
				}
				this->empnum--;
				cout << "删除成功：" << endl;
				this->look_workers();
				return;
			}
		}
	}
	else {
		cout << "输入错误" << endl;
		return;
	}
	cout << "不存在该编号的员工" << endl;
}
void workermanager::mod_worker() {
	int mod_id;
	cout << "请输入要修改的职工编号：" << endl;
	cin >> mod_id;
	for (int i = 0; i < this->empnum; i++) {
		if (this->emparray[i]->mid == mod_id) {
			worker* w=NULL;
			int id, did;
			string name1;
			cout << "请输入修改后的编号" << endl;
			cin >> id;
			cout << "请输入修改后的姓名" << endl;
			cin >> name1;
			cout << "请输入修改后的岗位：" << endl;
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
			cout << "修改成功" << endl;
			return;
		}
	}
	cout << "不存在该编号的员工" << endl;
}
void workermanager::find_worker() {
	int select;
	cout << "请选择查找方式：" << endl;
	cout << "1.姓名查找" << endl;
	cout << "2.职工编号查找" << endl;
	cin >> select;
	if (select == 2) {
		cout << "请输入要查找的员工编号：" << endl;
		int find_id;
		cin >> find_id;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->mid == find_id) {
				cout << "找到了！！！" << endl;
				this->emparray[i]->showinfo();
				return;
			}
		}
	}
	if (select == 1) {
		string name;
		cout << "请输入要查找的员工姓名：" << endl;
		cin >> name;
		for (int i = 0; i < this->empnum; i++) {
			if (this->emparray[i]->name == name) {
				cout << "找到了！！！" << endl;
				this->emparray[i]->showinfo();
				return;
			}
		}
	}
	else {
		cout << "输入错误" << endl;
		return;
	}
	cout << "未找到该员工" << endl;
}
void workermanager::sort_worker() {
	if (this->empnum == 0) {
		cout << "文件没有内容" << endl;
		return;
	}
	int select;
	cout << "请选择排序方式：" << endl;
	cout << "1.工号升序" << endl;
	cout << "2.工号降序" << endl;
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
		cout << "选择错误" << endl;
		return;
	}
	this->save();
	cout << "排序成功"<<endl;
}
void workermanager::clear_worker() {
	int s;
	cout << "确认删除所有数据吗？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	cin >> s;
	if (s == 2) {
		cout << "取消成功" << endl;
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
		cout << "清空成功" << endl;
	}
	else {
		cout << "输入错误" << endl;
	}
}