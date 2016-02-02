
public class Main {
	public static void main(String []args){
		
		Employee a1=new Employee("abc",10,12);
		Employee a2=new Employee("xyz",11,11);
		Employee a3=new Employee("abc2",12,15);
		Employee a4=new Employee("xyz2",13,13);
		Employee b1=new Employee("BX",20,20);
		Employee b2=new Employee("CX",21,21);
		Employee c=new Employee("A",1,100);
		
		EmployeUtil util=new EmployeUtil();
		util.addCeo(c);
		
		util.addManager(b1,c);
		util.addManager(b2,c);
		
		util.addEmployee(a1,b1);
		util.addEmployee(a2,b1);
		
		util.addEmployee(a3,b2);
		util.addEmployee(a4,b2);
		
		//util.printUpHierarchy(1);
		
		
		//util.printSalaries(b1);
		util.printAll(1);
		
			
	}

}
