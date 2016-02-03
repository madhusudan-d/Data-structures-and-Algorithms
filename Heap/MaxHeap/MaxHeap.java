
public class MaxHeap {
	int size;
	int capacity;
	
	int [] heap;
	
	public MaxHeap(int capacity){
		this.capacity=capacity;
		heap=new int[capacity];
		size=0;
	}
	
	
	public int parent(int i){
		return (i-1)/2;	
	}
	
	public int leftChild(int i){
		return 2*i+1;
	}
	
	public int rightChild(int i){
		return 2*i+2;
	}
	
	public void addtoHeap(int item){
		if(isFull()){
			System.out.println("Heap is full");
			return;
		}
		heap[size++]=item;
		int i=size-1;;
		while(i!=0 && heap[parent(i)]<=heap[i]){
			swap(i,parent(i));
			i=parent(i);
		}
		
	}
	
	public void swap(int i,int j){
		int t=heap[i];
		heap[i]=heap[j];
		heap[j]=t;
	}
	
	public int removeMax(){
		int max=heap[0];
		heap[0]=heap[--size];
		heapify(0);
		return max;
		
	}
	
	public int getMax(){
		return heap[0];
	}
	
	public void heapify(int k){
		int largest=k;
		int i=leftChild(k);
		int j=rightChild(k);
		if( i <size && heap[i]>heap[k])
			largest=i;
		if(j<size && heap[j]>heap[largest])
			largest=j;
		if(largest!=k){
			swap(k,largest);
			heapify(largest);
		}
			
	}
	
	public boolean isFull(){
		if(size==capacity-1)
			return true;
		return false;
	}
	
	public void printHeap(int i){
		for(int j=i;j<size;j++){
			System.out.print(heap[j]+" ");
		}
	}
	

}
