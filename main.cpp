#include <iostream>
#include <conio.h>
#include "DoubleLinkedList.h"
#include "Mem.h"
#include "AssociativeTable.h"
#include "ContainerTest.h"
using namespace std;

int main() {
	int N = 1000000;
	MemoryManager mem(N);
	AssociativeTable map(mem);
	DoubleLinkedList dList(mem);
	ContainerTest  test;



	cout << "//=========\nAssociativeTable Test N=" << N <<"\n//=========\n"<< endl;
	cout << "insert table time: " << test.insertTimeTable(&map, N) << "\n" << endl;
	cout << "mapSize: " << map.size() << "\n" << endl;
	//cout << "removeByIterator: " << test.removeAllTable(&map, N) << "\n" << endl;
	//cout << "mapSize: " << map.size() <<"\n"<< endl;
	cout << "remove Even: " << test.removeEvenElementsTable(&map, N) << "\n" << endl;
	cout << "mapSize: " << map.size() << "\n" << endl;
	cout << "find Even: " << test.findEvenTable(&map, N) << "\n" << endl;
	cout << "remove Odd: " << test.removeOddElementsTable(&map, N) << "\n" <<  endl;
	cout << "mapSize: " << map.size() << "\n" << endl;
	cout << "find Odd: " << test.findOddTable(&map, N) <<  endl;
	//cout << "find deleted elements: "<<test.fastFindDeletedElemsTable(&map, N) << endl;
	cout << "mapSize: " << map.size() << "\n" << endl;
	

	//=================
	
	//DoubleLinked List

	//=================

	cout << "//=========\nDoubleLinked List Test N=" << N << "\n//=========\n" << endl;
	cout << "insert DLList time: " << test.DLListInsertTime(&dList, N)<< "\n" << endl;
	cout <<"DLList size:"<< dList.size() << "\n" << endl;
	cout << "remove DLList time: "<<test.DDListRemoveTime(&dList, N) << "\n" << endl;
	//cout << "DLList delete even time: " << test.DLListDeleteEvenElements(&dList, N) << endl;
	//cout << "DLList delete odd time: " << test.DLListDeleteEvenElements(&dList, N) << endl;
	//cout << "clear  DLList time: " << test.DDListClearTime(&dList) << endl;
	cout << "DLList size:"<<dList.size() << "\n" << endl;



	
	_getch();
	return 0;
}












