#include"AssociativeTable.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
using namespace std;

int AssociativeTable::insertByKey(void * key, size_t keySize, void * elem, size_t elemSize){

	if (table != NULL) {
		int pos = hash_function(key, keySize);
		Data *new_el = new Data();
		new_el->value = elem;
		new_el->valSize = elemSize;
		memcpy(&(new_el->key), &key, keySize);
		new_el->keySize = keySize;

		if (table[pos] == NULL) {
			table[pos] = new DoubleLinkedList(_memory);
			table[pos]->push_front(new_el, sizeof(new_el));
			sizeCon++;
			return 0;
		} else {
			DoubleLinkedList::Iterator *it;
			size_t dataSize = 0;
			it = table[pos]->begin();
			for (int i = 0; i < table[pos]->size(); i++) {
				Data *temp;
				temp = (Data*)it->getElement(dataSize);
				if (temp->keySize == keySize) {
					if (memcmp(&(temp->key), &key, keySize) == 0) {
						table[pos]->insert(it, new_el, sizeof(new_el));
						return 0;
					}
				}
				it->goToNext();
			}
			table[pos]->push_front(new_el, sizeof(new_el));
			sizeCon++;
			return 0;
		}
	}
	return 1;
}

void AssociativeTable::removeByKey(void * key, size_t keySize){
	int pos = hash_function(key, keySize);

	if (table[pos] != NULL) {
		DoubleLinkedList::Iterator* it;
		it = table[pos]->begin();
		for (int i = 0; i < table[pos]->size(); i++) 
		{
			size_t dataSize;
			Data* temp;
			temp = (Data*)it->getElement(dataSize);

			if (keySize == temp->keySize) {
				if (memcmp(&(temp->key), &key, keySize) == 0) {
					table[pos]->remove(it);
					if (table[pos]->empty()) { table[pos] = NULL; }
					sizeCon--;
					break;
				}
			}
			it->goToNext();
		}
	}

}

void * AssociativeTable::at(void * key, size_t keySize, size_t & valueSize){

	int pos = hash_function(key, keySize);
	DoubleLinkedList::Iterator *it;
	it = table[pos]->begin();
	Data *temp;
	size_t dataSize;

	for (int i = 0; i < table[pos]->size(); i++) {
		temp = (Data*)it->getElement(dataSize);
		if (temp->keySize == keySize) {
			if (memcmp(&(temp->key), &key, keySize) == 0) {
				return temp->value;
			}
		}
		it->goToNext();
	}
	return nullptr;
}

size_t AssociativeTable::hash_function(void * key, size_t keySize){

	char*key1 = (char*)key;
	size_t hash=0;
	for (int i = 0; i < keySize; i++) {
		hash += (key1[i]);  
		hash += (hash << 1);
		hash += (hash << 2);
		hash += (hash << 3);
		hash += (hash << 5);
	}

	hash = hash % (tableSize + 3);
	return (hash%tableSize);
}

int AssociativeTable::size()
{
	return sizeCon;
}


void AssociativeTable::clear(){
	if (table != NULL) {
		for (int i = 0; i < tableSize; i++) {
			if (table[i]!=NULL) {
				table[i]->clear();
			}
		}
		sizeCon = 0;
		tableSize = 0;
		free(table);
		table = NULL;
	}
}

Container::Iterator * AssociativeTable::begin(){
	if (table != NULL) {
		for (int i = 0; i < tableSize; i++) {
			if (table[i] != NULL) {
				Tableiterator *iter = new Tableiterator(this, table[i], i,NULL);
				return iter;
			}
		}
	}

	return nullptr;
}

bool AssociativeTable::empty(){
	if (table == NULL)return true;
	return false;
}

Container::Iterator * AssociativeTable::newIterator(){
	if (table != NULL) {
		Tableiterator *it = new Tableiterator(this, table[0], 0,NULL);
		return it;
	}
	return nullptr;
}

Container::Iterator * AssociativeTable::findByKey(void * key, size_t keySize){
	
	int pos = hash_function(key, keySize);
	if (table[pos] != NULL) {
		DoubleLinkedList::Iterator *it;
		it = table[pos]->begin();
		Data*temp;
		size_t dataSize;
		for (int i = 0; i < table[pos]->size(); i++) {
			temp = (Data*)it->getElement(dataSize);
			
			if (temp->keySize == keySize) {
				if (memcmp(&(temp->key), &key, keySize) == 0) {
					Tableiterator *iter = new Tableiterator(this, table[pos], pos, it);
					return iter;
				}
			}
			it->goToNext();
		}
	}
	return nullptr;
}

Container::Iterator * AssociativeTable::end(){
	if (table != NULL) {
		for (int i = tableSize - 1; i > 0; i--) {
			if (table[i]!=NULL) {
				DoubleLinkedList::Iterator *it;
				it = table[i]->end();
				return it;
			}
		}
	}
	return nullptr;
}

void AssociativeTable::remove(Iterator * iter){
	Tableiterator *itr = (Tableiterator*)iter;
	DoubleLinkedList::Iterator* dItr;
	if (itr->it != NULL) {
		dItr = itr->it;
		if (table[itr->position] != NULL) {
			table[itr->position]->remove(dItr);
			if (table[itr->position]->empty()) table[itr->position] = NULL;
			iter->goToNext();
			sizeCon--;
		}
	}
}

Container::Iterator * AssociativeTable::find(void * elem, size_t size){
	if (table != NULL) {
		for (int i = 0; i < tableSize; i++) {
			if (table[i] != NULL) {
				DoubleLinkedList::Iterator *it;
				it = table[i]->begin();
				for (int j = 0; j < table[i]->size(); j++) {
					Data *temp;
					size_t dataSize;
					temp = (Data*)it->getElement(dataSize);
					if (size == temp->valSize) {
						if (memcmp(&(temp->value), &elem, size) == 0) {
							Tableiterator *iter;
							iter = new Tableiterator(this, table[i], i, it);
							return iter;
						}
					}
					it->goToNext();
				}
			}
		}
	}
	
	return NULL;
}

size_t AssociativeTable::max_bytes(){
	return tableSize;
}
void * AssociativeTable::Tableiterator::getElement(size_t & size) 
{	
	Data * temp = (Data*)it->getElement(size);
	size = temp->valSize;
	return temp->value;

}

bool AssociativeTable::Tableiterator::hasNext()
{
	if (it != NULL) {
	if (!it->hasNext()) {
		for (int i = position + 1; i < aTable->tableSize; i++) {
			if (aTable->table[i] != NULL) {
				return true;
			}
		}
		return false;
	}
	return true;
}
	return false;
}

void AssociativeTable::Tableiterator::goToNext(){ 
	if (it->hasNext()) { it->goToNext(); }

	else {
		for (int i = position + 1; i < aTable->tableSize; i++) {
			if (aTable->table[i]!=NULL) {
				position = i;
				it = aTable->table[i]->newIterator();
				break;
			}
		}
	}
}

bool AssociativeTable::Tableiterator::equals(Iterator * right)
{
	size_t size1=0, size2 = 0;
	Tableiterator*it = (Tableiterator*)right;

	if (this->position != it->position) return false;
	if (this->aTable != it->aTable)return false; 
	if (this->thisList != it->thisList)return false;
	if (this->getElement(size1) != it->getElement(size2))return false;
	if (size1 != size2)return false;
	return true;
}
