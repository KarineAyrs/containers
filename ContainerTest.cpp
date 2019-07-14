#include "ContainerTest.h"
//=========================================================

//Associative Table

//=========================================================
double ContainerTest::insertTimeTable(AssociativeTable * map, int numOfElem) {

	elems = (int*)malloc(numOfElem*sizeof(int));
	p_value = (int**)malloc(numOfElem*sizeof(int*));
	for (int i = 0; i < numOfElem; i++) {
		elems[i] = i;
		p_value[i] = &(elems[i]);
	}

	clock_t start = clock();
	for (int i = 0; i <numOfElem; i++) {
		map->insertByKey(p_value[i], sizeof(p_value[i]), p_value[i], sizeof(p_value[i]));
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double ContainerTest::removeAlltimeTable(AssociativeTable * map, int numOfElem) {

	clock_t start2 = clock();
	for (int i = 0; i < numOfElem; i++) {
		map->removeByKey(p_value[i], sizeof(p_value[i]));
	}
	clock_t end2 = clock();
	return (double)(end2 - start2) / CLOCKS_PER_SEC;
}

double ContainerTest::removeEvenElementsTable(AssociativeTable * map, int numOfElem) {

	clock_t start = clock();
	for (int i = 0; i < numOfElem; i++) {
		if (i % 2 == 0) {
			map->removeByKey(p_value[i], sizeof(p_value[i]));
		}
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double ContainerTest::removeOddElementsTable(AssociativeTable * map, int numOfElem) {

	clock_t start = clock();
	for (int i = 0; i < numOfElem; i++) {
		if (i % 2 != 0) {
			map->removeByKey(p_value[i], sizeof(p_value[i]));
		}
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double ContainerTest::removeAllTable(AssociativeTable * map, int numOfElem) {
	clock_t start2 = clock();
	for (int i = 0; i < numOfElem; i++) {
		map->removeByKey(p_value[i], sizeof(p_value[i]));
	}
	clock_t end2 = clock();
	return (double)(end2 - start2) / CLOCKS_PER_SEC;
}

char * ContainerTest::findEvenTable(AssociativeTable * map, int numOfElem) {

	for (int i = 0; i < numOfElem; i++) {
		if (i % 2 == 0) {
			if (map->findByKey(p_value[i], sizeof(p_value[i])) != nullptr) {
				void * this_num;
				size_t size;
				this_num = map->at(p_value[i], sizeof(p_value[i]), size);
				cout << *(int*)this_num << endl;
				return "fatal error! even nuber found!";
			}
		}
	}
	return "everything is ok!";
}

char * ContainerTest::findOddTable(AssociativeTable * map, int numOfElem) {
	for (int i = 0; i < numOfElem; i++) {
		if (i % 2 != 0) {
			if (map->findByKey(p_value[i], sizeof(p_value[i])) != nullptr) {
				void * this_num;
				size_t size;
				this_num = map->at(p_value[i], sizeof(p_value[i]), size);
				cout << *(int*)this_num << endl;
				return "fatal error! odd nuber found!\n";
			}
		}
	}
	return "everything is ok!\n";
}

char * ContainerTest::findDeletedElemsTable(AssociativeTable * map, int numOfElem) {
	for (int i = 0; i < numOfElem; i++) {
		if (map->find(p_value[i], sizeof(p_value[i])) != nullptr) {
			return "deleted element found! aaa!\n";
		}
	}
	return "everything is okey!\n";
}

char * ContainerTest::fastFindDeletedElemsTable(AssociativeTable * map, int numOfElem)
{
	for (int i = 0; i < numOfElem; i++) {
		if (map->findByKey(p_value[i], sizeof(p_value[i])) != nullptr) {
			return "deleted element found! aaa!\n";
		}
	}
	return "everything is okey!\n";
}

//================================================================

//DoubleLinked List

//================================================================

double ContainerTest::DLListInsertTime(DoubleLinkedList * dList, int numOfElem)
{
	elems = (int*)malloc(numOfElem*sizeof(int));
	p_value = (int**)malloc(numOfElem*sizeof(int*));
	for (int i = 0; i < numOfElem; i++) {
		elems[i] = i;
		p_value[i] = &(elems[i]);
	}

	clock_t start = clock();
	for (int i = 0; i <numOfElem; i++) {
		dList->push_front(p_value[i], sizeof(p_value[i]));
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double ContainerTest::DDListClearTime(DoubleLinkedList * dList)
{
	clock_t start = clock();
	dList->clear();
	clock_t end = clock();
	return  (double)(end - start) / CLOCKS_PER_SEC;
}

double ContainerTest::DDListRemoveTime(DoubleLinkedList * dList, int numOfElem)
{
	DoubleLinkedList::Iterator *it;
	it = dList->begin();
	clock_t start = clock();
	for (int i = 0; i < numOfElem; i++) {
		dList->remove(it);
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double ContainerTest::DLListDeleteEvenElements(DoubleLinkedList * dList, int numOfElem)
{
	DoubleLinkedList::Iterator *it;
	it = dList->begin();
	clock_t start = clock();
	for (int i = 0; i < numOfElem; i++) {
		if (i % 2 == 0) {
			dList->remove(it);
		}
		else {
			it->goToNext();
		}
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;

}

double ContainerTest::DLListDeleteOddElements(DoubleLinkedList * dList, int numOfElem)
{
	DoubleLinkedList::Iterator *it;
	it = dList->begin();
	clock_t start = clock();
	for (int i = 0; i < numOfElem; i++) {
		if (i % 2 != 0) {
			dList->remove(it);
		}
		else {
			it->goToNext();
		}
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;

}


