#include"workerManager.h"
WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ�û������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ�������
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	/*
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id<<" "
			<< "ְ��������" << this->m_EmpArray[i]->m_Name<<" "
			<< "ְ����λ��" << this->m_EmpArray[i]->m_DeptId<<endl;
	}
	*/

}
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout<< "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ��ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ�ְ����" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = " ";
			int dSelect = 0;
			cout << "���ң�" << id << " ��ְ������������ְ���ţ�" << endl;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������λ��" << endl;
			cout << "1����ְͨ��" << endl
			     << "2������" << endl
				 << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << endl;
					cout << "��ְ������Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "�������������������룡" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1������ְ��������" << endl;
		cout << "2������ְ���Ž���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
				else if (select == 2)
				{
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = temp;
					}
				}
				else
				{
					cout << "������������ѡ��" << endl;
				}
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->Show_Emp();

	}
}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;

	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
