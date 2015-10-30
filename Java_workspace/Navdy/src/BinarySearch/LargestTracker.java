package BinarySearch;

import java.util.ArrayList;
import java.util.List;

public class LargestTracker {
	private int TABLESIZE = 128;
	private int index = 0;
	/* using ping-pong buffer to avoid allocating array frequently*/
	private int[] arr1 = new int[TABLESIZE];
	private int[] arr2 = new int[TABLESIZE];
	
	private final static LargestTracker singleton = new LargestTracker();
	/**
	 * 
	 * Guarantees the creation of a single instance across the virtual machine.
	 * Assumed to be called very frequently.
	 * 
	 * @return an instance of LargestTracker
	 */

	static LargestTracker getInstance() {
		return singleton;
	}

	/**
	 * Returns a list in O(n log m) time OR BETTER where n is the number of
	 * entries added to LargestTracker and m is numberOfTopLargestElements.
	 * Duplicates are allowed
	 * 
	 * @param numberOfTopLargestElements
	 *        the number of top-most-elements to return
	 * @return the top-most-elements in the tracker sorted in ascending order
	 */
	List<Integer> getNLargest(int numberOfTopLargestElements){

		List<Integer> ret = new ArrayList<Integer>();
		synchronized(this) {
			if (numberOfTopLargestElements > index)
				numberOfTopLargestElements = index;
			
			/* O(m) since the internal array is already sorted */
			for (int i = index-numberOfTopLargestElements; i < index ; i++) {
				ret.add(arr1[i]);
			}
		}
		return ret;
	}

	private int[] resizeArray(int[] oldArray, int newSize) {
		int oldSize = oldArray.length;
		int[] newArray = new int[newSize];
		int preserveLength = Math.min(oldSize, newSize);
		if (preserveLength > 0)
			System.arraycopy(oldArray, 0, newArray, 0, preserveLength);
		return newArray;
	}

	private int quickselect(int[] arr, int anEntry, int a, int b) {
		int start = a;
		int end = b;
		while (start+1 < end) {
				int mid = start + (end-start)/2;
				if (arr[mid] > anEntry)
					end = mid;
				else if (arr[mid] < anEntry)
					start = mid;
				else
					return mid;
		}
		
		if(anEntry <= arr[start])
			return start;
		else if (anEntry <= arr[end])
			return end;
		else
			return end+1;
	}
	
	/**
	 * 
	 * Adds an entry to the tracker. This method must operate in O(log n) time
	 * OR BETTER
	 * 
	 * @param anEntry
	 * the entry to add to the tracker. Entries need not be unique.
	 */
	void add(int anEntry) {
		synchronized(this) {
			if (index == 0) {
				arr1[0] = anEntry;
				arr2[0] = anEntry;
				index++;
				return;
			}
			
			if (index == arr1.length) {
					arr1 = resizeArray(arr1, 2*arr1.length);
					arr2 = resizeArray(arr2, 2*arr2.length);
			}
			
			/* Binary search O(logN): find the insert position */
			int pos = quickselect(arr1, anEntry, 0, index -1);
			
			/* copy data from arr1 to arr2, the restore arr1 
			 * Supposing arraycopy is in O(1)? if it is in O(n), need new solution. 
			 */
			System.arraycopy(arr1, pos, arr2, pos+1, index-pos);
			arr2[pos] = anEntry;
			index++;
			
			System.arraycopy(arr2, 0, arr1, 0, index);
		}
	}

	/**
	 * Removes all the entries from the tracker. This should return in constant
	 * time.
	 */

	void clear() {
		arr1 = new int[TABLESIZE];
		arr2 = new int[TABLESIZE];
		index = 0;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LargestTracker tmp = LargestTracker.getInstance();
		tmp.add(3);
		tmp.add(8);
		tmp.add(12);
		tmp.add(14);
		tmp.add(24);
		tmp.add(13);
		tmp.add(15);
		tmp.add(20);
		List<Integer> x = tmp.getNLargest(18);
		for (int i = 0; i < x.size(); i++) {
			System.out.printf("%d ", x.get(i));
		}
	}

}
