#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<conio.h>
using namespace std;
void data (string vehicle,int money);
void read();
void readwrite();
main()
{
	pass:
	system("cls");
	char c=' ';
	string pass="";
	cout<<"\n\t\t\tEnter Password: ";
	while (c!=13)
	{
		c=getch();
		if (c!=13)
		{
			pass+=c;
			cout<<"*";
		}
	}
if (pass=="iba")
cout<<"Password accepted.";
else
{
cout<<"\n\n\t\t\tWrong Password..!"<<endl;
cout<<"\n\t\t\tPress any key to continue ..!";
getch();
goto pass;
}
{
int money=0;
ifstream fin;
fin.open("earnings.txt");
fin>>money;

	begin:
	system("cls");
	string name,regNum,reset,reset1,old;
	int rikshaw=50,car=100,bus=200,bike=30;
	char op;

	


	cout<<"\n\n	~~~~~~~~~~Welcome to Vehicle Parking program~~~~~~~~~~\n\n";
	
	cout<<"1. Rikshaw\n\n";
	cout<<"2. Car\n\n";
	cout<<"3. Bus\n\n";
	cout<<"4. Bike\n\n";
	cout<<"5. Check all details \n\n";
	cout<<"6. Deport\n\n";
	cout<<"7. Remove All records\n\n";
	cout<<"8. Earnings\n\n";
	cout<<"0. close this program\n\n";
	cout<<"Please select between (0-9) ";
	cin>>op;

	switch (op)
	{
	case '1':
		
		money+=rikshaw;
		data ("Rikshaw",rikshaw);
	
	break;
	case '2':
	
		money+=car;
		data ("Car",car);
	
	break;
	case '3':
	
		money+=bus;
		data ("BUS",bus);
	
	break;
	case '4':
	
		money+=bike;
		data ("Bike",bike);
	break;
	case '5':
	read();
	break;
	case '6':
		readwrite();
		
	break;
	case '7':
		remove("Parked.txt");
		remove("temp.txt");
		money=0;
		cout<<"\n\nMemory has been cleared...!"<<endl;
		cout<<"Press any key to continue...!";
		getch();
		break;
		case '8':
			{
	ofstream fout;
	fout.open("earnings.txt");
	fout<<money;
	fout.close();
			}
			cout<<"\n\nYOUR TOTAL EARNINGS ARE= "<<money<<endl;
			cout<<"\n\nPress any key to continue... !";
			getch();
		break;
		
	case '0':
	goto end;
	break;
	default:
cout<<"INVALID INPUT..! ";
getch();
break;
}
goto begin;
end:
	{
	ofstream fout;
	fout.open("earnings.txt");
	fout<<money;
	fout.close();
		system("cls");
		cout<<"\n\n\n\t\t\tTHANKS FOR USING OUR PROGRAM";
		cout<<"\n\t\t\tProgram by Bilal khan sec(A)";
		getch();

	}
}



}
void data (string vehicle,int money)
{

string name="",num="",regNum;

ofstream parked("Parked.txt",ios::app);
	cout<<"\n\nEnter "<<vehicle<<" Driver Name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"\n\nEnter "<<vehicle<<" Reg.Number ";
	cin>>num;
		ifstream objread("Parked.txt");
	int count=0;
	
	while(getline(objread,regNum))
	{		
	count++;
}

	parked<<count<<" ."<<num<<"               "<<name<<"               "<<vehicle<<"               "<<money<<endl;
	parked.close();
	cout<<"Your Fee: "<<money<<endl;
	cout<<"================================="<<endl;
	cout<<"	 PARKED"<<endl;
	cout<<"================================="<<endl;
	cout<<"Press any key to continue....!"<<endl;
	getch();
}


void read()
{
	system("cls");
	cout<<"===============================================================================\n";
	cout<<"Sr|Reg no.|	     Name|	    Type of Vehicle|	Fee|\n";
	cout<<"===============================================================================\n";
	string regNum="";
	ifstream objread("Parked.txt");
	int count=0,sn;
	
	while(objread>>sn)
	{
	getline(objread,regNum);		
	cout<<sn<<regNum<<endl;
	count++;
}
	cout<<"_______________________________________________________________________________\n"<<endl<<endl;
	cout<<"TOTAL PARKED VEHICLES= "<<count<<endl<<endl;
	getch();	
}

void readwrite()
{
	string regNum="";
	int search,sn=0;
	read();
	cout<<"\n\nEnter serial No. eg(0,1,2,3...): ";
	cin>>search;
	ofstream objWrite;
	objWrite.open("temp.txt");
	ifstream ObjRead;
	ObjRead.open("Parked.txt");
	
	
	while(ObjRead>>sn)
	{	getline(ObjRead,regNum);
		objWrite<<sn;
		objWrite<<regNum<<endl;
	}
	ObjRead.close();
	objWrite.close();
	ObjRead.open("temp.txt");
	objWrite.open("Parked.txt");
	while(ObjRead>>sn)
	{
	getline(ObjRead,regNum);
	if (search==sn)
	{
		continue;
	}
	else
	{
		objWrite<<sn<<regNum<<endl;
	}
	
}
}


