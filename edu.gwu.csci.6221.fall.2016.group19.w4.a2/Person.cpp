/*
 * Person.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: collin
 */

#include "Person.h"

using namespace std;

Person::Person() {
	init(-1, "", -1);
}

Person::~Person() {
	delete this;
}

Person::Person(string name) {
	init(generateHashKey(name), name);
}

Person::Person(string name, int age) {
	init(generateHashKey(name), name, age);
}

Person::Person(long key, string name, int age) {
	init(key, name, age);
}

void Person::init(long key, string name) {
	this->key = key;
	this->name = name;
	this->age = rand() % 100 + 1;
}

void Person::init(long key, string name, int age) {
	this->key = key;
	this->name = name;
	this->age = age;
}

long Person::generateHashKey(string name) {
	long hash = 11;
	for (int i = 0; i < name.length(); i++) {
		hash *= 13;
		hash += (int) name[i];
	}

	return hash;
}

long Person::getKey() {
	return key;
}

string Person::getName() {
	return name;
}

int Person::getAge() {
	return age;
}
