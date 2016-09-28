/*
 * PersonLinkedList.h
 *
 *  Created on: Sep 27, 2016
 *      Author: collin
 */

#ifndef PERSONLINKEDLIST_H_
#define PERSONLINKEDLIST_H_

#include <string>

using namespace std;

struct personNode {
	string name;
	int age;
	personNode* nextPersonNode;
};

class PersonLinkedList {
private:
	personNode *root, *tail;
public:
	PersonLinkedList();
	virtual ~PersonLinkedList();
	void insert(personNode*);
	personNode getByName(string);
	void print();
};

#endif /* PERSONLINKEDLIST_H_ */
