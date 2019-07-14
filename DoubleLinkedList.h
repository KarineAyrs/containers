#pragma once
#include <iostream>
#include "GroupContainer.h"
#include "List2Abstract.h"
using namespace std;

class DoubleLinkedList: public	AbstractList2{
private:
	struct Node {
		void *value;
		size_t size;
		Node*next, *prev;
	};
	Node*Head, *Tail;
	Node *Last;
	int nsize = 0;
	//=,==,!=
public:
	
	
	DoubleLinkedList(MemoryManager &mem) :Head(NULL), Last(NULL), Tail(NULL), AbstractList2(mem){
		
	}

	int push_back(void *elem, size_t elemSize);
	int push_front(void *elem, size_t elemSize);  //++

	//================
	void pop_back();
	void pop_front();   //++
	void* front(size_t &size);  //++
	void* back(size_t &size);
	//========
	void printList();

	int size();
	void clear();
	bool empty();


	class MyIterator : public Iterator{
	public:
		Node*thisElem;
		DoubleLinkedList* dbList;

		MyIterator(DoubleLinkedList* dbList, Node* thisel) : dbList(dbList), thisElem(thisel) {}

		void* getElement(size_t &size);
		
		virtual bool hasNext();
		
		void goToNext();
		
		bool equals(Iterator* right);
			
	};

	size_t max_bytes() { return 1; }

	// ������� ���������� ��������� �� ��������, ����������� �� ������ ���������
	// � ���������� �������. ���� ������� �� ������, ������������ ������ ���������.

	Container::Iterator* find(void *elem, size_t size);
	

	// �������� ���������, ���������������� ������� ���� ����������.
	Container::Iterator* newIterator();
	

	// ������� ���������� ��������� �� ��������, ����������� �� ������ �������
	// ����������. ���� ��������� ������, ������������ ������� ���������.
	Container::Iterator* begin();
	

	// ���������� �������� � �������, �� ������� ��������� �������� iter.
	// � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
	int insert(Iterator *iter, void *elem, size_t elemSize);  //�������� ����������? ��     //++
	
	// ������� ���������� ��������� �� ��������, ����������� ������� �� ���������
	// ��������� ����������. ���� ��������� ������, ������������ ������� ���������.
	Container::Iterator* end();
	

	// �������� �������� �� �������, �� ������� ��������� �������� iter.
	// ����� �������� �������� ��������� �� ��������� �� ��������� �������.
	void remove(Container::Iterator *iter);
	

	friend  bool operator== (const Node & el, const Node & el2) {

		if (el.size == el2.size) {
			if (el.value == el2.value) { return true; }
			return false;
		}
		return false;
	}

};