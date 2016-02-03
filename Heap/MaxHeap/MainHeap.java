
public class MainHeap {
	
	public static void main(String []args){
		MaxHeap h=new MaxHeap(10);
		h.addtoHeap(5);
		h.addtoHeap(90);
		h.addtoHeap(20);
		h.addtoHeap(30);
		h.addtoHeap(3);
		h.printHeap(0);
		System.out.println("size :"+h.size);
		System.out.println(h.removeMax()+"size :"+h.size);
		h.printHeap(0);
		System.out.println(h.removeMax()+"size :"+h.size);
		
		System.out.println(h.removeMax());
		h.printHeap(0);
	}

}
