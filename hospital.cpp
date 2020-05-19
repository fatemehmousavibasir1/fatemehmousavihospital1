// hospital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<vector>
#include<map>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
multimap <int, string> savedpatient;
class Person {
protected:
	string name;
	string family;
	int age;
	int idnumber;
	long phone;
	string address;
public:
	Person() {}
	Person(string name, string family, string address, long phone, int age, int idnumber) {

		this->name = name;
		this->family = family;
		this->address = address;
		this->phone = phone;
		this->age = age;
		this->idnumber = idnumber;
	}
	void setName(string name) {
		this->name = name;
	}
	void setFamily(string family) {
		this->family = family;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setPhone(long phone) {
		this->phone = phone;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setIdnumber(int idnumber) {
		this->idnumber = idnumber;
	}
	string getName() const {
		return name;
	}
	string getFamily()const {
		return family;
	}
	string getAddress()const {
		return address;
	}
	long getPhone()const {
		return phone;
	}
	int getAge()const {
		return age;
	}
	int getidnumber()const {
		return idnumber;
	}
	void report() const {

		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(10) << idnumber << endl;

	}
};
class Patient :public Person {
private:
	string type;

public:
	Patient() {}
	Patient(string name, string family, string address, long phone, int age, string type, int idnumber) :Person(name, family, address, phone, age, idnumber) {

		this->type = type;
	}
	void settype(string type) {

		this->type = type;

	}
	string gettype()const {
		return type;
	}
	void report() const {
		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << setw(10) << idnumber << type << endl;
	}
	void registerCourse();

};

class Docter :public Person {
private:
	string specialist;
	vector<Docter> registerdata;
public:
	Docter() {}
	Docter(string name, string family, string address, long phone, int age, int idnumber, string specialist) :Person(name, family, address, phone, age, idnumber) {
		this->specialist = specialist;
	}
	void setspecialist(string specialist) {
		this->specialist = specialist;
	}
	string getspecialist()const {
		return specialist;
	}
	void report() const {
		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << idnumber << setw(4) << specialist << endl;
	}
};
//###########################
vector <Patient> listp, listp2;
fstream patient1;
void writep() {

	int idnumber, age;
	string name, family, address, type;
	long phone;
	cout << "\n Enter the number of patient: ";
	cin >> idnumber;
	cout << "\n Enter the name of patient: ";
	cin >> name;
	cout << "\n Enter the family of patient: ";
	cin >> family;
	cout << "\n Enter the address of patient: ";
	cin >> address;
	cout << "\n Enter the phone of patient: ";
	cin >> phone;
	cout << "\n Enter the type of patient: ";
	cin >> type;
	cout << "\n Enter the age of student: ";
	cin >> age;
	listp.push_back(Patient(name, family, address, phone, age, type, idnumber));
	patient1.open("patient.csv", ios::app);
	patient1 << name + "," + family + "," + address + "," + to_string(age) + to_string(phone) + ","
		+ to_string(idnumber) + "," + type << endl;

}
void displayallp() {

	system("cls");
	cout << "\n\n\t\tALL PATIENT RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   type " << endl;
	cout << "==========================================================\n";
	for (int i = 0; i < listp.size(); i++)
	{

		listp[i].report();
	}

}
void displayonep(int idnumber) {

	system("cls");
	cout << "\n\n\t\tALL PATIENT RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   type " << endl;
	cout << "==========================================================\n";

	for (int i = 0; i < listp.size(); i++)
	{
		if (listp[i].getidnumber() == idnumber) {
			listp[i].report();
		}
	}

}
void modify(int idnumber) {
	string name, family, address, type;
	long phone;
	int a, age;
	for (int i = 0; i < listp.size(); i++)
	{
		if (listp[i].getidnumber() == idnumber) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\t4. ADDRESS";
			cout << "\n\n\t5. AGE";
			cout << "\n\n\t6. TYPE";
			cout << "\n\n\n\tEnter Choice ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listp[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listp[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listp[i].setPhone(phone); break;
			case 4: cout << "Enter a address" << endl; cin >> address; listp[i].setAddress(address); break;
			case 5: cout << "Enter a age" << endl; cin >> age; listp[i].setAge(age); break;
			case 6: cout << "Enter a type" << endl; cin >> type; listp[i].settype(type); break;

			}

		}
	}

}
void deleteallpatient() {

	listp.clear();

}
void delete_patient(int idnumber) {


	for (int i = 0; i < listp.size(); i++) {
		if (listp[i].getidnumber() != idnumber) {
			listp2.push_back(listp[i]);


		}
	}

	listp = listp2;
	vector<Patient>().swap(listp2);


}


