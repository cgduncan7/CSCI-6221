import java.io.IOException;

/**
 * P1 - recursive quicksort
 * @author collin
 *
 */

public class P1 extends Program {

	public P1(String arg) {
		this("P1", arg);
	}
	
	public P1(String name, String arg) {
		super(name, arg);
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
