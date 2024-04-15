#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class worker;
class workermanager
{
public:
	workermanager();
	void show_menu();
	void add_worker();
	void look_workers();
	~workermanager();
	void del_workers();
	void save();
	void mod_worker();
	void find_worker();
	void sort_worker();
	void clear_worker();
public:
	int empnum;
	worker** emparray;
};
class worker
{
public:
	virtual void showinfo() = 0;
	virtual string getdeptname() = 0;
public:
	string name;
	int mid;
	int mdeptid;
};
class common_worker :public worker
{
public:
	common_worker(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();
};
class manager_worker :public worker
{
public:
	manager_worker(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();
};
class boss_worker :public worker
{
public:
	boss_worker(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();
};

