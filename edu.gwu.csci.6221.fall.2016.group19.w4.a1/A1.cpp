/*
 * A1.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: collin
 */

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// Used to monitor system time in nanoseconds
typedef std::chrono::high_resolution_clock Clock;

/**
 * Data structure to hold aggregate stats of each array implementation
 */
struct timeStats {
public:
	string name;
	double total = 0;
	double min = 0;
	double max = 0;
	int iterations = 0;
};

/**
 * Function that creates an integer array on the stack of size arraySize. This function returns the
 * time it takes to complete the function in nanoseconds.
 */
double createStackArray(int arraySize);

/**
 * Function that creates an integer array on the heap of size arraySize. This function returns the
 * time it takes to complete the function in nanoseconds.
 */
double createHeapArray(int arraySize);

/**
 * This function updates the aggregate statistics of stats* based on the double newTime.
 */
void manageStats(timeStats* stats, double newTime);

/**
 * This function prints out the aggregate stats contained in timeStats* stats.
 */
void printStats(timeStats* stats);

int main() {

	const int loops = 1000000;
	const int size = 1000;

	timeStats heap;
	timeStats stack;
	heap.name = "Heap";
	stack.name = "Stack";

	int i;

	for (i = 0; i < loops; i++) {
		double stackTime = createStackArray(size);
		manageStats(&stack, stackTime);

		double heapTime = createHeapArray(size);
		manageStats(&heap, heapTime);
	}

	printStats(&stack);
	printStats(&heap);

	return 1;
}

// stack implementation of array
double createStackArray(int arraySize) {
	auto startTime = Clock::now();

	int array[arraySize];

	return chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - startTime).count();
}

// heap implementation of array. NOTE: Delete is performed after time has stopped.
double createHeapArray(int arraySize) {
	auto startTime = Clock::now();

	int* array = new int[arraySize];

	double time = chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - startTime).count();

	delete [] array;

	return time;
}

void manageStats(timeStats* stats, double newTime) {
	stats->total += newTime;
	stats->iterations = stats-> iterations + 1;

	if (stats->min == 0 || stats->min > newTime) {
		stats->min = newTime;
	}

	if (stats->max == 0 || stats->max < newTime) {
		stats->max = newTime;
	}
}

void printStats(timeStats* stats) {
	cout << stats->name << " stats:\n"
			  << "\tIterations:\t" << stats->iterations << "\n"
			  << "\tTotal time:\t" << stats->total << " ns\n"
			  << "\tAverage time:\t" << stats->total / stats->iterations << " ns\n"
			  << "\tMinimum time:\t" << stats->min << " ns\n"
			  << "\tMaximum time:\t" << stats->max << " ns\n\n";
}
