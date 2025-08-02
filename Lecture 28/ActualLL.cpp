#include<iostream>
#include"../Header_Files/Linked_List.h"
using namespace std;


int main() {

	int n;
	cin >> n;

	node<int>*head = nullptr;
	// node *head = NULL;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		/*
			I want these data to be
			inserted in Linked List.
		*/
		InsertAtHead(head, x);
	}

	Print(head);
	cout << length(head) << endl;
	cout << SearchLL(head, 5) << endl;
	cout << SearchRecursivelyLL(head, 5) << endl;
	cout << MidPointLL(head) << endl;
	cout << MidPoint2LL(head) << endl;
	cout << MidPoint3LL(head) << endl;
}










