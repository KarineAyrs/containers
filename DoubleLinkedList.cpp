#include "DoubleLinkedList.h"
#include <iostream>
#include<string.h>


int DoubleLinkedList::push_back(void * elem, size_t elemSize){

	Node *temp;
	temp = Tail;
	Node *new_el = new Node();
	memcpy(&(new_el->value), &elem, elemSize);
	new_el->size = elemSize;
	new_el->next = NULL;

	if (Tail!= NULL) {
		temp->next = new_el;
		new_el->prev = temp;
		Tail = new_el;
	}
	else {
		new_el->prev = NULL;
		Tail = new_el; Head = new_el;
	}
	nsize++;
	return 0;
}

int DoubleLinkedList::push_front(void * elem, size_t elemSize){
	
	
	Node * new_el = new Node();
	new_el->value = elem;
	new_el->size = elemSize;
	new_el->prev = NULL;

	if (Head == NULL) {
		Head = new_el;
		Tail = Head;
		nsize++;
	}
	else {
		Node *temp, *next;
		temp = Head;
		Head = new_el;
		Head->next = temp;
		temp->prev = Head;
		nsize++;
	}

	return 0;
}



void DoubleLinkedList::pop_back(){
	Node *last, *temp1;
	last = Tail;
	temp1 = last->prev;
	temp1->next = NULL;
	Tail = temp1;
	nsize--;
	free(last);
}

void DoubleLinkedList::pop_front(){
	if (Head != NULL) {
		Head->prev = NULL;
		Head = Head->next;
		nsize--;
	}
}

void * DoubleLinkedList::front(size_t & size){
	if (Head != NULL) {
		size = Head->size;
		return Head->value;
	}
	else return NULL;
}

void * DoubleLinkedList::back(size_t & size){
	if (Tail != NULL) {
		size = Tail->size;
		return Tail->value;
	}
	else return NULL;
}

void DoubleLinkedList::printList(){
	Node *temp = Head;
	while (temp != NULL) {
		cout << *(int*)temp->value << endl;
		temp = temp->next;
	}
}

int DoubleLinkedList::size(){
	return nsize;
}

void DoubleLinkedList::clear(){

	while (Head !=NULL) {
		Node *temp ;
		temp =Head;
		Head = Head->next;
		free(temp);
		nsize--;
	}

	if(Tail!=NULL) free(Tail);
	if (Last != NULL) { free(Last); Last = NULL; }
	Head = Tail = NULL;	
}

bool DoubleLinkedList::empty(){

	if (Head == NULL) return true;
	return false;
}

Container::Iterator * DoubleLinkedList::find(void * elem, size_t size){

	MyIterator *it=new MyIterator(this, Head);
	if (it->thisElem != NULL) {
		size_t eSize = 0;
		for (int i = 0; i < nsize; i++) {
			if (memcmp(elem, (it->getElement(eSize)), size) == 0) {
				if (eSize == size) {
					return it;
				}
			}
		}
		return nullptr;
	}
}
Container::Iterator * DoubleLinkedList::newIterator(){
	if (this->Head != NULL) {
		MyIterator *it = new MyIterator(this, Head);
		return it;
	}
	return nullptr;
}
Container::Iterator * DoubleLinkedList::begin(){
	if (this->Head != NULL) {
		MyIterator *it = new MyIterator(this, Head);
		return it;
	}
	return nullptr;
}
int DoubleLinkedList::insert(Iterator * iter, void * elem, size_t elemSize){
	if (iter != NULL) {
		MyIterator *it = (MyIterator*)iter;
		if (it->thisElem != NULL) {
			it->thisElem->value = elem;
			it->thisElem->size = elemSize;
			return 0;
		}
		return 1;
	}
	return 1;
}
Container::Iterator * DoubleLinkedList::end() {
	
	if (Tail->value != NULL) {
		Last = new Node();
		memcpy(&(Last->value),&(Tail->value), Tail->size);
		Last->size = 0;
		Last->prev = Tail;
		Tail->next = Last;

		MyIterator *it = new MyIterator(this, Last);
		return it;
	}
	return nullptr;
}
void DoubleLinkedList::remove(Container::Iterator * iter) {
	MyIterator *it = (MyIterator*)iter;
	if (it->thisElem != NULL) {


		Node *n, *p, *temp;
		temp = it->thisElem;
		n = temp->next;
		p = temp->prev;
		if (p != NULL) {
			p->next = n;
		}
		if (n != NULL) {
			n->prev = p;
		}
		if (it->thisElem == Head) {
			Head = n;
		}
		free(temp);
		nsize--;
		it->thisElem = n;
		if (nsize == 0) { Head = Tail = NULL; }
	}
}
void * DoubleLinkedList::MyIterator::getElement(size_t & size){
	if (thisElem != NULL) {
		size = thisElem->size;
		return thisElem->value;
	}
	return nullptr;
}

bool DoubleLinkedList::MyIterator::hasNext(){
	if (thisElem!=NULL && thisElem->next != NULL) {
		return true;
	}
	return false;
}

void DoubleLinkedList::MyIterator::goToNext(){

	if (thisElem->next != NULL) {
		memcpy(&thisElem, &(thisElem->next), sizeof(thisElem->next));
	}
}

bool DoubleLinkedList::MyIterator::equals(Iterator * right){
	MyIterator *iterator = (MyIterator*)right;
	if (iterator == NULL) return false;
	if (iterator->thisElem == NULL)return false;
	if (iterator->thisElem->size != this->thisElem->size) return false;
	if (memcmp(iterator->thisElem->value, this->thisElem->value, iterator->thisElem->size) != NULL) return false;
	return true;
}
