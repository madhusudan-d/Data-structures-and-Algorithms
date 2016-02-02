
public class Main {
	
	
	public void testcase1(TrieUtil util,BuildJsonFromTrie build){

		Trie root=new Trie();
		util.insert(root, "a>b=1");
		util.insert(root, "a>b=2");
		util.insert(root, "a>c>d>e>f=3");
		util.insert(root, "a>c>e=4");
		util.insert(root,"x=1");
		
		
		build.buildJson(root);

	}
	
	public void testcase2(TrieUtil util,BuildJsonFromTrie build){
		Trie root=new Trie();
		util.insert(root, "a>b=1");
		util.insert(root, "a>b=2");
		util.insert(root, "a>c>d=3");
		util.insert(root, "a>c>e=4");
		
		
		build.buildJson(root);
		
	}
	
	public void testcase3(TrieUtil util,BuildJsonFromTrie build){
		Trie root=new Trie();
		util.insert(root, "a>b=1");
		util.insert(root, "a>b=2");
		util.insert(root, "a>c>d=3");
		util.insert(root, "a>c>e=4");
		
		util.insert(root, "a>b>d");
		
		build.buildJson(root);
		
	}
	public void testcase4(TrieUtil util,BuildJsonFromTrie build){
		//String str="a>b=c";
		
		Trie root=new Trie();
		util.insert(root, "a>b=1");
		util.insert(root, "a>b=2");
		util.insert(root, "a>c>d=3");
		util.insert(root, "a>c>e=4");
		
		util.insert(root, "a>b>d");
		
		build.buildJson(root);
		
	}
	
	public static void main(String [] args){
		
		
		TrieUtil  util= new TrieUtil();
		BuildJsonFromTrie build= new BuildJsonFromTrie();
		
		Main test= new Main();
		
		System.out.println("########################");
		test.testcase1(util,build);
		System.out.println("########################");
		test.testcase2(util,build);
		System.out.println("########################");
		test.testcase3(util, build);
		System.out.println("########################");
		test.testcase4(util, build);
		System.out.println("########################");
		
		
		
		
		
		
		
	}

}

