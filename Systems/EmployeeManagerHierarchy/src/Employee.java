import java.util.*;

public class Employee implements Comparable<Employee> {
	
	
	String name;
	int id;
	int salary;
	int rating;
	boolean isManager;
	boolean isEmployee;
	boolean isCeo;
	
	//Employee [] reportee= new Employee[10];
	ArrayList<Employee> reportee= new ArrayList<Employee>();
	
	
	public Employee(String name,int id,int salary){
		this.name=name;
		this.id=id;
		this.salary=salary;
	}
	
	@Override
	
	public int compareTo(Employee e){
		Integer i=new Integer(e.getSalary());
		Integer j=new Integer(this.salary);
		if(i.equals(j)){
			Integer k=new Integer(this.rating);
			Integer l=new Integer(e.rating);
			return k.compareTo(l); 
		}
		return j.compareTo(i);
	}
	
	public int getSalary(){
		return this.salary;
	}
	
	public boolean isManager(){
		return isManager;
	}
	
	public boolean isCeo(){
		return isCeo;
	}
	public boolean isEmployee(){
		return isEmployee;
	}
	
	public void setManager(){
		isManager=true;
	}
	
	public void setCeo(){
		isCeo=true;
	}
	public void setEmployee(){
		isEmployee=true;
	}
	
	
	public String toString(){
		return this.name;
	}
}
