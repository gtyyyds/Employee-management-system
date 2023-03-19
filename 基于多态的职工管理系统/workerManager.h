#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();

	void Show_Menu();//展示菜单

	void ExitSystem();//退出系统

	int m_EmpNum;//当前职工人数

	Worker ** m_EmpArray;//职工数组

	void Add_Emp();//添加职工

	void save();//保存文件

	bool m_FileIsEmpty;//文件是否为空

	int get_EmpNum();//获取文件里的人数

	void init_Emp();//初始化员工

	void Show_Emp();//显示员工

	void Del_Emp();//删除员工

	int IsExist(int id);//判断员工是否存在

	void Mod_Emp();//修改职工

	void Find_Emp();//查找职工

	void Sort_Emp();//排序职工

	void Clean_File();//清空文件

	~WorkerManager();
};