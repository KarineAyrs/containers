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

	// Функция возвращает указатель на итератор, указывающий на первый найденный
	// в контейнере элемент. Если элемент не найден, возвращается пустой указатель.

	Container::Iterator* find(void *elem, size_t size);
	

	// Создание итератора, соответствующего данному типу контейнера.
	Container::Iterator* newIterator();
	

	// Функция возвращает указатель на итератор, указывающий на первый элемент
	// контейнера. Если контейнер пустой, возвращается нулевой указатель.
	Container::Iterator* begin();
	

	// Добавление элемента в позицию, на которую указывает итератор iter.
	// В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
	int insert(Iterator *iter, void *elem, size_t elemSize);  //значение затирается? да     //++
	
	// Функция возвращает указатель на итератор, указывающий позицию за последним
	// элементом контейнера. Если контейнер пустой, возвращается нулевой указатель.
	Container::Iterator* end();
	

	// Удаление элемента из позиции, на которую указывает итератор iter.
	// После удаления итератор указывает на следующий за удаленным элемент.
	void remove(Container::Iterator *iter);
	

	friend  bool operator== (const Node & el, const Node & el2) {

		if (el.size == el2.size) {
			if (el.value == el2.value) { return true; }
			return false;
		}
		return false;
	}

};