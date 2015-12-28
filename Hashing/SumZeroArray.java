package practice.hashing;

import java.util.*;

public class SumZeroArray {
	
	static HashMap<Integer,Integer> hm= new HashMap<Integer,Integer>();
	
	static boolean printSubArray(int arr[]){
		int sum =0;
		for(int i=0;i<arr.length;i++){
			sum=sum+arr[i];
			if(arr[i]==0 || sum==0 ||hm.get(sum)!=null)
				return true;
			
			hm.put(sum, i);
		}
		
		return false;
		
	}
	
	public static void main(String [] args){
		int [] arr={4,2,3,1,6};
		
		if(SumZeroArray.printSubArray(arr))
			System.out.println("Found subarray with sum zero");
		else
			System.out.println("Subarray with sum zero not found");
		
	}

}
