/**
 * P2 - iterative quicksort
 * @author collin
 *
 */

public class P2 extends Program {

	public P2(String arg, boolean verbose) {
		this("P2", arg, verbose);
	}
	
	public P2(String name, String arg, boolean verbose) {
		super(name, arg, verbose);
	}

	public int[] sort(int[] nums) {
		return iterativeQuicksort(nums);
	}
	
	/**
	 * Instead of using recursive function calls we must
	 * implement a stack to keep track of each partition's
	 * low and high indices.
	 * 
	 * This uses the same partition method as the recursive
	 * quicksort.
	 * 
	 * @param toSort: int[]
	 * @return int[]
	 */
	private int[] iterativeQuicksort(int[] toSort) {
		int[] workingArray = toSort, stack;
		int pivot, 
			low = 0, 
			high = workingArray.length - 1,
			top = -1;
		
		stack = new int[high - low + 1];
		stack[++top] = low;
		stack[++top] = high;
		
		while (top > 0) {
			int h = stack[top--];
			int l = stack[top--];
			
			pivot = partition(workingArray, l, h);
			
			// if the right partition has >1 elements
			// add to stack
			if (pivot + 1 < h) {
				stack[++top] = pivot+1;
				stack[++top] = h;
			}
			
			// if the left partition has >1 elements
			// add to stack
			if (pivot > l) {
				stack[++top] = l;
				stack[++top] = pivot;
			}
		}
		
		return workingArray;
	}
}
