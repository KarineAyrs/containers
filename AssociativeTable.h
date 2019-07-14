#pragma once
#include <iostream>
#include "DoubleLinkedList.h"
#include"TableAbstract.h"
#include "TableAbstract.h"

using namespace std;

class AssociativeTable :public AbstractTable{

private:
	struct Data {
		void *key;
		void *value;
		size_t keySize;
		size_t valSize;
	};
	DoubleLinkedList **table;
	size_t tableSize;
	size_t sizeCon;


public:

	AssociativeTable(MemoryManager &mem) :AbstractTable(mem) {

		tableSize = mem.size();
		table = (DoubleLinkedList**)malloc(tableSize*sizeof(DoubleLinkedList*));
		_memory = mem;
		for (int i = 0; i < tableSize; i++) {
			table[i] = NULL;
		}
		sizeCon = 0;

	}
	int insertByKey(void *key, size_t keySize, void *elem, size_t elemSize);

	void removeByKey(void *key, size_t keySize);
	void* at(void *key, size_t keySize, size_t &valueSize);
	size_t hash_function(void *key, size_t keySize);
	int size();
	void clear();
	bool empty();
	size_t max_bytes();
	Container::Iterator* begin();
	Container::Iterator* newIterator();
	Container::Iterator* findByKey(void *key, size_t keySize);
	Container::Iterator* find(void *elem, size_t size);

	Container::Iterator* end();
	void remove(Iterator *iter);
	
	
	 class Tableiterator : public Iterator {
	 public:
		 AssociativeTable *aTable; 
		 DoubleLinkedList *thisList;
		 DoubleLinkedList::Iterator *it;
		 int position;	 
		 Tableiterator(AssociativeTable *aTab, DoubleLinkedList *thisL, int pos, DoubleLinkedList::Iterator *it1) :aTable(aTab), thisList(thisL) {
			 if (it1 != NULL) it=it1;
			 else it = thisList->newIterator();
			 position = pos;
		 }
		 void* getElement(size_t &size);
		 bool hasNext();
		 void goToNext();
		 bool equals(Iterator *right); 
	 };



	 int fullLists(){
		 int count = 0;
		for (int i = 0; i < tableSize; i++) {
			if (table[i]!=NULL) {
				count++;
			}
		}
		return count;
	 }

};