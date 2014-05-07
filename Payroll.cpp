//Phuntsok Norbu


#include<iostream> 
#include<string>
#include<iomanip>
#include<fstream>


using namespace std;

class Employee 
{
public:
	Employee();
	void input();
	void calculate();
	void display();
	void input_storage(Employee []);
	void sort(Employee[], int);
	void swap(Employee &, Employee &);
	void set_name(string);
	string get_name(Employee[], int);
	void set_hours(double);
	double get_hours(Employee[], int);
	void set_rate(double);
	double get_rate(Employee[], int);	
	double get_ovrhours(Employee[], int);	
	double get_sal(Employee[], int);	
	double get_ovrsal(Employee[], int);
	
private:
	string name;	
	int count;
	double hours, rate, ovrhours, sal, ovrsal;
	
};

Employee::Employee()
{
	count=0;
}
	
void Employee::set_name(string new_name)
{
	name=new_name;
}
 
void Employee::set_hours(double new_hours)
{
	hours=new_hours;
}
 
void Employee::set_rate(double new_rate)
{
	rate=new_rate;
}
 

 
void Employee::input()  
	{			
		cout << "\nEnter name: ";
		cin >> name;
		cout <<"\n Enter  hours: ";
		cin>> hours;
		cout << "\n Enter rate: ";
		cin>> rate;
		cout << endl;
		
	}

void Employee::calculate()  
	{
		ovrhours=hours-40;
			
		if (ovrhours>=10)
			{
				ovrsal=(10*(1.5*rate))+((hours-50)*(2*rate));
				sal=(40*rate)+ovrsal;
			}

			else if (ovrhours>0 && ovrhours<10)
			{
				ovrsal=ovrhours*(rate*1.5);
				sal=(40*rate)+ovrsal;
			}

			else
			{
				ovrhours=0.0;
				ovrsal=0.0;
				sal=hours*rate;
			}
	}

void Employee::input_storage(Employee storage[])
{
	storage[count].name=name;
	storage[count].rate=rate;
	storage[count].hours=hours;
	storage[count].ovrhours=ovrhours;
	storage[count].ovrsal=ovrsal;
	storage[count].sal=sal;
	count++;
}

void Employee::sort(Employee storage[], int n) 
	{
		
		for (int i=n-1; i>0; i--)
			for (int j=0; j<i; j++)
				if (storage[j].name > storage[j+1].name) swap(storage[j],storage[j+1]);
	}

void Employee::swap(Employee &a, Employee &b)
{
	Employee temp = a;
	a = b;
	b = temp;
}

	

void Employee::display() 
	{	
		cout << "Report is created in your respective workspace." << endl;
	
	}

string Employee::get_name(Employee storage[], int x)
 {
	 return storage[x].name;
 }

double Employee::get_rate(Employee storage[], int x)
 {
	 return storage[x].rate;
 }

 double Employee::get_ovrhours(Employee storage[], int x)
 {
	 return storage[x].ovrhours;
 }

  double Employee::get_hours(Employee storage[], int x)
 {
	 return storage[x].hours;
 }
	double Employee::get_sal(Employee storage[], int x)
 {
	 return storage[x].sal;
 }
	double Employee::get_ovrsal(Employee storage[], int x)
 {
	 return storage[x].ovrsal;
 }


	class PayrollReport
{
public:
	PayrollReport();
	void insertDetail(Employee[], int);
	void border(int);
	void display_total(Employee[]);
	void columnheadings();
	void indent(int);
	void reportheader();
	void skiplines(int);
	
private:
	double tot_hours, tot_ovrhours, tot_ovrsal, tot_sal;
	ofstream outreport;
};


PayrollReport::PayrollReport()
{
	outreport.open("report.txt", ios::out);
	tot_hours=0.0;
	tot_ovrhours=0.0;
	tot_ovrsal=0.0;
	tot_sal=0.0;
	
}	

void PayrollReport::indent(int n)
{
	for (int i=0; i<n; i++)
		outreport << " ";
}
void PayrollReport::skiplines (int n)
{
for (int i=1; i<=n; i++)
outreport << endl;
}

void PayrollReport::reportheader()
{
	border(100);
	skiplines(1);
	indent(37);
	outreport << "EMPLOYEE PAYROLL REPORT"<<endl;
	border(100);
}


void PayrollReport::columnheadings()
{
outreport << endl<<setiosflags(ios::right)
<< setw (15) << ' ' << setw (20) << "Hourly"
<< setw(10) << "Overtime"
<< setw(10) << "Overtime" << setw(10) <<"Total" << endl
<< setiosflags(ios::left) << setw (15) << "Name"
<< setiosflags(ios::right)
<< setw (10) << "Hours" << setw(10) << "Rate" << setw(10) << "Hours"
<< setw(10) << "Salary" << setw(10) <<"Salary" << endl;
border(100);
skiplines(1);
}


void PayrollReport::insertDetail(Employee storage[], int n)
{
	int i=0;
	while (i <n)
	{
	outreport << setiosflags(ios::right)<<setprecision(2) << std::fixed <<setw(15)<< storage[i].get_name(storage, i) << ' ' << 
				setw(10)<<storage[i].get_hours(storage,i)<< setw(10) << storage[i].get_rate(storage,i) << setw(10)<< storage[i].get_ovrhours(storage,i) << setw(10)
				<< storage[i].get_ovrsal(storage, i) << setw(10) << storage[i].get_sal(storage, i) << endl;
	
	
	

	tot_hours+=storage[i].get_hours(storage, i);
	tot_sal+=storage[i].get_sal(storage, i);
	tot_ovrhours+=storage[i].get_ovrhours(storage, i);
	tot_ovrsal+=storage[i].get_ovrsal(storage, i);

	i++;
	}
	
}

void PayrollReport::display_total(Employee[])
{
	border(100);
	skiplines(1);
	outreport << setiosflags(ios::showpoint | ios::fixed | ios::right)
	<< setw(15)<<"Totals"<<setw(11) << tot_hours
	<< setw(20) << tot_ovrhours
	<< setw(10) << tot_ovrsal
	<< setw(10) << tot_sal << endl;

	skiplines(4);
	border(100);
	skiplines(1);
	border(100);
	
}

void PayrollReport::border(int n)
{
	for (int i=0; i<n; i++)
		outreport << "-";
}



int main()
{
	
	int counter =0;
	Employee x;
	Employee storage[15];
	PayrollReport p;

	p.reportheader();
	p.columnheadings();
	
	string type;
	cout << "Start or End"<<endl;
	cin >> type;

	while(type!="end")
	{

		x.input();
		x.calculate();
		x.input_storage(storage);
		counter ++;
		cout << "Continue or End: ";
		cin >> type;
		cout << endl;
	} 

	x.sort(storage, counter);

	p.insertDetail(storage, counter);	
	

	p.display_total(storage);
	x.display();

	cin.ignore();
	return 0;
	
}

