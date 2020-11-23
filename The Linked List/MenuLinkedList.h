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


	void Menu();    //主菜单

private:

	//-----Int Begin----
	void MenuInt(); //Int菜单

	void IntInsert();    //Int插入菜单
	void IntErase();     //Int删除菜单
	void IntSearch();    //Int查询菜单
	void IntReadFile();  //Int读文件
	void IntWriteFile(); //Int写文件
	//-----Int Over----

	//-----Stu Begin---
	void MenuStu();

	void StuInsert();    //Int插入菜单
	void StuErase();     //Int删除菜单
	void StuSearch();    //Int查询菜单
	void StuReadFile();  //Int读文件
	void StuWriteFile(); //Int写文件
	//-----Stu Over----

};

