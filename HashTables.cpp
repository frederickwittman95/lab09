// Fred Wittman
// Dr. Hill
// lab 09
// 23 April 2019

// Main() is set up for ease of grading.

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int size_of_hashtable = 100;

struct Node {
	char value[1000] = "";
	Node* next = NULL;
};

int sfold(char* key) {
	unsigned int *lkey = (unsigned int *)key;
	int intlength = strlen(key) / 4;
	unsigned int sum = 0;
	for (int i = 0; i<intlength; i++) {
		sum += lkey[i];
	}

	int extra = strlen(key) - intlength * 4;
	char temp[4];
	lkey = (unsigned int *)temp;
	lkey[0] = 0;
	for (int i = 0; i<extra; i++) {
		temp[i] = key[intlength * 4 + i];
	}
	sum += lkey[0];
	return sum % size_of_hashtable;
}

// Modified code to allow user to insert multiple elements at a time: allowed for an easier testing framework
// Modified code to count number of collisions
void add_to_linked_hashtable(vector<Node> &hashtable) {
	int collisions = 0;
	cout << "Enter 'stop' to stop adding elements to the linked hashtable.";
	while (true) {
		char string[1000];
		cin >> string;
		if (strcmp(string, "stop") == 0) {
			cout << "Collisions during this round of inputs to the linked hashtable: " << collisions << endl;
			return;
		}
		int n = sfold(string);
		cout << "n: " << n << endl;
		Node * temp = new Node;
		strcpy_s(temp->value, string);
		cout << temp->value << endl;
		Node * position_to_insert = &hashtable[n];
		if (position_to_insert->next != NULL) {
			collisions++;
		}
		while (position_to_insert->next != NULL) {
			position_to_insert = position_to_insert->next;
		}
		position_to_insert->next = temp;
	}
}

// Modified code to allow user to insert multiple elements at a time: allowed for an easier testing framework
// Modified code to count number of collisions
void add_to_open_addressing_hashtable(vector<string> &hashtable)
{
		int collisions = 0;
		cout << "Enter 'stop' to stop adding elements to the open addressing hashtable." << endl;
		while (true) {
			char string[1000];
			cin >> string;
			if (strcmp(string, "stop") == 0) {
				cout << "Collisions during this round of inputs to the open addressing hashtable: " << collisions << endl;
				return;
			}
			int n = sfold(string);

			if (strcmp(hashtable[n].c_str(), "$")) {
				collisions++;
			}
			while (strcmp(hashtable[n].c_str(), "$") != 0) {
				n = (n + 1) % size_of_hashtable;
			}
			hashtable[n] = string;
			cout << "n: " << n << endl;
			cout << string << endl;
		}
	}


bool find_linked(vector<Node> hashtable, char string[1000]) {

	int n = sfold(string);
	Node * currNode = hashtable[n].next;
	while (currNode != NULL) {
		if (strcmp(string, currNode->value) == 0) {
			return true;
		}
		currNode = currNode->next;
	}
	return false;
}

// Uses linear probing
bool find_open(vector<string> hashtable, char string[1000]) {

	int size = hashtable.size();
	int n = sfold(string);
	const char * temp = hashtable[n].c_str();
	while (strcmp(string, temp) != 0) {
		if (strcmp(string, "$")) {
			return false;
		}
		n = (n + 1) % size;
		temp = hashtable[n].c_str();
	}
	return true;
}


int main() {

	// Testing harness for lab 09; this should make grading easier.

	vector<Node> linked_hashtable(100);
	vector<string> open_addressing_hashtable(100, "$");

	add_to_linked_hashtable(linked_hashtable);
	cout << "Printing linked hashtable: " << endl;
	Node *currNode = new Node;
	for (int i = 0; i<100; i++) {
		if (linked_hashtable[i].next != NULL) {
			currNode = linked_hashtable[i].next;
			while (currNode != NULL) {
				cout << i << " " << currNode->value << endl;
				currNode = currNode->next;
			}
		}
	}

	add_to_open_addressing_hashtable(open_addressing_hashtable);
	cout << "Printing open-addressing hashtable:" << endl;
	for (int i = 0; i < 100; i++) {
		if (open_addressing_hashtable[i] != "$") {
			cout << i << ": " << open_addressing_hashtable[i] << endl;
		}
	}

	cout << endl << "Enter strings you would like to check the linked hashtable for.  Enter 'stop' to move forward.";
	while (true) {
		char string[1000];
		cin >> string;
		if (strcmp(string, "stop") == 0) {
			break;
		}
		else if(find_linked(linked_hashtable, string)) {
			cout << string << " is in the linked hashtable." << endl;
		}
		else {
			cout << string << " is not in the hashtable" << endl;
		}
	}

	cout << endl << "Enter strings you would like to check the open addressing hashtable for.  Enter 'stop' to move forward.";
	while (true) {
		char string[1000];
		cin >> string;
		if (strcmp(string, "stop") == 0) {
			break;
		}
		else if (find_linked(linked_hashtable, string)) {
			cout << string << " is in the open addressing hashtable." << endl;
		}
		else {
			cout << string << " is not in the open addressing hashtable" << endl;
		}
	}
	return 0;
}



