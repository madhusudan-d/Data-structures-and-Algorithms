
import java.util.*;

public class NaryTree {
	
	
	NaryTree manager;
	Employee emp;
	
	public NaryTree(Employee emp,NaryTree manager){
		this.emp=emp;
		this.manager=manager;
		
	}
	
	Map<Integer,NaryTree> subordinate=new HashMap<Integer,NaryTree>();
	
	public String toString(){
		return emp.name;
	}
}
