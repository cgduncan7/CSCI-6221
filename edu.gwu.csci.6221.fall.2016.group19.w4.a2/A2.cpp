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

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

// Class which contains the key and value. The key is an integer created using generateHashKey(string name) where
// the parameter is the name of the person.
class Person {
private:
	long key;
	string name;
	int age;

public:

	Person() {
		init(-1, "", -1);
	}

	Person(string name) {
		init(generateHashKey(name), name);
	}

	Person(string name, int age) {
		init(generateHashKey(name), name, age);
	}

	Person(long key, string name, int age) {
		init(key, name, age);
	}

	void init(long key, string name) {
		this->key = key;
		this->name = name;
		this->age = rand() % 100 + 1;
	}

	void init(long key, string name, int age) {
		this->key = key;
		this->name = name;
		this->age = age;
	}

	long generateHashKey(string name) {
		long hash = 11;
		for (int i = 0; i < name.length(); i++) {
			hash *= 13;
			hash += (int) name[i];
		}

		return hash;
	}

	long getKey() {
		return key;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}
};

class PersonHashMap {
private:
	Person **persons;
	const int SIZE = 8192;

public:
	PersonHashMap() {
		persons = new Person*[SIZE];

		for (int i = 0; i < SIZE; i++) {
			persons[i] = NULL;
		}
	}

	~PersonHashMap() {
		for (int i = 0; i < SIZE; i++) {
			if (persons[i] != NULL) {
				delete persons[i];
			}
		}

		delete [] persons;
	}

	Person findByName(string name) {
		Person* toFind = new Person(name);

		return get(*toFind);
	}

	Person get(Person toFind) {
		return get(toFind.getKey());
	}

	Person get(long key) {
		long hash = key % SIZE;
		while (persons[hash] != NULL && persons[hash]->getKey() != key) {
			hash = (hash + 1) % SIZE;
		}

		if (persons[hash] == NULL) {
			return *(new Person());
		}
		else {
			return *(persons[hash]);
		}
	}

	void put(Person* person) {
		long key = person->getKey();
		long hash = key % SIZE;
		while (persons[hash] != NULL && (key % SIZE) != hash + 1) {
			hash = (hash + 1) % SIZE;
		}

		if (persons[hash] != NULL) {
			cout << "Out of space... deleting to make room." << endl;
			delete persons[hash];
		}

		persons[hash] = person;
	}
};

struct personNode {
	Person person;
	personNode* nextPersonNode;
};

class PersonLinkedList {
private:
	personNode* root;
	personNode* tail;
public:
	PersonLinkedList() {
		root = new personNode;
		tail = root;
	}

	void insert(Person* person) {
		personNode* toInsert = new personNode;
		toInsert->person = *person;
		toInsert->nextPersonNode = NULL;
		tail->nextPersonNode = toInsert;
		tail = toInsert;
	}

	void print() {
		personNode* c = root;
		int x = 0;
		while (c->nextPersonNode != NULL) {
			c = c->nextPersonNode;
			cout << c->person.getName() << endl;
		}
	}

	Person getByName(string name) {
		personNode* c = root;
		while (c->nextPersonNode != NULL) {
			c = c->nextPersonNode;
			if (c->person.getName().compare(name) == 0) {
				return c->person;
			}
		}

		return *(new Person);
	}
};

PersonHashMap* createPersonHashMap() {
	PersonHashMap* phm = new PersonHashMap();
	const int valuesToRead = -1; // -1 for all or specify an int

	ifstream nameFile ("names.txt");
	if (nameFile.is_open()) {
		string line;
		int x = 0;
		long double sum = 0;
		while (getline(nameFile, line) && (valuesToRead == -1 || x < valuesToRead)) {
			x++;
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
	return phm;
}

double testPersonHashMap(PersonHashMap* phm) {
	ifstream nameFile2 ("names.txt");
	if (nameFile2.is_open()) {
		string line;
		int x = 0;
		long double sum = 0;
		while (getline(nameFile2, line)) {
			auto start = Clock::now();
			Person p = phm->findByName(line);
			auto end = Clock::now();
			double timeToFind = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			sum += timeToFind;
			x++;
			if (p.getName().length() > 0) {
//				cout << "Found\t" <<
//						"NAME:" << p.getName() <<
//						"  AGE:" << p.getAge() <<
//						"  in " << timeToFind << " ns." << endl;
			}
			else {
				cout << "No person with that name exists in map." << endl;
			}
		}
		nameFile2.close();

		cout << "Total time for " << x << " finds: " << sum << " ns." << endl;

		return sum;
	} else {
		cout << "Unable to open file.\n";
		return -1;
	}
}

PersonLinkedList* createPersonLinkedList() {
	PersonLinkedList* pll = new PersonLinkedList();
	const int valuesToRead = -1;

	ifstream nameFile ("names.txt");
	if (nameFile.is_open()) {
		string line;
		int x = 0;
		long double sum = 0;
		while (getline(nameFile, line) && (valuesToRead == -1 || x < valuesToRead)) {
			x++;
			auto start = Clock::now();
			Person* p = new Person(line);
			personNode* pn = new personNode;
			pll->insert(p);
			auto end = Clock::now();
			double timeToPut = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			sum += timeToPut;
		}
		cout << "LinkedList initialized with " << x << " values in " << sum << " ns." << endl;
		nameFile.close();
	}
	else {
		cout << "Unable to open file.\n";
	}
	return pll;
}

double testPersonLinkedList(PersonLinkedList* pll) {
	ifstream nameFile2 ("names.txt");
	if (nameFile2.is_open()) {
		string line;
		int x = 0;
		long double sum = 0;
		while (getline(nameFile2, line)) {
			auto start = Clock::now();
			Person p = pll->getByName(line);
			auto end = Clock::now();
			double timeToFind = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			sum += timeToFind;
			x++;
			if (p.getName().length() > 0) {
				/*cout << "Found\t" <<
						"NAME:" << p.getName() <<
						"  AGE:" << p.getAge() <<
						"  in " << timeToFind << " ns." << endl;*/
			}
			else {
				cout << "No person with that name (" << line << ") exists in list." << endl;
			}
		}
		nameFile2.close();

		cout << "Total time for " << x << " finds: " << sum << " ns." << endl;

		return sum;
	} else {
		cout << "Unable to open file.\n";
		return -1;
	}
}

int main() {
	// Initialize new random seed for age
	srand(time(NULL));

	PersonHashMap* phm = createPersonHashMap();
	testPersonHashMap(phm);

	PersonLinkedList* pll = createPersonLinkedList();
	testPersonLinkedList(pll);

	return 1;
}
