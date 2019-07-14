#pragma once
#include <iostream>
#include "AssociativeTable.h"
#include <time.h>
using namespace std;

class ContainerTest{
private:
	int *elems;
	int **p_value;

public:
	//=================

	//Associative Table

	//=================

	double insertTimeTable(AssociativeTable *map, int numOfElem);

	double removeAlltimeTable(AssociativeTable*map, int numOfElem);

	double removeEvenElementsTable(AssociativeTable *map, int numOfElem);

	double removeOddElementsTable(AssociativeTable *map, int numOfElem);

	double removeAllTable(AssociativeTable *map, int numOfElem);

	char* findEvenTable(AssociativeTable *map, int numOfElem);

	char* findOddTable(AssociativeTable *map, int numOfElem);

	char* findDeletedElemsTable(AssociativeTable *map, int numOfElem);

	char* fastFindDeletedElemsTable(AssociativeTable *map, int numOfElem);
	
	//==================

	//DoubleLinked List

	//==================


	double DLListInsertTime(DoubleLinkedList *dList, int numOfElem);

	double DDListClearTime(DoubleLinkedList *dList);
	
	double DDListRemoveTime(DoubleLinkedList *dList, int numOfElem);
	
	double DLListDeleteEvenElements(DoubleLinkedList *dList, int numOfElem);
	
	double DLListDeleteOddElements(DoubleLinkedList *dList, int numOfElem);


};