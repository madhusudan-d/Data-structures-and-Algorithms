package practice;

public class TreeUtil {
	
	public Tree createTree(){
		Tree t1=new Tree(1);
		Tree t2=new Tree(2);
		Tree t3=new Tree(3);
		Tree t4=new Tree(4);
		Tree t5=new Tree(5);
		Tree t6=new Tree(6);
		Tree t7=new Tree(7);
		Tree t8=new Tree(8);
		Tree t9=new Tree(9);
		
		t8.left=t4;
		t8.right=t9;
		
		t4.left=t2;
		t4.right=t6;
		
		
		t2.left=t1;
		t2.right=t3;
		
		t6.left=t5;
		t6.right=t7;
		
		return t8;
		
	}
	
	public void printInOrder(Tree tree){
		if(tree==null)
			return;
		printInOrder(tree.left);
		System.out.print(tree.data);
		printInOrder(tree.right);
		
	}
	
	public void printPreOrder(Tree tree){
		if(tree==null)
			return;
		System.out.print(tree.data);
		printPreOrder(tree.left);
		printPreOrder(tree.right);
		
	}
	
	public void printPostOrder(Tree tree){
		if(tree==null)
			return;
		printPostOrder(tree.left);
		printPostOrder(tree.right);
		System.out.print(tree.data);
		
	}

}
