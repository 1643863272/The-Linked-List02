#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

/// <summary>
/// ����ָ���±�Ľڵ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">�±�</param>
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
/// �����±�ǰ�Ľڵ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">�±�</param>
/// <returns></returns>
template<class T>
LinkNode<T>* LinkedList<T>::FindBeforePos(int pos)
{
	if (pos < 0 || pos > length)
		return NULL;

	LinkNode<T>* n = this->first;  //���ҵ��±�ǰ�Ľڵ�
	for (int i = 0; i < pos; i++)
		n = n->link;
	return n;
}

/// <summary>
/// ����Ԫ��ǰ�ڵ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">����</param>
/// <returns>Ԫ��ǰ�ڵ�</returns>
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
/// ͨ��Ԫ�ز��ҽڵ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">����Ԫ��</param>
/// <returns>ָ��Ԫ�ؽڵ�</returns>
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
/// �ƶ�β���
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
/// ��ָ���±����Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">ָ���±�</param>
/// <param name="ele">����Ԫ��</param>
/// <returns>�Ƿ����ɹ�</returns>
template<class T>
bool LinkedList<T>::Insert(int pos, T ele)
{
	LinkNode<T>* before = FindBeforePos(pos);  //�����±�ǰ�Ľڵ�
	if (before == NULL)
		return false;

	LinkNode<T>* newData = new LinkNode<T>(ele);
	if (newData == NULL) {
		cerr << "�ڴ����ʧ��" << endl;
		exit(1);
	}

	newData->link = before->link;
	before->link = newData;
	length++;
	MoveLast();
	return true;
}

/// <summary>
/// ��������Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">Ҫ��ӵ�Ԫ��</param>
template<class T>
void LinkedList<T>::PushBack(T ele)
{
	LinkNode<T>* n = new LinkNode<T>(ele);

	last->link = n;
	last = n;
	length++;
}

/// <summary>
/// ��ָ��Ԫ��ǰ����Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleBefore">ָ��Ԫ��</param>
/// <param name="ele">����Ԫ��</param>
/// <returns>�Ƿ����ɹ�</returns>
template<class T>
bool LinkedList<T>::InsertBefore(T eleBefore, T ele)
{
	LinkNode<T>* before = FindEleBefore(eleBefore);  //eleBeforeǰ�ڵ�
	if (before == NULL)
		return false;
	LinkNode<T>* newData = new LinkNode<T>(ele);
	if (newData == NULL) {
		cerr << "�ڴ����ʧ�ܣ�" << endl;
		exit(1);
	}

	newData->link = before->link;
	before->link = newData;
	length++;
	return true;
}

/// <summary>
/// ��ָ��Ԫ�غ����Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleAfter">ָ��Ԫ��</param>
/// <param name="ele">����Ԫ��</param>
/// <returns>�Ƿ����ɹ�</returns>
template<class T>
bool LinkedList<T>::InsertAfter(T eleAfter, T ele)
{
	LinkNode<T>* current = FindEle(eleAfter); //eleAfter�ڵ�
	if (current == NULL)
		return false;
	LinkNode<T>* newData = new LinkNode<T>(ele);
	if (newData == NULL) {
		cerr << "�ڴ����ʧ�ܣ�" << endl;
		exit(1);
	}

	newData->link = current->link;
	current->link = newData;
	length++;
	MoveLast();
	return true;
}

/// <summary>
/// ����Ԫ���±�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">���ҵ�Ԫ��</param>
/// <returns>Ԫ���±�(-1Ϊδ�ҵ�)</returns>
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
/// ��λԪ��λ�ã��±�+1��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">��λ��Ԫ��</param>
/// <returns>Ԫ��λ�ã��±�+1��</returns>
template<class T>
int LinkedList<T>::Locate(T ele)
{
	return Search(ele) + 1;
}

template<class T>
void LinkedList<T>::Display()
{
	if (length == 0) {
		cout << "Ԫ��Ϊ0" << endl;
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
/// ɾ��ָ��Ԫ�أ����У�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ele">Ҫɾ����Ԫ��</param>
template<class T>
void LinkedList<T>::Erase(T ele)
{
	LinkNode<T>* nn = this->first;
	while (nn->link != NULL) {
		if (nn->link->data == ele) {
			LinkNode<T>* toDel = nn->link;  //Ҫɾ���Ľڵ�

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
/// ɾ��ָ��λ��Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">Ԫ��λ��</param>
/// <returns>�Ƿ�ɾ���ɹ�</returns>
template<class T>
bool LinkedList<T>::EraseByPos(int pos)
{
	LinkNode<T>* before = FindBeforePos(pos);
	if (before == NULL)
		return false;

	LinkNode<T>* toDel = before->link;  //Ҫɾ����Ԫ��

	if (last == toDel)
		last = first;

	before->link = toDel->link;
	delete toDel;
	length--;
	MoveLast();
	return true;
}

/// <summary>
/// ���Ԫ��
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
/// �޸�ָ��λ��Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pos">ָ��λ��</param>
/// <param name="ele">�޸ĺ�Ԫ��</param>
/// <returns>�Ƿ��޸ĳɹ�</returns>
template<class T>
bool LinkedList<T>::Modify(int pos, T ele)
{
	LinkNode<T>* current = FindByPos(pos);  //�ýڵ�
	if (current == NULL)
		return false;

	current->data = ele;
	return true;
}

/// <summary>
/// ������Ԫ��A�޸�ΪԪ��B(û��AԪ�����޸�)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eleA">Ԫ��A</param>
/// <param name="eleB">Ԫ��B</param>
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
/// ���ļ��������ݸ��Ǹ�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="fileName">�ļ���</param>
template<class T>
void LinkedList<T>::ReadFile(string fileName)
{
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.is_open()) {
		cerr << "�ļ���ʧ��!" << endl;
		exit(1);
	}

	this->Clear();

	int count;  //���ݸ���
	f >> count;  //�ļ���һ��ΪԪ�ظ���
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
		cerr << "�ļ���ʧ��!" << endl;
		exit(1);
	}

	f << length << endl;  //д��Ԫ�ظ���
	LinkNode<T>* current = this->first->link;  //���ڱ���
	while (current != NULL) {
		f << current->data << endl;
		current = current->link;
	}
	f.close();
}
