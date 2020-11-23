#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

/// <summary>
/// 查找指定下标的节点
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">下标</param>
/// <returns></returns>
template<class T>
LinkNode<T>* LinkedList<T>::FindByPos(int pos)
{
	if (pos < 0 || pos >= length)
		return NULL;

	LinkNode<T>* n = this->first;
	for (int i = 0; i < pos + 1; i++)
		n = n->link;
	return n;
}

/// <summary>
/// 查找下标前的节点
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">下标</param>
/// <returns></returns>
template<class T>
LinkNode<T>* LinkedList<T>::FindBeforePos(int pos)
{
	if (pos < 0 || pos > length)
		return NULL;

	LinkNode<T>* n = this->first;  //查找的下标前的节点
	for (int i = 0; i < pos; i++)
		n = n->link;
	return n;
}

/// <summary>
/// 查找元素前节点
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">数据</param>
/// <returns>元素前节点</returns>
template<class T>
LinkNode<T>* LinkedList<T>::FindEleBefore(T ele)
{
	LinkNode<T>* before = this->first;
	while (before->link != NULL) {
		if (before->link->data == ele)
			return before;
		before = before->link;
	}
	return NULL;
}

/// <summary>
/// 通过元素查找节点
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">查找元素</param>
/// <returns>指定元素节点</returns>
template<class T>
LinkNode<T>* LinkedList<T>::FindEle(T ele)
{
	LinkNode<T>* current = this->first->link;
	while (current != NULL) {
		if (current->data == ele)
			return current;
		current = current->link;
	}
	return NULL;
}

/// <summary>
/// 移动尾结点
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void LinkedList<T>::MoveLast()
{
	if (length == 0) {
		last = first;
		return;
	}

	while (last->link != NULL) {
		last = last->link;
	}
}

template<class T>
LinkedList<T>::LinkedList()
{
	this->first = new LinkNode<T>;
	this->last = first;

	length = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	this->Clear();
}

/// <summary>
/// 在指定下标插入元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">指定下标</param>
/// <param name="ele">插入元素</param>
/// <returns>是否插入成功</returns>
template<class T>
bool LinkedList<T>::Insert(int pos, T ele)
{
	LinkNode<T>* before = FindBeforePos(pos);  //插入下标前的节点
	if (before == NULL)
		return false;

	LinkNode<T>* newData = new LinkNode<T>(ele);
	if (newData == NULL) {
		cerr << "内存分配失败" << endl;
		exit(1);
	}

	newData->link = before->link;
	before->link = newData;
	length++;
	MoveLast();
	return true;
}

/// <summary>
/// 在最后添加元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">要添加的元素</param>
template<class T>
void LinkedList<T>::PushBack(T ele)
{
	LinkNode<T>* n = new LinkNode<T>(ele);

	last->link = n;
	last = n;
	length++;
}

/// <summary>
/// 在指定元素前插入元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleBefore">指定元素</param>
/// <param name="ele">插入元素</param>
/// <returns>是否插入成功</returns>
template<class T>
bool LinkedList<T>::InsertBefore(T eleBefore, T ele)
{
	LinkNode<T>* before = FindEleBefore(eleBefore);  //eleBefore前节点
	if (before == NULL)
		return false;
	LinkNode<T>* newData = new LinkNode<T>(ele);
	if (newData == NULL) {
		cerr << "内存分配失败！" << endl;
		exit(1);
	}

	newData->link = before->link;
	before->link = newData;
	length++;
	return true;
}

/// <summary>
/// 在指定元素后插入元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleAfter">指定元素</param>
/// <param name="ele">插入元素</param>
/// <returns>是否插入成功</returns>
template<class T>
bool LinkedList<T>::InsertAfter(T eleAfter, T ele)
{
	LinkNode<T>* current = FindEle(eleAfter); //eleAfter节点
	if (current == NULL)
		return false;
	LinkNode<T>* newData = new LinkNode<T>(ele);
	if (newData == NULL) {
		cerr << "内存分配失败！" << endl;
		exit(1);
	}

	newData->link = current->link;
	current->link = newData;
	length++;
	MoveLast();
	return true;
}

