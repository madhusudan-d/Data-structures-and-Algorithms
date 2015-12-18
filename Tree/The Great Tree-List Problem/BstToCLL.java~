package practice;

public class BstToCLL {
	
	
	public Tree TreeToCll(Tree root){
		
		if(root==null)
			return null;
		
		Tree left=TreeToCll(root.left);
		Tree right=TreeToCll(root.right);
		
		root.left=root;
		root.right=root;
		
		
		left=bind(left,root);
		left=bind(left,right);
		
		printCll(left);
		
		return left;
		
	}
	
	public static Tree bind(Tree a,Tree b){
		if(a==null)
			return b;
		if(b==null)
			return a;
		
		
		Tree alast=a.left;
		Tree blast=b.left;
		
		join(alast,b);
		join(blast,a);
		
		
		return a;
	}
	
	public static void join(Tree a, Tree b){
		a.right=b;
		b.left=a;
	}
	
	public static void printCll(Tree tree){
		
		Tree current=tree;
		while(current !=null){
			System.out.print(current.data+"<->");
			if(current.right==tree)
				break;
			current=current.right;
			
		}
		System.out.println();
	}
	
	public static void main(String []args){
		
		TreeUtil treeUtil=new TreeUtil();
		Tree root=treeUtil.createTree();
		treeUtil.printPreOrder(root);
		System.out.print("\n");
		
		BstToCLL btocll= new BstToCLL();
		
		Tree t1=btocll.TreeToCll(root);
		BstToCLL.printCll(t1);
		
		
	}

}
