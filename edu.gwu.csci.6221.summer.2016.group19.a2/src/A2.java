/**
 * CSCI 6221 - Advanced Software Paradigms - Homework 2 - A2
 * 
 * A2
 * ==
 * 
 * This is the main file for the homework and will provide access to the two problems' solutions. An example
 * of correct usage would be:
 * 		java A2 P1 30
 * where this runs P1 (recursive quicksort) over a randomly ordered array of integers, x, where 1 <= x <= 30.
 * 
 * You can also use a file where integers are delimited by a single, non-integer character (space, comma, etc.)
 * 		java A2 P1 inputs.txt
 * Where inputs.txt:
 * 		1 5 9 2 4 3 6 8 7 10
 * 
 * @author collin
 */
public class A2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 2) { 
			System.out.println("Invalid number of arguments.\nEx: java A2 P2 <number of random integers to sort | filename>");
			System.exit(-1);
		}
		
		Program p = null;
		if (args[0].equals("P1")) {
			p = new P1(args[1], true);
		} else if (args[0].equals("P2")) {
			p = new P2(args[1], true);
		} else { 
			System.out.println("Invalid arguments.\nEx: java A2 P2 <number of random integers to sort | filename>");
			System.exit(-1);
		}
		
		if (p != null) 
			p.run();
	}
}
