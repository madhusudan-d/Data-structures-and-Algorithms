package practice.hashing;

import java.util.*;

public class EmplUnderEmp {

	Map<String,Integer> result=new HashMap<String,Integer>();
	
	static void printEmplUnderEmpl(HashMap<String,String> data){
		
		Map<String,List<String>> managerEmp=new HashMap<String,List<String>>() ;
		
		for(Map.Entry<String, String> entry:data.entrySet()){
			String emp=entry.getKey();
			String mngr=entry.getValue();
			
			if(!emp.equals(mngr)){
				
				List<String> directReports=managerEmp.get(mngr);
				if(directReports == null){
					directReports= new ArrayList<String>();	
				}
				directReports.add(emp);
				managerEmp.put(mngr, directReports);
				
			}
			
			
		}
		
		printResult(managerEmp);
		
	}
	
	static void printResult(Map<String,List<String>> managerEmp){
		
		for(Map.Entry<String, List<String>> entry:managerEmp.entrySet()){
			String mngr=entry.getKey();
			int count=entry.getValue().size();
			System.out.println("Manager: " + mngr + " reports: "+count);
		}
		
	}
	
	
	
	
	public static void main(String []args){
		
		HashMap<String,String> data=new HashMap<String,String>();
		data.put("A", "C");
		data.put("B", "C");
		data.put("C", "F");
		data.put("D", "E");
		data.put("E", "F");
		data.put("F", "F");
		printEmplUnderEmpl(data);
		
	}

}
