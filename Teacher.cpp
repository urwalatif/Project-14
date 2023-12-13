#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



Teacher::Teacher() {
	firstName = lastName = DepartmentName = regDate = ".";
	Username = Password = confirmPassword = ".";
	gender = '.';
	Qualification = Address = ".";
	tID = contactNo = ".";

}

bool Teacher::Login() {

	string id, pass;
	string I_D = "Hina Iqbal";
	string pa_ss = "oop123";

	//ifstream infile;
	//infile.open("Teacher.txt", ios::in);
	while (1) {
		system("cls");
		cout << " --------------------------------------- " << endl;
		cout << "             Register Course             " << endl;
		cout << " --------------------------------------- " << endl << endl;
		cout << "    ID (Hina Iqbal)          :"; cin >> id;
		cout << "    PASSWORD (oop123)        :"; cin >> pass;
		cout << " --------------------------------------- " << endl;

		//infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;

		if (id != I_D || pass != pa_ss) {
			cout << endl << "Try Again!" << endl;
			return 0;
			system("pause");
		}
		else {
			cout << endl << "Login Success!" << endl;
			system("pause");
			return 1;
			break;
		}
	}
}

int Teacher::Menu() {

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "                 MENU               " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " View Registered Courses                  (1)" << endl;
	cout << " Register Neew Course                     (2)" << endl;
	cout << " Exit                                     (3)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 4)) {
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

//Save data to file.
void::Teacher::saveData() {

	ofstream outfile;

	outfile.open("Teacher.txt", ios::app);
	outfile << firstName << "    " << lastName << "    " << tID << "    " << DepartmentName << "    " << regDate << "    " << Username << "    "
		<< Password << "    " << gender << "    " << Qualification << "    " << contactNo << "    " << Address << endl;

	outfile.close();
	cout << "Data Recorded! " << endl << endl;

	system("pause");

}

//Print All Teachers.
void Teacher::viewAllTeachers() {

	system("cls");

	ifstream infile;
	infile.open("Teacher.txt", ios::in);


	cout << "__________________________________Teachers___________________________________" << endl;
	cout << " ___________________________________________________________________________ " << endl;
	cout << "|   FirstName  LastName   Gender   Qualification   Contact         Username |" << endl;
	cout << "| _________________________________________________________________________ |" << endl;

	while (1) {
		infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
		if (!infile.eof()) {
			cout << "| " << setw(10) << firstName << setw(10) << lastName << setw(5) << gender << setw(15) << Qualification << setw(20) << contactNo << setw(13) << Username << " |" << endl;
		}
		else { break; }
	}

	cout << " ___________________________________________________________________________ " << endl;
	system("pause");
	infile.close();
}

//Edit specific Teacher details.
void Teacher::editTeacher() {

	system("cls");
	DisplayTeacherID();

	string checkID;
	cout << "Enter Teacher ID to Edit: ";
	cin >> checkID;
	system("pause");
	system("cls");

	ifstream infile;
	infile.open("Teacher.txt", ios::in);

	ofstream outfile;
	outfile.open("NewTeacher.txt", ios::app);

	if (!infile) { cout << "File does not exist! "; }
	else {
		infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;

		while (!infile.eof()) {

			if (checkID == tID) { //If ID match then edit and save data.
				cout << " ------------------------------------------------- " << endl;
				cout << "                   Enter New Data                  " << endl;
				cout << " ------------------------------------------------- " << endl;
				cout << "Enter Address                : "; cin >> Address;
				cout << "Enter Contact No.            : "; cin >> contactNo;
				cout << "Enter Qualification          : "; cin >> Qualification;
				cout << " ------------------------------------------------ " << endl;

				outfile << firstName << "    " << lastName << "    " << tID << "    " << DepartmentName << "    " << regDate << "    " << Username << "    "
					<< Password << "    " << gender << "    " << Qualification << "    " << contactNo << "    " << Address << endl;
			}
			else { //If ID not match then save data as it is.
				outfile << firstName << "    " << lastName << "    " << tID << "    " << DepartmentName << "    " << regDate << "    " << Username << "    "
					<< Password << "    " << gender << "    " << Qualification << "    " << contactNo << "    " << Address << endl;
			}
			//getting data for next teacher.
			infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
		}
	}

	infile.close();
	outfile.close();

	remove("Teacher.txt");
	rename("NewTeacher.txt", "Teacher.txt");


}

//Display Teacher IDs for editTeacher function.
void Teacher::DisplayTeacherID() {

	ifstream infile;
	infile.open("Teacher.txt", ios::in);

	cout << "Teacher IDs: " << endl;
	while (1) {
		infile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
		if (!infile.eof()) {
			cout << tID << endl;
		}
		else { break; }
	}
	infile.close();
}

//count number of lines in file and hence number of Teachers.
void Teacher::countLines() {

	ifstream countfile;
	count = -1;
	countfile.open("Teacher.txt", ios::in);

	while (!countfile.eof()) {

		countfile >> firstName >> lastName >> tID >> DepartmentName >> regDate >> Username >> Password >> gender >> Qualification >> contactNo >> Address;
		count++;
	}
	countfile.close();
}

void Teacher::MarkAttendance() {

	system("cls");

	string id;
	int choice;

	ifstream infile;
	infile.open("Attendance.txt", ios::in);

	ofstream outfile;
	outfile.open("temp.txt", ios::app);

	cout << "--------Attendance--------" << endl;
	cout << " Enter Student ID       : "; cin >> id;

	infile >> stuID >> P >> A;

	while (!infile.eof()) {

		if (stuID == id) {

			cout << " --------------------- " << endl;
			cout << "Press (1) for Present  " << endl;
			cout << "Press (2) for Absent   " << endl;
			cout << "Enter Choice         : "; cin >> choice;
			cout << " --------------------- " << endl;
			if (choice == 1) {
				P++;
				cout << "Present Recorded! " << endl;
			}
			else if (choice == 2) {
				A++;
				cout << "Absent Recorded! " << endl;
			}
			system("pause");

			outfile << stuID << "    " << P << "    " << A << endl;
		}

		else {
			outfile << stuID << "    " << P << "    " << A << endl;
		}

		infile >> stuID >> P >> A;
	}

	infile.close();
	outfile.close();

	remove("Attendance.txt");
	rename("temp.txt", "Attendance.txt");

}

void Teacher::AssignMarks() {

	string id, cName;

	ifstream infile;
	infile.open("Marks.txt", ios::in);

	ofstream outfile;
	outfile.open("temp.txt", ios::app);

	system("cls");
	cout << "----------Assigning Marks and Grades----------" << endl;
	cout << "  ------------------------------------------  " << endl;
	cout << "Enter Student ID                       : "; cin >> id;
	infile >> stuID >> courseName >> marks >> grade;

	//if previous data is found.
	while (!infile.eof()) {

		if (stuID == id) {

			cout << "Enter Course Name                      : "; cin >> cName;
			cout << " --------------------- " << endl;

			if (courseName == cName) {
				cout << "Enter Marks          : "; cin >> marks;
				cout << " --------------------- " << endl;
				cout << "Marks Recorded! " << endl;
				AssignGrade();
				system("pause");
				outfile << stuID << "    " << courseName << "    " << marks << "    " << grade << endl;
			}
			else if (courseName != cName) { break; }
		}

		else {
			AssignGrade();
			outfile << stuID << "    " << courseName << "    " << marks << "    " << grade << endl;
		}

		infile >> stuID >> courseName >> marks >> grade;
	}

	//IF previous data is not found.
	if (stuID == id && courseName != cName) {

		cout << "Enter Marks          : "; cin >> marks;
		cout << " --------------------- " << endl;
		cout << "Marks Recorded! " << endl;
		AssignGrade();
		outfile << stuID << "    " << cName << "    " << marks << "    " << grade << endl;
		system("pause");
	}

	if (stuID != id) {
		cout << endl << "------ Invalid Student ID! ------" << endl;
		system("pause");
	}


	infile.close();
	outfile.close();

	remove("Marks.txt");
	rename("temp.txt", "Marks.txt");

}

void Teacher::AssignGrade() {

	if (marks >= 80) { grade = 'A'; }
	else if (marks >= 70) { grade = 'B'; }
	else if (marks >= 60) { grade = 'C'; }
	else if (marks >= 50) { grade = 'D'; }
	else { grade = 'F'; }
}

string Teacher::viewTimeTable() {

	if (loggedIn == "umar123") {
		return "TT1.jpg";
	}
	else if (loggedIn == "ahmad123") {
		return "TT2.jpg";
	}
	else if (loggedIn == "affan123") {
		return "TT4.jpg";
	}
	else if (loggedIn == "danish123") {
		return "TT4.jpg";
	}
	else if (loggedIn == "saba123") {
		return "TT5.jpg";
	}
}

Teacher::~Teacher() { }
