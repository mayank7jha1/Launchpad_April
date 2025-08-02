#include<iostream>
#include"node.h"
using namespace std;


//Insertion in Linked List.
template<typename T>
void InsertAtHead(node<T>*&h, T d) {

	//Defined and Initialised using parameterised Constructor
	node<T>*n = new node<T>(d);

	//Insertion At Old Head whose address is
	//stored in pointer h.

	// (*n).next = h;
	n->next = h;
	h = n;
};


template<typename T>
void Print(node<T>* head) {

	while (head != NULL) {
		cout << head->data << " ---> ";
		head = head->next;
	}
	cout << "NULL" << endl;

	// node<T>*temp = head;
	// while (temp != NULL) {
	// 	cout << temp->data << " ---> ";
	// 	temp = temp->next;
	// }
	// cout << "NULL" << endl;
}

//Length
template<typename T>
int length(node<T>* head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

//Linear Search
template<typename T>
bool SearchLL(node<T>*head, int key) {

	while (head != NULL) {
		if (head->data == key) {
			return true;
		}

		head = head->next;
	}

	return false;
}


template<typename T>
bool SearchRecursivelyLL(node<T>*head, int key) {

	//Base Condition
	if (head == NULL) {
		return false;
	}

	//Current State: SearchRecursivelyLL(head,key)
	//Task
	if (head->data == key) {
		return true;
	}

	//Next state:
	return SearchRecursivelyLL(head->next, key);
}

//MidPoint in Linked List
template<typename T>
T MidPointLL(node<T>*head) {
	int len = length(head);
	len /= 2;

	while (len > 0) {
		head = head->next;
		len--;
	}

	//I am at the Mid Point.
	return head->data;
}


template<typename T>
T MidPoint2LL(node<T>*head) {

	node<T>*slow = head;//x
	node<T>*fast = head;//2x

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		// fast = fast->next;
		// fast = fast->next;
		slow = slow->next;
	}

	/*
		Odd ke case me mid point and
		even ke case me second mid point.
	*/
	return slow->data;
}

template<typename T>
T MidPoint3LL(node<T>*head) {

	node<T>*slow = head;//x
	node<T>*fast = head->next;//2x


	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		// fast = fast->next;
		// fast = fast->next;
		slow = slow->next;
	}

	/*
		Odd ke case me mid point and
		even ke case me first mid point.
	*/
	return slow->data;
}

template<typename T>
void Cycle_Creation(node<T>* head) {

	node<T>*tail = head;
	while (tail->next = NULL) {
		tail = tail->next;
	}

	//Cycle is to be created at the
	//fourth node from start.

	tail->next = head->next->next->next;
	return;
}


template<typename T>
bool IsCycle(node<T>* head) {
	node<T>*slow = head;
	node<T>*fast = head;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;//x
		fast = fast->next->next;//2x

		if (slow == fast) {
			return true;
		}
	}
	return false;
}


template<typename T>
void Cycle_Removal(node<T>* head) {



}










