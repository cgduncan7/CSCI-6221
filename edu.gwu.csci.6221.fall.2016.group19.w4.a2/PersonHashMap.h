/*
 * PersonHashMap.h
 *
 *  Created on: Sep 27, 2016
 *      Author: collin
 */

#ifndef PERSONHASHMAP_H_
#define PERSONHASHMAP_H_

#include "Person.h"

using namespace std;

class PersonHashMap {
private:
	Person **persons;
	const int SIZE = 8192;
public:
	PersonHashMap();
	virtual ~PersonHashMap();
	Person* findByName(string);
	Person* get(long);
	void put(Person*);
};

#endif /* PERSONHASHMAP_H_ */
