package com.gwu.group19;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Interface for both P1 and P2 solutions to homework A2.
 * Contains the partition, run, and parseInput methods used in P1/P2.
 * @author Collin Duncan, Mason Molesky, Anderson Thomas (Group 19)
 */
public abstract class Program {
	private String name;
	private int[] nums;
	private boolean verbose;
	
	public Program(String name, String arg, boolean verbose) {
		this.name = name;
		this.nums = parseInput(arg);
		this.verbose = verbose;
		if (getVerbose()) printArray("Input values:", this.nums);
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int[] getNums() {
		return this.nums;
	}
	
	public void setNums(int[] nums) {
		this.nums = nums;
	}

	public boolean getVerbose() {
		return this.verbose;
	}
	
	public void setVerbose(boolean v) {
		this.verbose = v;
	}

	/**
	 * Using the Hoare partition scheme. This scheme starts by using two indices at the ends
	 * of the array and then moving these indices towards each other until an inversion is
	 * detected. An inversion is when the low-order index is greater than the pivot, and the
	 * high-order index is less than the pivot. Then the two values are swapped.
	 * @param array: int[]
	 * @param low: int
	 * @param high: int
	 * @return int: pivot
	 */
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
	
	/**
	 * Calls the sort() method which is implemented individually in P1 and P2
	 */
	public void run() {
		int[] sorted = sort(this.nums);
		
		if (getVerbose()) printArray("Output values:", sorted);
	}
	
	/**
	 * Generates a random ordering of consecutive integers from 1 to size.
	 * @param size: int
	 * @return int[]: input
	 */
	public static int[] generateRandomIntArray(int size) {
		int[] nums = new int[size];
		for (int i = 0; i < size; i++) {
			nums[i] = 0;
		}
		
		for (int i = 1; i <= size;) {
			int index = (int) (Math.random() * size);
			if (nums[index] == 0) {
				nums[index] = i;
				i = i + 1;
			}
		}
		
		return nums;
	}
	
	/**
	 * Used in parseInput to read int[] from file
	 * @param filename: String
	 * @return int[]: input
	 * @throws FileNotFoundException: if filename is not a valid file
	 */
	public static int[] readIntArrayFromFile(String filename) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileReader(filename));
		
		ArrayList<Integer> t = new ArrayList<Integer>();
		while (scanner.hasNextInt()) {
			t.add(scanner.nextInt());
		}
		
		scanner.close();
		
		int[] numList = new int[t.size()];
		for (int i = 0; i < t.size(); i++) {
			numList[i] = t.get(i);
		}
		
		return numList;
	}
	
	/**
	 * Parses stdin and determines what to do next.
	 * Valid commands are:
	 * - java A2 P1 <integer | filename>
	 * - java A2 P2 <integer | filename>
	 * @param arg: String
	 * @return
	 */
	public static int[] parseInput(String arg) {
		try {
			// try to parse the arg as an integer, meaning that the user wants the
			// program to generate random integers to sort
			int s = Integer.parseInt(arg);
			return generateRandomIntArray(s);
			
		} catch (NumberFormatException nfe) {
			// if it's not an integer, it's a filepath and should be read accordingly
			try {
				return readIntArrayFromFile(arg);
			} catch (FileNotFoundException fnfe) {
				System.out.println(fnfe.getMessage());
				return null;
			}
		}
	}
	
	/**
	 * Prints an int[] along with a title
	 * @param title
	 * @param toPrint
	 */
	private static void printArray(String title, int[] toPrint) {
		System.out.print(title + "\n [ ");
		for (int i : toPrint) {
			System.out.print(i + " ");
		}
		System.out.println("]");
	}
	
	// TO IMPLEMENT
	public abstract int[] sort(int[] nums);
}
