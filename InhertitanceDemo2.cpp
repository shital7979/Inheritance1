 #include<iostream>
using namespace std;  
class Employee{
private:int empid;//auto increment
         string name;//visible only in class
protected: double salary;//visible only in child class
    //public:visible everywhere
public:Employee(){
}
     Employee(int empid,string name,double salary){
	cout<<"emplyee parameter constr "<<endl;
	  this->empid=empid;
	  this->name=name;
	  this->salary=salary;
       }
	   		 	
	  virtual void calSalary()
	   {                                                            
	   	cout<<"Employee Salary "<<salary<<endl;
	   }
	  void displayDetails()
	  {
	  	cout<<empid<<"  "<<name<<"   "<<salary<<endl;
	  }
	
	
};
class Manager:public Employee {
	private: string deptName;
	         double incentives;
	public :Manager(int empid,string name,double salary ,string deptName):Employee(empid,name,salary)
	{
		this->incentives=15000;
		this->deptName=deptName;
	}  
     
     //child class hides method of parent class
     //calSalary()
     //overriding:same funName with same signature
     void calSalary()
     {
	cout<<"Manager Salary:"<<this->salary+incentives<<endl;
     }

};
class Admin:public Employee{


public :void calSalary()
{
	cout<<"Admin Salary :"<<this->salary+5000<<endl;
	}	
};
int main()
{
	Employee emp;
	emp.calSalary();	
	
 	Manager mgr(1001,"Rakesh",88000,"IT");
	mgr.displayDetails();
    mgr.calSalary();// mgr class method
	            
	cout<<"\n\n";
	Admin ad;
	ad.calSalary();//employee
	cout<<"----------generic pointer-----"<<endl;
	Employee *basePtr=new Manager(300,"Abc",70000,"Account");
	basePtr->calSalary();
//	basePtr->calSalary();;//employee
	
	
	
//	Employee iacsd[3];
//	
//	iacsd[0]=emp;
//	iacsd[1]=mgr;
//	iacsd[2]=ad;
//	
//	cout<<"----salary of all emp-----"<<endl;
//	for(int i=0;i<3;i++){
//		iacsd[i].calSalary();
//	}
	
	
	
	
	
	
	
	
}







