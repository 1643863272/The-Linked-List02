#pragma once
#include <iostream>
#include <string>
using namespace std;
/// <summary>
/// 单个节点
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class LinkNode {
public:
	T data;     //储存的单个数据
	LinkNode<T>* link;  //下一节

	LinkNode(){         //构造函数
		this->link = NULL;
	}
	LinkNode(LinkNode<T>& L){      //复制构造函数
		this->data = L.data;
		this->link = L.link;
	}
	LinkNode(T data) {  //有参构造
		this->link = NULL;
		this->data = data;
	}
};




/// <summary>
/// 链表
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class LinkedList
{
private:
	int length;        //目前容量
	LinkNode<T>* first;   //头节点(指向第一个节点)
	LinkNode<T>* last;    //尾结点(指向最后一个节点)

	LinkNode<T>* FindByPos(int pos);  //返回pos下标的节点
	LinkNode<T>* FindBeforePos(int pos);  //返回pos下标前的节点,用于插入数据
	LinkNode<T>* FindEleBefore(T ele);  //通过元素找之前的节点
	LinkNode<T>* FindEle(T ele);        //通过元素找该节点

	void MoveLast(); //移动尾结点
public:
	LinkedList();    //构造函数
	~LinkedList();   //析构函数


	bool Insert(int pos, T ele); //指定位置插入数据
	void PushBack(T ele);        //在最后插入//////////未完成
	bool InsertBefore(T eleBefore, T ele);  //在指定元素前插入元素
	bool InsertAfter(T eleAfter, T ele);    //在指定元素后插入元素

	int Search(T ele); //找元素的下标(不存在为-1)
	int Locate(T ele); //找元素的位置（下标+1，不存在为0）
	void Display();    //显示所有数据

	void Erase(T ele);        //删除指定元素(所有)
	bool EraseByPos(int pos); //删除指定位置元素
	void Clear();  //清空元素

	int Size();  //元素个数

	bool Modify(int pos, T ele);      //修改指定位置的元素
	void ModifyAToB(T eleA, T eleB);  //讲所有元素A修改为元素B

	void ReadFile(string fileName);  //读文件（相同类型数据）
	void WriteFile(string fileName); //写文件（相同类型数据）
};
