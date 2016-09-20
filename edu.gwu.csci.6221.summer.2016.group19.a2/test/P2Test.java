import static org.junit.Assert.*;
import org.junit.Test;


public class P2Test {

	@Test
	public void P2_testRandomIntArray_Small() {
		int[][] vals = P2_testRandomIntArray(50);
		
		assertArrayEquals("Output values do not match expected values.", 
				vals[0], vals[1]);
	}
	
	@Test
	public void P2_testRandomIntArray_Medium() {
		int[][] vals = P2_testRandomIntArray(1000);
		
		assertArrayEquals("Output values do not match expected values.", 
				vals[0], vals[1]);
	}
	
	@Test
	public void P2_testRandomIntArray_Large() {
		int[][] vals = P2_testRandomIntArray(100000);
		
		assertArrayEquals("Output values do not match expected values.", 
				vals[0], vals[1]);
	}
	
	private int[][] P2_testRandomIntArray(int size) {
		int[] expectedValues = new int[size];
		for (int i = 1; i <= size; i++) {
			expectedValues[i-1] = i;
		}
		
		P2 p2 = new P2("" + size, false);
		int[] outputValues = p2.sort(p2.getNums());
		
		return new int[][]{expectedValues, outputValues};
	}

}
