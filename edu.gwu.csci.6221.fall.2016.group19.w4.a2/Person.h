/*
 * Person.h
 *
 *  Created on: Sep 27, 2016
 *      Author: collin
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

using namespace std;

class Person {
private:
	long key;
	string name;
	int age;
public:
	Person();
	virtual ~Person();
	Person(string);
	Person(string, int);
	Person(long, string, int);
	void init(long, string);
	void init(long, string, int);
	long generateHashKey(string);
	long getKey();
	string getName();
	int getAge();
};

#endif /* PERSON_H_ */ */
