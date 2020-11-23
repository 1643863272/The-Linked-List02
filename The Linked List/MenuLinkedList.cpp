#include "MenuLinkedList.h"

void MenuLinkedList::Menu()
{
	while (true) {
		cout << "ѡ�����������" << endl;
		cout << "1. int����" << endl;
		cout << "2. Student����" << endl;
		cout << "0. �˳�" << endl;
		cout << "�������ѡ��:";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			exit(0);
			break;
		case '1':
			system("cls");
			MenuInt();
			break;
		case '2':
			system("cls");
			MenuStu();
			break;
		default:
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuLinkedList::MenuInt()
{
	while (true) {
		cout << "----int����----" << endl;
		cout << "|1. ��ʾ����--|" << endl;
		cout << "|2. ��������--|" << endl;
		cout << "|3. ɾ������--|" << endl;
		cout << "|4. ��������--|" << endl;
		cout << "|5. ��ȡ����--|" << endl;
		cout << "|6. ��������--|" << endl;
		cout << "|0. ����    --|" << endl;
		cout << "�������ѡ��: ";
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1':
			system("cls");
			linkedListInt.Display();
			break;
		case '2':
			system("cls");
			IntInsert();
			break;
		case '3':
			system("cls");
			IntErase();
			break;
		case '4':
			system("cls");
			IntSearch();
			break;
		case '5':
			system("cls");
			IntReadFile();
			break;
		case '6':
			system("cls");
			IntWriteFile();
			break;
		default:
			system("cls");
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuLinkedList::IntInsert()
{
	while (true) {
		cout << "int ��������" << endl;
		cout << "1. ��ָ��Ԫ��ǰ��������" << endl;
		cout << "2. ��ָ��Ԫ�غ��������" << endl;
		cout << "3. ��ָ��λ�ò�������" << endl;
		cout << "4. ���Ԫ�أ�Ĭ��Ϊ���λ��)" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int beforeEle, insertEle;
			cout << "��������Ҫ����ǰԪ�أ�"; cin >> beforeEle;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> insertEle;
			bool flag01 = linkedListInt.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '2': {
			int afterEle, eleInsert;
			cout << "��������Ҫ�����Ԫ�أ�"; cin >> afterEle;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> eleInsert;
			bool flag02 = linkedListInt.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '3': {
			int pos, ele;
			cout << "��������Ҫ�����λ��(��1��ʼ)��"; cin >> pos;
			cout << "��������Ҫ����Ԫ�أ�"; cin >> ele;
			pos--;
			bool flag03 = linkedListInt.Insert(pos, ele);
			if (flag03 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '4': {
			int elee;
			cout << "������Ҫ��ӵ�Ԫ��:"; cin >> elee;
			linkedListInt.PushBack(elee);
			cout << "����ɹ�!" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuLinkedList::IntErase()
{
	while (true) {
		cout << "int ɾ������" << endl;
		cout << "1. ɾ��ָ��Ԫ��(����)" << endl;
		cout << "2. ɾ��ָ��λ��Ԫ��" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int eleErase;
			cout << "��������Ҫɾ����Ԫ��:"; cin >> eleErase;
			linkedListInt.Erase(eleErase);
			cout << "ɾ���ɹ������޸�Ԫ����ɾ��)" << endl;
			break;
		}
		case '2': {
			int poss;
			cout << "��������ɾ����Ԫ�����(��1��ʼ):"; cin >> poss;
			poss--;
			bool flag01 = linkedListInt.EraseByPos(poss);
			if (flag01 == true)
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2')
			return;
	}
}

void MenuLinkedList::IntSearch()
{
	while (true) {
		cout << "int ��ѯ����" << endl;
		cout << "1. ����ĳԪ��λ��" << endl;
		cout << "2. �޸�ָ��λ��Ԫ��" << endl;
		cout << "3. ������Ԫ��A��ΪB" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			int ele;
			cout << "���������ѯ��Ԫ��:"; cin >> ele;
			int pos = linkedListInt.Locate(ele);
			if (pos == 0)
				cout << "δ�ҵ���Ԫ��" << endl;
			else
				cout << "��Ԫ��λ��Ϊ:" << pos << endl;
			break;
		}
		case '2': {
			int posToMo;
			int eleAfterMo;
			cout << "������Ҫ�޸ĵ�Ԫ��λ��:"; cin >> posToMo;
			cout << "������Ҫ�޸�Ϊ��Ԫ��:"; cin >> eleAfterMo;
			bool flag01 = linkedListInt.Modify(posToMo, eleAfterMo);
			if (flag01 == true)
				cout << "�޸ĳɹ�" << endl;
			else
				cout << "�޸�ʧ��" << endl;
			break;
		}
		case '3': {
			int eleA, eleB;
			cout << "�����޸�ǰ��Ԫ��A:"; cin >> eleA;
			cout << "�����޸ĺ��Ԫ��B:"; cin >> eleB;
			linkedListInt.ModifyAToB(eleA, eleB);
			cout << "�޸ĳɹ�!(��AԪ�����޸�)" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuLinkedList::IntReadFile()
{
	string fileName;
	cout << "������Ҫ��ȡ���ļ���:"; cin >> fileName;
	linkedListInt.ReadFile(fileName);
	cout << "��ȡ�ɹ�����ȷ���ļ���Ϊint����)" << endl;
}

void MenuLinkedList::IntWriteFile()
{
	string fileName;
	cout << "������Ҫд����ļ���:"; cin >> fileName;
	linkedListInt.WriteFile(fileName);
	cout << "д��ɹ�" << endl;
}

void MenuLinkedList::MenuStu()
{
	while (true) {
		cout << "----Stu����----" << endl;
		cout << "|1. ��ʾ����--|" << endl;
		cout << "|2. ��������--|" << endl;
		cout << "|3. ɾ������--|" << endl;
		cout << "|4. ��������--|" << endl;
		cout << "|5. ��ȡ����--|" << endl;
		cout << "|6. ��������--|" << endl;
		cout << "|0. ����    --|" << endl;
		cout << "�������ѡ��: ";
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1':
			system("cls");
			cout << "һ����" << linkedListStu.Size() << "��ѧ��" << endl;
			cout << "����  ѧ��  ����" << endl;
			linkedListStu.Display();
			break;
		case '2':
			system("cls");
			StuInsert();
			break;
		case '3':
			system("cls");
			StuErase();
			break;
		case '4':
			system("cls");
			StuSearch();
			break;
		case '5':
			system("cls");
			StuReadFile();
			break;
		case '6':
			system("cls");
			StuWriteFile();
			break;
		default:
			system("cls");
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void MenuLinkedList::StuInsert()
{
	while (true) {
		cout << "Stu ��������" << endl;
		cout << "1. ��ָ��Ԫ��ǰ��������" << endl;
		cout << "2. ��ָ��Ԫ�غ��������" << endl;
		cout << "3. ��ָ��λ�ò�������" << endl;
		cout << "4. ���Ԫ�أ�Ĭ��Ϊ���λ�ã�" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student beforeEle("11"), insertEle("11");
			Student s();
			cout << "��������Ҫ�����ǰԪ�أ�" << endl; beforeEle.Input();
			cout << "��������Ҫ����Ԫ�أ�" << endl; insertEle.Input();;
			bool flag01 = linkedListStu.InsertBefore(beforeEle, insertEle);
			if (flag01 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '2': {
			Student afterEle(""), eleInsert("");
			cout << "��������Ҫ�����Ԫ�أ�" << endl; afterEle.Input();
			cout << "��������Ҫ����Ԫ�أ�" << endl; eleInsert.Input();
			bool flag02 = linkedListStu.InsertAfter(afterEle, eleInsert);
			if (flag02 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '3': {
			int pos;
			Student	ele("");
			cout << "��������Ҫ�����λ��(��1��ʼ)��"; cin >> pos;
			cout << "��������Ҫ����Ԫ�أ�" << endl; ele.Input();
			pos--;
			bool flag03 = linkedListStu.Insert(pos, ele);
			if (flag03 == true)
				cout << "����ɹ�!" << endl;
			else
				cout << "����ʧ��!" << endl;
			break;
		}
		case '4': {
			Student elee("");
			cout << "������Ҫ��ӵ�Ԫ��:" << endl; elee.Input();
			linkedListStu.PushBack(elee);
			cout << "��ӳɹ�" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuLinkedList::StuErase()
{
	while (true) {
		cout << "Stu ɾ������" << endl;
		cout << "1. ɾ��ָ��Ԫ��(����)" << endl;
		cout << "2. ɾ��ָ��λ��Ԫ��" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student eleErase("");
			cout << "��������Ҫɾ����Ԫ��:" << endl; eleErase.Input();
			linkedListStu.Erase(eleErase);
			cout << "ɾ���ɹ������޸�Ԫ����ɾ��)" << endl;
			break;
		}
		case '2': {
			int poss;
			cout << "��������ɾ����Ԫ�����(��1��ʼ):"; cin >> poss;
			poss--;
			bool flag01 = linkedListStu.EraseByPos(poss);
			if (flag01 == true)
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2')
			return;
	}
}

void MenuLinkedList::StuSearch()
{
	while (true) {
		cout << "Stu ��ѯ����" << endl;
		cout << "1. ����ĳԪ��λ��" << endl;
		cout << "2. �޸�ָ��λ��Ԫ��" << endl;
		cout << "3. ������Ԫ��A��ΪB" << endl;
		cout << "0. ����" << endl;
		cout << "�������ѡ��";

		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			return;
			break;
		case '1': {
			Student ele("");
			cout << "���������ѯ��Ԫ��:" << endl; ele.Input();
			int pos = linkedListStu.Locate(ele);
			if (pos == 0)
				cout << "δ�ҵ���Ԫ��" << endl;
			else
				cout << "��Ԫ��λ��Ϊ:" << pos << endl;
			break;
		}
		case '2': {
			int posToMo;
			Student eleAfterMo("");
			cout << "������Ҫ�޸ĵ�Ԫ��λ��:"; cin >> posToMo;
			cout << "������Ҫ�޸�Ϊ��Ԫ��:" << endl; eleAfterMo.Input();
			bool flag01 = linkedListStu.Modify(posToMo, eleAfterMo);
			if (flag01 == true)
				cout << "�޸ĳɹ�" << endl;
			else
				cout << "�޸�ʧ��" << endl;
			break;
		}
		case '3': {
			Student eleA(""), eleB("");
			cout << "�����޸�ǰ��Ԫ��A:" << endl; eleA.Input();
			cout << "�����޸ĺ��Ԫ��B:" << endl; eleB.Input();
			linkedListStu.ModifyAToB(eleA, eleB);
			cout << "�޸ĳɹ�!(��AԪ�����޸�)" << endl;
			break;
		}
		default:
			cout << "����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
		if (choice == '1' || choice == '2' || choice == '3')
			return;
	}
}

void MenuLinkedList::StuReadFile()
{
	string fileName;
	cout << "������Ҫ��ȡ���ļ���:"; cin >> fileName;
	linkedListStu.ReadFile(fileName);
	cout << "��ȡ�ɹ�����ȷ���ļ���ΪStudent����)" << endl;
}

void MenuLinkedList::StuWriteFile()
{
	string fileName;
	cout << "������Ҫд����ļ���:"; cin >> fileName;
	linkedListStu.WriteFile(fileName);
	cout << "д��ɹ�" << endl;
}