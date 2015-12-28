package practice.hashing;

import java.util.HashSet;

public class DupliWithinKDist {
	
	static boolean isDuplicatePresent(int arr[],int k){
		HashSet<Integer> hs=new HashSet<Integer>();
		
		for(int i=0;i<arr.length;i++){
			if(hs.contains(arr[i]))
				return true;
			
			hs.add(arr[i]);
			if(i>=k)
				hs.remove(arr[i-k]);
				
		}
		
		return false;
	}
	
	public static void main(String []args){
		int []arr={10,5,3,4,1,5,6};
		int k=3;
		if(DupliWithinKDist.isDuplicatePresent(arr, k))
			System.out.println("duplicates found within "+ k +" distance");
		else
			System.out.println("duplicates not found within "+ k + " distance");
	}

}
