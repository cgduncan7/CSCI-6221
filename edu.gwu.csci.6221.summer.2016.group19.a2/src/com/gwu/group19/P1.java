package com.gwu.group19;
import java.io.IOException;

/**
 * P1 - recursive quicksort
 * @author Collin Duncan, Mason Molesky, Anderson Thomas (Group 19)
 *
 */

public class P1 extends Program {

	public P1(String arg, boolean verbose) {
		this("P1", arg, verbose);
	}
	
	public P1(String name, String arg, boolean verbose) {
		super(name, arg, verbose);
	}
	
	public int[] sort(int[] toSort) {
		return recursiveQuicksort(toSort, 0, toSort.length - 1);
	}
	
	/**
	 * Recursive quicksort is very simple. While the partition has more
	 * than one element, split up the partition at a chosen pivot and
	 * call recursiveQuicksort on each of those partitions until an array
	 * of size one is reached.
	 * 
	 * This uses the same partition method as the iterative
	 * quicksort.
	 * 
	 * @param toSort: int[]
	 * @param low: int
	 * @param high: int
	 * @return int[]
	 */
	private int[] recursiveQuicksort(int[] toSort, int low, int high) {
		if (low < high) {
			int pivotIndex = partition(toSort, low, high);
			recursiveQuicksort(toSort, low, pivotIndex);
			recursiveQuicksort(toSort, pivotIndex + 1, high);
		}
		return toSort;
	}
}
