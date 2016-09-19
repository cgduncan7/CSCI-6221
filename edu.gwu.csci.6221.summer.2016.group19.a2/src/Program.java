import java.io.IOException;

/**
 * Interface for both P1 and P2 solutions to homework A2.
 * @author collin
 *
 */
public abstract class Program {
	private String name;
	private int[] nums;
	
	public Program(String name, String arg) {
		this.name = name;
		this.nums = parseInput(arg);
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}

	public int partition(int[] array, int low, int high) {
		// Select pivot as lowest element
		int pivot = array[low];
		int l = low - 1;
		int h = high + 1;
		
		while (true) {
			do {
				l++;
			} while (array[l] < pivot);
			
			do {
				h--;
			} while (array[h] > pivot);
			
			if (l >= h) {
				return h;
			}
			
			// Swap values array[l] and array[h]
			int temp = array[l];
			array[l] = array[h];
			array[h] = temp;
		}
	}
	
	public void run() {
		int[] sorted = sort(this.nums);
		
		System.out.print("Sorted values:\n [ ");
		for (int x : sorted) {
			System.out.print(x + " ");
		}
		System.out.println("]");
	}
	
	public static int[] parseInput(String arg) {
		try {
			int s = Integer.parseInt(arg);
			int[] nums = new int[s];
			for (int i = 0; i < s; i++) {
				nums[i] = 0;
			}
			
			for (int i = 1; i <= s;) {
				int index = (int) (Math.random() * s);
				if (nums[index] == 0) {
					nums[index] = i;
					i = i + 1;
				}
			}
			
			System.out.print("Input numbers:\n [ ");
			for (int i : nums) {
				System.out.print(i + " ");
			}
			System.out.println("]");
			
			return nums;
			
		} catch (NumberFormatException nfe) {
			try {
				// TODO: read from file
				throw new IOException();
			} catch (IOException ioe) {
				return null;
			}
		}
	}
	
	
	// TO IMPLEMENT
	public abstract int[] sort(int[] toSort);
}
