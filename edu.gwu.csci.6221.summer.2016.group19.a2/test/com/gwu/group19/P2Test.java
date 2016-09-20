package com.gwu.group19;
import static org.junit.Assert.*;
import org.junit.Test;

import com.gwu.group19.P2;


public class P2Test {

	private int[] constructExpectedValues(int size) {
		int[] expectedValues = new int[size];
		for (int i = 1; i <= size; i++) {
			expectedValues[i-1] = i;
		}
		
		return expectedValues;
	}
	
	private int[][] P2_testRandomIntArray(int size) {
		
		int[] expectedValues = constructExpectedValues(size);
		
		P2 p2 = new P2("" + size, false);
		int[] outputValues = p2.sort(p2.getNums());
		
		return new int[][]{expectedValues, outputValues};
	}
	
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
	
	@Test
	public void P2_testFileInput_Small() {
		P2 p2 = new P2(System.getProperty("user.dir") + "/test/test_s.txt", false);
		int[] outputValues = p2.sort(p2.getNums());
		int[] expectedValues = constructExpectedValues(outputValues.length);
		assertArrayEquals("Output values do not match expected values.",
				expectedValues, outputValues);
	}
	
	@Test
	public void P2_testFileInput_Medium() {
		P2 p2 = new P2(System.getProperty("user.dir") + "/test/test_m.txt", false);
		int[] outputValues = p2.sort(p2.getNums());
		int[] expectedValues = constructExpectedValues(outputValues.length);
		assertArrayEquals("Output values do not match expected values.",
				expectedValues, outputValues);
	}
	
	@Test
	public void P2_testFileInput_Large() {
		P2 p2 = new P2(System.getProperty("user.dir") + "/test/test_l.txt", false);
		int[] outputValues = p2.sort(p2.getNums());
		int[] expectedValues = constructExpectedValues(outputValues.length);
		assertArrayEquals("Output values do not match expected values.",
				expectedValues, outputValues);
	}
}
