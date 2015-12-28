package practice.hashing;

import java.util.HashMap;

public class DistinctElementInWindow {
	
	
	
	static void printDistCount(int arr[],int k){
		HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>();
		int distCount=0;
		
		for(int i=0;i<k;i++){
			
			if(hm.get(arr[i])==null){
				distCount++;
				hm.put(arr[i],1 );
			}
			else{
				int val=hm.get(arr[i]);
				hm.put(arr[i],++val );
			}
			
		}
		System.out.println(distCount);
		
		for(int i=k;i<arr.length;i++){
			
			
			if(hm.get(arr[i-k])==1){
				hm.remove(arr[i-k]);
				distCount--;
			}
			else{
				int val=hm.get(arr[i-k]);
				hm.put(arr[i-k],--val);
			}
			
			if(hm.get(arr[i])!=null){
				int val=hm.get(arr[i]);
				hm.put(arr[i],++val);
			}
			else{
				hm.put(arr[i],1);
				distCount++;
				
			}
			System.out.println(distCount);
			
		}
	}
	
	public static void main(String [] args){
		int []arr={1,2,1,1,3,4,2,3};
		DistinctElementInWindow.printDistCount(arr,4);
	}

}