multimap <int, string> getsavedpatient() {
	return savedpatient;
}
//##########################
vector <Docter> listd, listd2;
fstream docter1;
void writeDA() {

	int idnumber, age;
	string name, family, address, specialist;
	long phone;
	cout << "\n Enter the number of Docter: ";
	cin >> idnumber;
	cout << "\n Enter the name of Docter: ";
	cin >> name;
	cout << "\n Enter the family of Docter: ";
	cin >> family;
	cout << "\n Enter the address of Docter: ";
	cin >> address;
	cout << "\n Enter the phone of Docter: ";
	cin >> phone;
	cout << "\n Enter the spcialist of Docter: ";
	cin >> specialist;
	cout << "\n Enter the age of Docter: ";
	cin >> age;


	listd.push_back(Docter(name, family, address, phone, age, idnumber, specialist));
	docter1.open("docter.csv", ios::app);
	docter1 << name + "," + family + "," + address + "," + to_string(age) + to_string(phone) + ","
		+ to_string(idnumber) + "," + specialist << endl;
}
void displayalld() {

	cout << "\n\n\t\tALL DOCTERS RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber      specialist" << endl;
	cout << "==========================================================\n";
	for (int i = 0; i < listd.size(); i++)
	{

		listd[i].report();
	}

}
void displayoned(int idnumber) {

	system("cls");
	cout << "\n\n\t\tALL DOCTERS RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   specialist" << endl;
	cout << "==========================================================\n";

	for (int i = 0; i < listd.size(); i++)
	{
		if (listd[i].getidnumber() == idnumber) {
			listd[i].report();
		}
	}

}
void modifyd(int idnumber) {
	int  age, a;
	string name, family, address, specialist;
	long phone;
	for (int i = 0; i < listd.size(); i++)
	{
		if (listd[i].getidnumber() == idnumber) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\t4. ADDRESS";
			cout << "\n\n\t5. AGE";
			cout << "\n\n\t6. TYPE";
			cout << "\n\n\n\tEnter Choice ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listd[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listd[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listd[i].setPhone(phone); break;
			case 4: cout << "Enter a address" << endl; cin >> address; listd[i].setAddress(address); break;
			case 5: cout << "Enter a age" << endl; cin >> age; listd[i].setAge(age); break;
			case 6: cout << "Enter a type" << endl; cin >> specialist; listd[i].setspecialist(specialist); break;

			}

		}
	}
}
void deletealld() {

	listd.clear();

}
void delete_docter(int idnumber) {


	for (int i = 0; i < listd.size(); i++) {

		if (listd[i].getidnumber() != idnumber) {

			listd2.push_back(listd[i]);


		}
	}

	listd = listd2;
	vector<Docter>().swap(listd2);
}
vector<Docter> getdataregisterd() {
	return listd;

}
vector<Patient> getdataregisterp() {
	return listp;

}

