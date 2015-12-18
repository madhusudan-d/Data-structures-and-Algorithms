package practice;

import java.util.*;


public class PalinndromeDp {
	
	String str;
	int length;
	char []str1;
	
	HashMap<String,Integer> hm =new HashMap<String,Integer>();
	
	PalinndromeDp(String str,int length){
		this.str=str;
		str1=str.toCharArray();
		this.length=length;
		
	}
	
	void searchPalindrome(){
		int i,start,end;
		
		for(i=0;i<length;i++){
			
			//for finding  odd length palindrome
			start=i-1;
			end=i+1;
			while(start>=0 && end<length && str1[start]==str1[end]){
				start--;
				end++;	
				if(start!=i-1 ||end!=i+1){	
					storePalindrome(start+1, end);
				}
			}
			
				
			
			//for finding even length palindrome
			start=i;
			end=i;
			while(start>=0 && end<length && str1[start]==str1[end]){
				start--;
				end++;
				storePalindrome(start+1,end);
			}	
			
		}
		
	}
	
	 void storePalindrome(int start,int end){
		String s=str.substring(start, end);
		//System.out.println(s);
		hm.put(s, start+end);
	}
	
	 void printUniqueSubstring(){
		Iterator<String> iterator=hm.keySet().iterator();
		while(iterator.hasNext()){
			String key=iterator.next().toString();
			System.out.println(key);
		}
		
	}
	
public static void main(String args[]){
	String str="abababa";
	int n=str.length();
	PalinndromeDp pal= new PalinndromeDp(str,n);
	pal.searchPalindrome();
	pal.printUniqueSubstring();
	
}
	
	
}