/// <summary>
/// 查找元素下标
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">查找的元素</param>
/// <returns>元素下标(-1为未找到)</returns>
template<class T>
int LinkedList<T>::Search(T ele)
{
	if (length == 0)
		return -1;

	LinkNode<T>* n = this->first->link;
	int pos = 0;
	while (n != NULL) {
		if (n->data == ele)
			return pos;
		n = n->link;
		pos++;
	}
	return -1;
}

/// <summary>
/// 定位元素位置（下标+1）
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">定位的元素</param>
/// <returns>元素位置（下标+1）</returns>
template<class T>
int LinkedList<T>::Locate(T ele)
{
	return Search(ele) + 1;
}

template<class T>
void LinkedList<T>::Display()
{
	if (length == 0) {
		cout << "元素为0" << endl;
		return;
	}

	LinkNode<T>* n = this->first->link;
	while (n != NULL) {
		cout << n->data << " ";
		n = n->link;
	}
	cout << endl;
}

/// <summary>
/// 删除指定元素（所有）
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">要删除的元素</param>
template<class T>
void LinkedList<T>::Erase(T ele)
{
	LinkNode<T>* nn = this->first;
	while (nn->link != NULL) {
		if (nn->link->data == ele) {
			LinkNode<T>* toDel = nn->link;  //要删除的节点

			if (last == toDel)
				last = first;

			nn->link = toDel->link;
			delete toDel;
			length--;
			continue;
		}
		nn = nn->link;
	}
	MoveLast();
}

/// <summary>
/// 删除指定位置元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">元素位置</param>
/// <returns>是否删除成功</returns>
template<class T>
bool LinkedList<T>::EraseByPos(int pos)
{
	LinkNode<T>* before = FindBeforePos(pos);
	if (before == NULL)
		return false;

	LinkNode<T>* toDel = before->link;  //要删除的元素

	if (last == toDel)
		last = first;

	before->link = toDel->link;
	delete toDel;
	length--;
	MoveLast();
	return true;
}

/// <summary>
/// 清空元素
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void LinkedList<T>::Clear()
{
	this->last = this->first;
	LinkNode<T>* p;
	while (this->first->link != NULL) {
		p = this->first->link;
		this->first->link = p->link;

		delete p;
	}
	length = 0;
}

template<class T>
int LinkedList<T>::Size()
{
	return length;
}

/// <summary>
/// 修改指定位置元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">指定位置</param>
/// <param name="ele">修改后元素</param>
/// <returns>是否修改成功</returns>
template<class T>
bool LinkedList<T>::Modify(int pos, T ele)
{
	LinkNode<T>* current = FindByPos(pos);  //该节点
	if (current == NULL)
		return false;

	current->data = ele;
	return true;
}

/// <summary>
/// 将所有元素A修改为元素B(没有A元素则不修改)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleA">元素A</param>
/// <param name="eleB">元素B</param>
template<class T>
void LinkedList<T>::ModifyAToB(T eleA, T eleB)
{
	LinkNode<T>* current = this->first->link;
	while (current != NULL) {
		if (current->data == eleA)
			current->data = eleB;
		current = current->link;
	}
}

/// <summary>
/// 读文件，将数据覆盖该链表
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="fileName">文件名</param>
template<class T>
void LinkedList<T>::ReadFile(string fileName)
{
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.is_open()) {
		cerr << "文件打开失败!" << endl;
		exit(1);
	}

	this->Clear();

	int count;  //数据个数
	f >> count;  //文件第一行为元素个数
	for (int i = 0; i < count; i++) {
		T newData;
		f >> newData;
		this->Insert(i, newData);
	}
	f.close();
}

template<class T>
void LinkedList<T>::WriteFile(string fileName)
{
	ofstream f;
	f.open(fileName, ios::out);
	if (!f.is_open()) {
		cerr << "文件打开失败!" << endl;
		exit(1);
	}

	f << length << endl;  //写入元素个数
	LinkNode<T>* current = this->first->link;  //用于遍历
	while (current != NULL) {
		f << current->data << endl;
		current = current->link;
	}
	f.close();
}
