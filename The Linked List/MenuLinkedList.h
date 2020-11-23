#pragma once
#include "Student.h"
#include "LinkedList.h"
#include "LinkedList.cpp"


class MenuLinkedList
{
private:
	LinkedList<int> linkedListInt;
	LinkedList<Student> linkedListStu;

public:


	void Menu();    //���˵�

private:

	//-----Int Begin----
	void MenuInt(); //Int�˵�

	void IntInsert();    //Int����˵�
	void IntErase();     //Intɾ���˵�
	void IntSearch();    //Int��ѯ�˵�
	void IntReadFile();  //Int���ļ�
	void IntWriteFile(); //Intд�ļ�
	//-----Int Over----

	//-----Stu Begin---
	void MenuStu();

	void StuInsert();    //Int����˵�
	void StuErase();     //Intɾ���˵�
	void StuSearch();    //Int��ѯ�˵�
	void StuReadFile();  //Int���ļ�
	void StuWriteFile(); //Intд�ļ�
	//-----Stu Over----

};