void Patient::registerCourse() {
	displayalld();
	int code;
	char ch;
	do {
		cout << "Enter the code of docter for register" << endl;
		cin >> code;
		vector<Docter> listdocter = getdataregisterd();
		vector<Patient> listpatient = getdataregisterp();
		for (int i = 0; i < listdocter.size(); i++) {

			if (listdocter[i].getidnumber() == code) {

				string special = listdocter[i].getspecialist();

				for (int j = 0; j < listpatient.size(); j++) {
					if (special == listpatient[j].gettype()) {

						savedpatient.insert(pair<int, string>(code, listpatient[j].getName() + " " + listpatient[j].getFamily()));


						multimap<int, string> list = getsavedpatient();
						for (multimap<int, string> ::iterator it = list.begin(); it != list.end(); it++) {

							if (code == it->first) {
								cout << it->second;
							}
						}
					}
				}
			}

		}






		cout << "Are you continue? (Y|y)" << endl;
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');
}

/*multimap <int, string> getsavedpatient() {
return savedpatient;
}



void printsavedpatient(int code) {

multimap<int, string> list = getsavedpatient();
for (multimap<int, string> ::iterator it = list.begin(); it != list.end(); it++) {
cout << "1";
if (code == it->first) {
cout << it->second;
}
}
}*/
void report_men() {

	int a, e, f, idnumber;
	system("cls");
	cout << "\n\n\n\tREPORT MENU";
	cout << "\n\n\n\t1. REPORTS";
	cout << "\n\n\t2. Back to Main Menu";
	cout << "\n\n\n\tEnter Choice (1/2/3)? ";
	cin >> a;
	switch (a)
	{
	case 1:
	{	system("cls");
	cout << "\n\n\n\tREPORTs MENU";
	cout << "\n\n\t1. Patient Reports";
	cout << "\n\n\t2. Docter Reports";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> e;
	switch (e)
	{
	case 1:
	{
		cout << "\n\n\n\tSELECT";
		cout << "\n\n\t1. All Patient Report";
		cout << "\n\n\t2. Patient Report";
		cout << "\n\n\n\tEnter Choice (1/2)? ";
		cin >> f;
		switch (f)
		{
		case 1:  displayallp(); break;
		case 2: cout << "\n Enter the number of patient: "; cin >> idnumber;
			displayonep(idnumber); break;
		}

		break; }
	case 2:
	{
		cout << "\n\n\n\tSELECT";
		cout << "\n\n\t1. All Docters Report";
		cout << "\n\n\t2. Docters Report";
		cout << "\n\n\n\tEnter Choice (1/2)? ";
		cin >> f;
		switch (f)
		{
		case 1:  displayalld(); break;
		case 2: cout << "\n Enter the number of docter: "; cin >> idnumber;
			displayoned(idnumber); break;
		}

		break; }
	break;

	}
	case 2:break;
	}

	}
}


void entry_men() {
	int a, num;
	char choice;
	Patient q;
	system("cls");
	cout << "\n\n\n\tENTRY MENU";
	cout << "\n\n\t1.ENTRY MENU PATIENT";
	cout << "\n\n\t2.ENTRY MENU DOCTER";
	cout << "\n\n\t3.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-3) ";

	cin >> a;
	switch (a)
	{
	case 1:
	{    system("cls");
	cout << "\n\n\n\tENTRY MENU STUDENT";
	cout << "\n\n\t1.CREATE PATIENT RECORD";
	cout << "\n\n\t2.MODIFY PATIENT RECORD";
	cout << "\n\n\t3.DELETE PATIENT RECORD";
	cout << "\n\n\t4.DELETE PATIENT RECORDS";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a) {
	case 1:
		do {
			writep();
			cout << "\n Patient record has been created";

			system("cls");
			cout << "Do you want to insert new record of patient? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the number of student " << endl;
		cin >> num; modify(num); break;
		break;
	case 3: cout << "\nEnter the number of student " << endl;
		cin >> num; delete_patient(num); break;
		break;
	case 4:  deleteallpatient(); break;
	case 5: break;
	}
	break;
	}
	case 2:
	{   system("cls");
	cout << "\n\n\n\tENTRY MENU DOCTER";
	cout << "\n\n\t1.CREATE DOCTER RECORD";
	cout << "\n\n\t2.MODIFY DOCTER RECORD";
	cout << "\n\n\t3.DELETE DOCTER RECORD";
	cout << "\n\n\t4.DELETE DOCTER RECORDS";
	cout << "\n\n\t5.SHOW PATIENT OF DOCTER";
	cout << "\n\n\t6.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a) {
	case 1:
		do {
			writeDA();
			cout << "\n docter record has been created";

			system("cls");
			cout << "Do you want to insert new record of doctor? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the number of doctor " << endl;
		cin >> num; modifyd(num); break;
		break;
	case 3: cout << "\nEnter the number of doctor " << endl;
		cin >> num; delete_docter(num); break;
		break;
	case 4:  deletealld(); break;
	case 5: cout << "\nEnter the number of doctor " << endl;
		cin >> num; q.registerCourse(); break;
	case 6: break;
	}
	break;
	}



	case 3:break;

	}
}
int main()
{
	int a;
	do {
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. REPORT MENU";
		cout << "\n\n\t02. ENTRY/EDIT MENU";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";

		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:report_men(); break;
		case 2:entry_men();
		case 3:break;
		}
	} while (a != 3);

	_getch();
	return 0;
}

