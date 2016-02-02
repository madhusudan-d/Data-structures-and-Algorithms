import java.util.*;

public class EmployeUtil {
	
	//private static final int NaryTree = 0;
	//private static final int Integer = 0;
	HashMap<Integer,NaryTree> hm=new HashMap<Integer,NaryTree>();
	
	public void addEmployee(Employee emp,Employee manager){
		
		
		manager.reportee.add(emp);
		emp.setEmployee();
		NaryTree root=hm.get(manager.id);
		
		NaryTree employee= new NaryTree(emp,root);
		hm.put(emp.id, employee);
		root.subordinate.put(emp.id,employee );
	}
	
	public void addManager(Employee emp,Employee manager){
		
		
		manager.reportee.add(emp);
		NaryTree root=hm.get(manager.id);
		emp.setManager();
		
		NaryTree man=new NaryTree(emp,root);
		hm.put(emp.id,man);
		root.subordinate.put(emp.id,man );
	}
	
	public void addCeo(Employee emp){
		NaryTree node= new NaryTree(emp,null);
		hm.put(emp.id, node);
		emp.setCeo();
	}
	
	
	public void printUpHierarchy(int empId){
		if(hm.containsKey(empId)){
			NaryTree node=hm.get(empId);
			printHierarchy(node);
			
		}
		else{
			System.out.println("Inavalid employee Id");
		}
		
	}
	
	public void printHierarchy(NaryTree node){
		if(node==null)
			return;
		System.out.println(node.emp);
		printHierarchy(node.manager);
		
	}
	
	public void printAll(int ceoId){
		NaryTree node=hm.get(ceoId);
		printTopToBottom(node);	
		
	}
	
	public void printTopToBottom(NaryTree node){
		if(node==null || node.subordinate.isEmpty()){
			System.out.println();
			return ;
			
		}
			
		//Iterator it=node.subordinate.entrySet().iterator();
		System.out.println(node+":");
		HashMap<Integer,NaryTree> hm= (HashMap<java.lang.Integer, NaryTree>) node.subordinate;
		for(NaryTree k :hm.values()){
			System.out.print("  "+k);
		}
		System.out.println();
		for(NaryTree k :hm.values()){
			//System.out.print("  {");
			printTopToBottom(k);
			//System.out.print("}");
		}
		
	}
	
	public void printSalaries(Employee emp){
		System.out.print(emp+"");
		//for(Employee e:emp.reportee.)
		sortSalaries(emp);
		System.out.println(emp.reportee);
	}
	
	
	
	public void sortSalaries(Employee emp){
		
		// arr=emp.reportee;
		Collections.sort(emp.reportee);
		
	}
	
	
	

}
