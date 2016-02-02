
public class TrieUtil {
	
	public void insert(Trie root,String str){
		
		for(int i=0;i<str.length();i++){
			
			if(str.charAt(i)=='>'){
				if(!isValid(root,str))
					return;
				
			}
			else if(str.charAt(i)=='='){
				
				
					i=i+1;
					addValueToNode(root,str.charAt(i));
				
			}
			else{
				if(root.child[indexOf(str.charAt(i))]!=null){
					root=root.child[indexOf(str.charAt(i))];
				}
				else{
					root.child[indexOf(str.charAt(i))]=new Trie(str.charAt(i));
					root=root.child[indexOf(str.charAt(i))];
				}
			}
			
		}
		setLeaf(root,true);
	}
	
	public void addValueToNode(Trie root,char c){
		root.array.add(c);
	}
	
	public boolean isValid(Trie root,String str){
		if(root.array.size()!=0){
			System.out.println("Failure: "+str);
			return false;
		}
		return true;
		
	}
	
	public void display(Trie root){
		if(isLeaf(root)){
			System.out.println();
			return;
		}
		else{
			for(int i=0;i<26;i++){
				if(root.child[i]!=null){
					System.out.print(root.child[i]);
					display(root.child[i]);
				}
			}
		}	
	}
	
	
	public int indexOf(char a){
		return a-'a';
	}
	
	public boolean isLeaf(Trie t){
			return t.isLeaf;
	}
	
	public void setLeaf(Trie t,boolean value){
		t.isLeaf=value;
	}
}
