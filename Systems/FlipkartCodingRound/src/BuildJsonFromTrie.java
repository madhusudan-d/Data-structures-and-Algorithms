import java.util.*;
public class BuildJsonFromTrie {
	
	public void buildJson(Trie root){
		if(root.isLeaf){
			
			printValues(root);
			System.out.println();
			return;
		}
		
		System.out.println(" {");
		
		for(int i=0;i<26;i++){
			if(root.child[i]!=null){
				System.out.print(" \""+root.child[i] + "\" :");
				buildJson(root.child[i]);
			}
		}
		//System.out.print(",");
		
		System.out.println(" }");
		
	}
	
	public void printValues(Trie root){
		ArrayList<Character> arr=root.array;
		if(arr.size()>1)
			System.out.print("[");
		for(int i=0;i<arr.size();i++){
			System.out.print(arr.get(i));
			if(i==arr.size()-1){
				
			}
			else{
				System.out.print(",");
			}		
		}
		if(arr.size()==1)
			System.out.print(",");
		if(arr.size()>1)
			System.out.print("],");
		
	}

}

