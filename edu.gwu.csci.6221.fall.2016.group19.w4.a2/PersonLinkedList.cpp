/*
 * PersonLinkedList.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: collin
 */

#include "PersonLinkedList.h"

using namespace std;

PersonLinkedList::PersonLinkedList() {
	root = new personNode;
	tail = root;
}

PersonLinkedList::~PersonLinkedList() {
	personNode* c = root;
	while (c->nextPersonNode != NULL) {
		personNode* t = c->nextPersonNode;
		delete c;
		c = t;
	}
	delete root;
}

void PersonLinkedList::insert(personNode* toInsert) {
	toInsert->nextPersonNode = NULL;
	tail->nextPersonNode = toInsert;
	tail = toInsert;
}

void PersonLinkedList::print() {
	personNode* c = root;
	while (c->nextPersonNode != NULL) {
		c = c->nextPersonNode;
	}
}

personNode PersonLinkedList::getByName(string name) {
	personNode* c = root;
	while (c->nextPersonNode != NULL) {
		c = c->nextPersonNode;
		if (c->name.compare(name) == 0) {
			return *c;
		}
	}
	return *(new personNode);
}
