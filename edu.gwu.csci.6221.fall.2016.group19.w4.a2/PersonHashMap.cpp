/*
 * PersonHashMap.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: collin
 */

#include "PersonHashMap.h"
#include <iostream>


using namespace std;

PersonHashMap::PersonHashMap() {
	persons = new Person*[SIZE];

	for (int i = 0; i < SIZE; i++) {
		persons[i] = NULL;
	}
}

PersonHashMap::~PersonHashMap() {
	for (int i = 0; i < SIZE; i++) {
		if (persons[i] != NULL) {
			delete persons[i];
		}
	}

	delete [] persons;
}

Person* PersonHashMap::findByName(string name) {
	Person* p = new Person();
	long key = p->generateHashKey(name);
	p = get(key);
	return p;
}

Person* PersonHashMap::get(long key) {
	long hash = key % SIZE;
	while (persons[hash] != NULL && persons[hash]->getKey() != key) {
		hash = (hash + 1) % SIZE;
	}

	if (persons[hash] == NULL) {
		return new Person();
	}
	else {
		return persons[hash];
	}
}

void PersonHashMap::put(Person* person) {
	long key = person->getKey();
	long hash = key % SIZE;
	while (persons[hash] != NULL && (key % SIZE) != hash + 1) {
		hash = (hash + 1) % SIZE;
	}

	if (persons[hash] != NULL) {
		delete persons[hash];
	}

	persons[hash] = person;
}
