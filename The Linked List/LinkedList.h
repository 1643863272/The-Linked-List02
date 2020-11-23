#pragma once
#include <iostream>
#include <string>
using namespace std;
/// <summary>
/// �����ڵ�
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class LinkNode {
public:
	T data;     //����ĵ�������
	LinkNode<T>* link;  //��һ��

	LinkNode(){         //���캯��
		this->link = NULL;
	}
	LinkNode(LinkNode<T>& L){      //���ƹ��캯��
		this->data = L.data;
		this->link = L.link;
	}
	LinkNode(T data) {  //�вι���
		this->link = NULL;
		this->data = data;
	}
};




/// <summary>
/// ����
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class LinkedList
{
private:
	int length;        //Ŀǰ����
	LinkNode<T>* first;   //ͷ�ڵ�(ָ���һ���ڵ�)
	LinkNode<T>* last;    //β���(ָ�����һ���ڵ�)

	LinkNode<T>* FindByPos(int pos);  //����pos�±�Ľڵ�
	LinkNode<T>* FindBeforePos(int pos);  //����pos�±�ǰ�Ľڵ�,���ڲ�������
	LinkNode<T>* FindEleBefore(T ele);  //ͨ��Ԫ����֮ǰ�Ľڵ�
	LinkNode<T>* FindEle(T ele);        //ͨ��Ԫ���Ҹýڵ�

	void MoveLast(); //�ƶ�β���
public:
	LinkedList();    //���캯��
	~LinkedList();   //��������


	bool Insert(int pos, T ele); //ָ��λ�ò�������
	void PushBack(T ele);        //��������//////////δ���
	bool InsertBefore(T eleBefore, T ele);  //��ָ��Ԫ��ǰ����Ԫ��
	bool InsertAfter(T eleAfter, T ele);    //��ָ��Ԫ�غ����Ԫ��

	int Search(T ele); //��Ԫ�ص��±�(������Ϊ-1)
	int Locate(T ele); //��Ԫ�ص�λ�ã��±�+1��������Ϊ0��
	void Display();    //��ʾ��������

	void Erase(T ele);        //ɾ��ָ��Ԫ��(����)
	bool EraseByPos(int pos); //ɾ��ָ��λ��Ԫ��
	void Clear();  //���Ԫ��

	int Size();  //Ԫ�ظ���

	bool Modify(int pos, T ele);      //�޸�ָ��λ�õ�Ԫ��
	void ModifyAToB(T eleA, T eleB);  //������Ԫ��A�޸�ΪԪ��B

	void ReadFile(string fileName);  //���ļ�����ͬ�������ݣ�
	void WriteFile(string fileName); //д�ļ�����ͬ�������ݣ�
};
