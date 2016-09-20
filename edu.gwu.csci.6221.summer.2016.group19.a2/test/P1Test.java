import static org.junit.Assert.*;
import org.junit.Test;


public class P1Test {

	private int[] constructExpectedValues(int size) {
		int[] expectedValues = new int[size];
		for (int i = 1; i <= size; i++) {
			expectedValues[i-1] = i;
		}
		
		return expectedValues;
	}
	
	private int[][] P1_testRandomIntArray(int size) {
		
		int[] expectedValues = constructExpectedValues(size);
		
		P1 p1 = new P1("" + size, false);
		int[] outputValues = p1.sort(p1.getNums());
		
		return new int[][]{expectedValues, outputValues};
	}
	
	@Test
	public void P1_testRandomIntArray_Small() {
		int[][] vals = P1_testRandomIntArray(50);
		
		assertArrayEquals("Output values do not match expected values.", 
				vals[0], vals[1]);
	}
	
	@Test
	public void P1_testRandomIntArray_Medium() {
		int[][] vals = P1_testRandomIntArray(1000);
		
		assertArrayEquals("Output values do not match expected values.", 
				vals[0], vals[1]);
	}
	
	@Test
	public void P1_testRandomIntArray_Large() {
		int[][] vals = P1_testRandomIntArray(100000);
		
		assertArrayEquals("Output values do not match expected values.", 
				vals[0], vals[1]);
	}
	
	@Test
	public void P1_testFileInput_Small() {
		P1 p1 = new P1(System.getProperty("user.dir") + "/test/test_s.txt", false);
		int[] outputValues = p1.sort(p1.getNums());
		int[] expectedValues = constructExpectedValues(outputValues.length);
		assertArrayEquals("Output values do not match expected values.",
				expectedValues, outputValues);
	}
	
	@Test
	public void P1_testFileInput_Medium() {
		P1 p1 = new P1(System.getProperty("user.dir") + "/test/test_m.txt", false);
		int[] outputValues = p1.sort(p1.getNums());
		int[] expectedValues = constructExpectedValues(outputValues.length);
		assertArrayEquals("Output values do not match expected values.",
				expectedValues, outputValues);
	}
	
	@Test
	public void P1_testFileInput_Large() {
		P1 p1 = new P1(System.getProperty("user.dir") + "/test/test_l.txt", false);
		int[] outputValues = p1.sort(p1.getNums());
		int[] expectedValues = constructExpectedValues(outputValues.length);
		assertArrayEquals("Output values do not match expected values.",
				expectedValues, outputValues);
	}
}
