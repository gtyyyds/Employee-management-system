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

	void Show_Menu();//չʾ�˵�

	void ExitSystem();//�˳�ϵͳ

	int m_EmpNum;//��ǰְ������

	Worker ** m_EmpArray;//ְ������

	void Add_Emp();//���ְ��

	void save();//�����ļ�

	bool m_FileIsEmpty;//�ļ��Ƿ�Ϊ��

	int get_EmpNum();//��ȡ�ļ��������

	void init_Emp();//��ʼ��Ա��

	void Show_Emp();//��ʾԱ��

	void Del_Emp();//ɾ��Ա��

	int IsExist(int id);//�ж�Ա���Ƿ����

	void Mod_Emp();//�޸�ְ��

	void Find_Emp();//����ְ��

	void Sort_Emp();//����ְ��

	void Clean_File();//����ļ�

	~WorkerManager();
};