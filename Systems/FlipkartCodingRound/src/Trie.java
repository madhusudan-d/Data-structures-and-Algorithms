import java.util.*;

public class Trie {
	
	char value;
	
	ArrayList<Character> array= new ArrayList<Character>();
	
	boolean isLeaf;
	
	public Trie(char value){
		isLeaf=false;
		this.value=value;
	}
	public Trie(){
	}
	
	
	Trie [] child=new Trie[26];
	
	public String toString(){
		return String.valueOf(value);
	}
	
	
	
}
