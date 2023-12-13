#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



Student::Student() {
	firstName = lastName = DepartmentName = regDate = ".";
	gender = '.';
	contactNo = ".";
	BloodGroup = Address = ".";
	feeStatus = 0;
	marks = 0;
}

bool Student::Login() {

	string id, pass;
	string I_D = "Hina Iqbal";
	string pa_ss = "oop123";

	//ifstream infile;
	//infile.open("Student.txt", ios::in);
	while (1) {
	system("cls");
	cout << " --------------------------------------- " << endl;
	cout << "                    LOGIN                " << endl;
	cout << " --------------------------------------- " << endl << endl;
	cout << "    ID (Hina Iqbal)          :"; cin >> id;
	cout << "    PASSWORD (oop123)        :"; cin >> pass;
	cout << " --------------------------------------- " << endl;

	//infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

	/*while (!infile.eof()) {

		if (id == sID) {
			loggedIn = id;
			cout << endl << "Login Success!" << endl;
			return 1;
			break;
		}

		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;*/

	};
	if (id != sID) {
		//playSound();
		cout << endl << "No Student Exists!" << endl;
		return 0;
	}

	infile.close();


}

int Student::Menu() {

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "            STUDENT MENU            " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " View Attendance                 (1)" << endl;
	cout << " View Marks                      (2)" << endl;
	cout << " View Grades                     (3)" << endl;
	cout << " View Courses                    (4)" << endl;
	cout << " View Fee Status                 (5)" << endl;
	cout << " Exit                            (6)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 7)) {
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

//save data to file.
void Student::saveData() {

	ofstream outfile, outfile2, outfile3;

	outfile.open("Student.txt", ios::app);
	outfile2.open("Attendance.txt", ios::app);
	outfile3.open("Marks.txt", ios::app);

	outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
		<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;

	//initializing attendance for new student to 0.
	outfile2 << sID << "    " << 0 << "    " << 0 << endl;

	//initializing marks file with atleast 1 course name.
	if (DepartmentName == "CS" || DepartmentName == "SE" || DepartmentName == "EE") {
		outfile3 << sID << "    " << "OOP" << "    " << 0 << endl;
	}
	else if (DepartmentName == "BA") {
		outfile3 << sID << "    " << "Accounting" << "    " << 0 << endl;
	}

	outfile.close();
	outfile2.close();
	cout << "Data Recorded! " << endl << endl;

	system("pause");
}

//display all students.
void Student::viewAllStudents() {

	system("cls");

	ifstream infile;
	infile.open("Student.txt", ios::in);

	cout << "________________________________________Students_______________________________________" << endl;
	cout << " _____________________________________________________________________________________ " << endl;
	cout << "|  ID      FirstName   LastName   Gender   Department     Contact             Address |" << endl;
	cout << "| ___________________________________________________________________________________ |" << endl;

	while (1) {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		if (!infile.eof()) {
			cout << "| " << setw(5) << sID << setw(12) << firstName << setw(10) << lastName << setw(6) << gender << setw(10) << DepartmentName << setw(24) << contactNo << setw(15) << Address << "  |" << endl;
		}
		else { break; }
	}

	cout << " _____________________________________________________________________________________ " << endl;
	system("pause");
	infile.close();
}

//edit specific student.
void Student::editStudent() {

	system("cls");
	DisplayRollNo();

	string checkID;
	cout << "Enter Student ID to Edit: ";
	cin >> checkID;
	system("pause");
	system("cls");

	ifstream infile;
	infile.open("Student.txt", ios::in);

	ofstream outfile;
	outfile.open("NewStudent.txt", ios::app);

	if (!infile) { cout << "File does not exist! "; }
	else {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;

		while (!infile.eof()) {

			if (checkID == sID) { //If ID match then edit and save data.
				cout << " ------------------------------------------------- " << endl;
				cout << "                   Enter New Data                  " << endl;
				cout << " ------------------------------------------------- " << endl;
				cout << "Enter First Name             : "; cin >> firstName;
				cout << "Enter Last Name              : "; cin >> lastName;
				cout << "Enter Fee Status             : "; cin >> feeStatus;
				cout << "Enter Address                : "; cin >> Address;
				cout << "Enter Contact No.            : "; cin >> contactNo;
				cout << " ------------------------------------------------ " << endl;

				outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
					<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;
			}
			else { //If ID not match then save data as it is.
				outfile << firstName << "    " << lastName << "    " << sID << "    " << DepartmentName << "    " << regDate << "    "
					<< gender << "    " << contactNo << "    " << Address << "    " << feeStatus << "    " << BloodGroup << endl;
			}
			//getting data for next teacher.
			infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		}
	}

	infile.close();
	outfile.close();

	remove("Student.txt");
	rename("NewStudent.txt", "Student.txt");
}

//Display roll numbers for edit function.
void Student::DisplayRollNo() {

	ifstream infile;
	infile.open("Student.txt", ios::in);

	cout << "Roll Numbers: " << endl;
	while (!infile.eof()) {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		cout << sID << endl;
	}
	infile.close();
}

////count number of lines in file and hence number of students.
void Student::countLines() {

	ifstream countfile;
	count = -1;
	countfile.open("Student.txt", ios::in);

	while (!countfile.eof()) {

		countfile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		count++;
	}
	countfile.close();
}

void Student::viewMarks() {

	system("cls");

	ifstream infile;
	infile.open("Marks.txt", ios::in);

	cout << "--------Marks--------" << endl;

	while (!infile.eof()) {

		infile >> stuID >> courseName >> marks >> grade;

		if (stuID == loggedIn) {
			cout << "-----------------------" << endl;
			cout << "Course: " << courseName << endl;
			cout << "Marks: " << marks << endl;
			cout << "-----------------------" << endl;
		}

	}

	system("pause");

	infile.close();
}

void Student::viewGrades() {

	system("cls");

	ifstream infile;
	infile.open("Marks.txt", ios::in);

	cout << "--------Grades---------" << endl;

	while (!infile.eof()) {

		infile >> stuID >> courseName >> marks >> grade;

		if (stuID == loggedIn) {
			cout << "-----------------------" << endl;
			cout << "Course: " << courseName << endl;
			cout << "Grdae: " << grade << endl;
			cout << "-----------------------" << endl;
		}

	}
	system("pause");

	infile.close();
}

void Student::viewCourses() {

	system("cls");

	ifstream infile;
	infile.open("Marks.txt", ios::in);

	cout << "---------Courses---------" << endl;

	while (!infile.eof()) {
		infile >> stuID >> courseName >> marks >> grade;
		if (stuID == loggedIn) {
			cout << "-------------------------" << endl;
			cout << courseName << endl;
		}
	}
	cout << "-----------------------" << endl;

	system("pause");

	infile.close();
}

void Student::viewFeeStatus() {

	system("cls");

	ifstream infile;
	infile.open("Student.txt", ios::in);

	while (!infile.eof()) {
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
		if (stuID == loggedIn) {

			cout << "-----------------------" << endl;
			cout << "Fee Status: ";

			if (feeStatus == 1) { cout << "  Paid" << endl; }
			else { cout << "  Un-Paid" << endl; }

		}
		infile >> firstName >> lastName >> sID >> DepartmentName >> regDate >> gender >> contactNo >> Address >> feeStatus >> BloodGroup;
	}
	cout << "-----------------------" << endl;

	system("pause");

	infile.close();
}

void Student::viewAttendance() {

	system("cls");

	ifstream infile;
	infile.open("Attendance.txt", ios::in);

	infile >> stuID >> P >> A;

	while (!infile.eof()) {

		if (stuID == loggedIn) {
			cout << " ------------------------ " << endl;
			cout << "Present Count        : " << P << endl;
			cout << "Absent Count         : " << A << endl;
			cout << " ------------------------ " << endl;
		}

		infile >> stuID >> P >> A;
	}

	system("pause");

	infile.close();
}

Student::~Student() {

}

