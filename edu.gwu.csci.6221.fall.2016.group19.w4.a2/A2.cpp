/*
 * A2.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: collin
 */

/*
 * A2.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: collin
 */

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

// Hash Map implementation
#include "PersonHashMap.h"

// Linked list implementation
#include "PersonLinkedList.h"

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

// Class which contains the key and value. The key is an integer created using generateHashKey(string name) where
// the parameter is the name of the person.

long double initializePersonHashMap(PersonHashMap* phm) {
	const int valuesToRead = -1; // -1 for all or specify an int
	long double sum = 0;

	ifstream nameFile ("names.txt");
	if (nameFile.is_open()) {
		string line;
		int x = 0;
		while (getline(nameFile, line) && (valuesToRead == -1 || x++ < valuesToRead)) {
			auto start = Clock::now();
			Person* p = new Person(line);
			phm->put(p);
			auto end = Clock::now();
			double timeToPut = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			sum += timeToPut;
		}
		nameFile.close();
	}
	else {
		cout << "Unable to open file.\n";
	}
	return sum;
}

long double testPersonHashMap(PersonHashMap* phm) {
	ifstream nameFile ("names.txt");
	long double sum = 0;
	if (nameFile.is_open()) {
		string line;
		while (getline(nameFile, line)) {
			auto start = Clock::now();
			Person* p = phm->findByName(line);
			auto end = Clock::now();
			double timeToFind = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			sum += timeToFind;
		}
		nameFile.close();
	}
	return sum;
}

long double initializePersonLinkedList(PersonLinkedList* pll) {
	const int valuesToRead = -1;
	long double sum = 0;

	ifstream nameFile ("names.txt");
	if (nameFile.is_open()) {
		string line;
		int x = 0;
		while (getline(nameFile, line) && (valuesToRead == -1 || x++ < valuesToRead)) {
			auto start = Clock::now();
			personNode* pn = new personNode;
			pn->name = line;
			pn->age = rand() % 100 + 1;
			pll->insert(pn);
			auto end = Clock::now();
			double timeToPut = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			sum += timeToPut;
		}
		nameFile.close();
	}
	return sum;
}

long double testPersonLinkedList(PersonLinkedList* pll) {
	ifstream nameFile2 ("names.txt");
	long double sum = 0;

	if (nameFile2.is_open()) {
		string line;
		while (getline(nameFile2, line)) {
			auto start = Clock::now();
			personNode p = pll->getByName(line);
			auto end = Clock::now();
			double timeToFind = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			sum += timeToFind;
		}
		nameFile2.close();
	}
	return sum;
}

int main() {
	// Initialize new random seed for age
	srand(time(NULL));

	long double hashTime = 0;
	long double hashSearchTime = 0;
	long double llTime = 0;
	long double llSearchTime = 0;

	PersonHashMap* phm = new PersonHashMap();
	hashTime += initializePersonHashMap(phm);
	hashSearchTime += testPersonHashMap(phm);

	PersonLinkedList* pll = new PersonLinkedList();
	llTime += initializePersonLinkedList(pll);
	llSearchTime += testPersonLinkedList(pll);

	cout << "Total time for initialization:\n\tHash:\t\t" << hashTime << "\n\tLinkedList:\t" << llTime << endl;
	cout << "Total time for finding:\n\tHash:\t\t" << hashSearchTime << "\n\tLinkedList:\t" << llSearchTime << endl;

	return 1;
}
