// Sorting.cpp : Defines the entry point for the console application.
//

// Still need to add times!

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

// Insert Node in List
void insert(DoublyLinkedList<int> listy, int val)
{
	listy.insertNode(val);
}

// Find Node in List
void lookup(DoublyLinkedList<int> listy, int val)
{
	if (listy.find(val) != nullptr)
	{
		auto foundNode = *listy.find(val);
		cout << "Found: " << foundNode.getData() << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

// Delete Node in List
void destroy(DoublyLinkedList<int> listy, int val)
{
	listy.deleteNode(val);
}

// Display all nodes in list
void display(DoublyLinkedList<int> listy)
{
	listy.displayList();
}

// Sort Bubble Sort
void sortWithBubble(DoublyLinkedList<int> listy)
{
	long double duration;
	clock_t start = clock();
	listy.bubbleSort();
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << "This took: " << duration << " seconds to complete" << endl;
}

// Sort Selection Sort
void sortWithSelection(DoublyLinkedList<int> listy)
{
	long double duration;
	clock_t start = clock();
	listy.selectionSort();
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << "This took: " << duration << " seconds to complete" << endl;
}

// Automated Suite
void automatedTest()
{
	cout << "Bubble Sort" << endl;
	int unsortedInts[10] = { 50,40,20,60,70,80,10,30,90,0 };
	DoublyLinkedList<int> list1;
	for (int i = 0; i < sizeof(unsortedInts) / sizeof(int); i++)
	{
		list1.insertNode(unsortedInts[i]);
	}
	cout << "List to Sort: " << endl;
	list1.displayList();
	cout << "Sorted List: " << endl;
	list1.bubbleSort();
	list1.displayList();

	cout << "Selection Sort" << endl;
	DoublyLinkedList<int> list2;
	for (int i = 0; i < sizeof(unsortedInts) / sizeof(int); i++)
	{
		list2.insertNode(unsortedInts[i]);
	}
	cout << "List to Sort: " << endl;
	list2.displayList();
	cout << "Sorted List: " << endl;
	list2.selectionSort();
	list2.displayList();
}

// Simply Display Menu
void displayMenu()
{
	cout << "Menu Options:" << endl;
	cout << "1. Insert Node in List" << endl;
	cout << "2. Lookup Node in List" << endl;
	cout << "3. Delete Node in List" << endl;
	cout << "4. Sort List (Bubble Sort)" << endl;
	cout << "5. Sort List (Selection Sort)" << endl;
	cout << "6. Display List" << endl;
	cout << "7. Complete Automated Suite" << endl;
	cout << "99. Exit Program" << endl;
}

// Display a welcome screen with a brief introduction to the program
void displayStart()
{
	cout << "Welcome to my Linked-List Program" << endl;
	cout << "This is a templated linked list" << endl;
	cout << "For the purposes of this test the default table is of int type" << endl;
	system("pause");
}

int main()
{
	// variables
	int choice;
	int value;
	DoublyLinkedList<int> dlList;

	displayStart();

	// main program loop
	do
	{
		displayMenu();
		cout << "Please select a menu option" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "Choose a value to insert" << endl;
				cin >> value;
				cout << endl;
				insert(dlList, value);
				break;
			}
			case 2:
			{
				cout << "What node would you like to look up?" << endl;
				cin >> value;
				cout << endl;
				lookup(dlList, value);
				break;
			}
			case 3:
			{
				cout << "What node would you like to delete?" << endl;
				cin >> value;
				cout << endl;
				destroy(dlList, value);
				break;
			}
			case 4:
			{
				sortWithBubble(dlList);
				break;
			}
			case 5:
			{
				sortWithSelection(dlList);
				break;
			}
			case 6:
			{
				display(dlList);
				break;
			}
			case 7:
			{
				automatedTest();
				break;
			}
			case 99:
			{
				cout << "Exiting Program" << endl;
				break;
			}
			default:
			{
				cout << "Invalid option selected" << endl;
				cout << "Please select a valid option from the menu" << endl;
				break;
			}
		}
		system("pause");
		system("cls");
	} while (choice != 99);
}

