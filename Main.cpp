#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"
#include "sfml.h"


//input operator for student.
istream& operator >> (istream& in, Student& obj) {

	//count number of lines and hence find latest student id number.
	obj.countLines();

	system("cls");
	cout << " ------------------------------------------------- " << endl;
	cout << "                 ENTER STUDENT DATA                " << endl;
	cout << " ------------------------------------------------- " << endl;
	cout << "Enter First Name              : "; in >> obj.firstName;
	cout << "Enter Second Name             : "; in >> obj.lastName;
	cout << "Enter Registration Date       : "; in >> obj.regDate;
	cout << "Enter Department              : "; in >> obj.DepartmentName;
	cout << "Enter Gender                  : "; in >> obj.gender;
	cout << "Enter Contact No.             : "; in >> obj.contactNo;
	cout << "Fee paid                      : "; in >> obj.feeStatus;
	cout << "Enter Blood Group             : "; in >> obj.BloodGroup;
	cout << "Enter Address                 : "; in >> obj.Address;
	obj.sID = obj.DepartmentName + "-" + to_string(obj.count);
	cout << "---------------------------------------------------" << endl;
	return in;
}

//input operator for Teacher.
//istream& operator >> (istream& in, Teacher& obj) {
//
//	//count number of lines and hence find latest student id number.
//	//obj.countLines();
//
//	system("cls");
//	cout << " ------------------------------------------------- " << endl;
//	cout << "                 ENTER TEACHER DATA                " << endl;
//	cout << " ------------------------------------------------- " << endl;
//	cout << "Enter First Name              : "; in >> obj.firstName;
//	cout << "Enter Second Name             : "; in >> obj.lastName;
//	cout << "Enter Department Name         : "; in >> obj.DepartmentName;
//	cout << "Enter Registration Date       : "; in >> obj.regDate;
//	cout << "Enter Gender                  : "; in >> obj.gender;
//	cout << "Enter Contact No.             : "; in >> obj.contactNo;
//	cout << "Enter Qualification           : "; in >> obj.Qualification;
//	cout << "Enter Address                 : "; in >> obj.Address;
//	cout << "Enter Username                : "; in >> obj.Username;
//	cout << "Enter Password                : "; in >> obj.Password;
//	obj.tID = obj.DepartmentName + "-" + to_string(obj.count);
//	do {
//
//		try {
//
//			cout << "Re-enter Password             : "; in >> obj.confirmPassword;
//
//			if (obj.Password != obj.confirmPassword) { throw(obj.confirmPassword); }
//			else { cout << "Password Match! " << endl; }
//		}
//
//		catch (string pwd) {
//			cout << "Wrong Password:  " << pwd << endl;
//		}
//
//	} while (obj.Password != obj.confirmPassword);
//
//	cout << " ------------------------------------------------- " << endl;
//
//	return in;
//}

int main() {
	//Showing Main Screen.
	displayGraphic("flex.jpg");


	Student stu; Admin adm; Teacher teach;
	int choice = 0, choice2 = 0, ctrl = 1;

	while (ctrl == 1) {
		choice = 0;
		system("cls");
		/*cout << "\t\t\tFlex Management System" << endl;
		cout << "Enter 1 for Admin Module" << endl;
		cout << "Enter 2 for Teacher Module" << endl;
		cout << "Enter 3 for student Module" << endl;
		cout << "Enter 4 to Quit Program" << endl;*/
		cout << "\t\t\tFlex Management System" << endl;
		cout << "Enter 1 to Enroll Student" << endl;
		cout << "Enter 2 for COurse Registration" << endl;
		cout << "Enter 3 for Attendance" << endl;
		cout << "Enter 4 for Marks" << endl;
		cout << "Enter 5 for Course Withdraw" << endl;
		cout << "Enter 6 to Quit Program" << endl;
		cin >> choice;

		switch (choice) {
			//admin.
		case 1:
			//resetting choice2.
			choice2 = 0;

			sfml_text(" -----------------------  \n Enroll A Student \n -----------------------  ");
		//	admin login.
			if (adm.Login() == 1) {

				while (choice2 != 5) {
					//admin menu.
					choice2 = adm.Menu();

					switch (choice2) {

						//new student.
					case 1:
						cin >> stu;
					    stu.saveData();
						break;
						////view studnets.
					case 2:
						stu.viewAllStudents();
						break;
						//edit student.
					case 3:
						stu.editStudent();
						break;
						//add teacher.
					case 0:
						sfml_text(" --------------- \n Exited \n ---------------  ");
						break;

						//admin choice2 switch.
					default:
						break;
					}
				}
			}
			else { playSound(); }
			break;

			//Teacher.
		case 2:
			//resetting choice2.
			choice2 = 0;

			sfml_text(" -----------------------  \n Course Registration \n -----------------------  ");
			//teacher login.
			if (teach.Login() == 1) 
			{
				while (choice2 != 4) {
					//teacher menu.
					choice2 = teach.Menu();

					switch (choice2) {

						//view timetable.
					case 1:
						displayGraphic(teach.viewTimeTable());
						break;
					case 2:
						teach.MarkAttendance();
						break;
					case 3:
						sfml_text(" --------------- \n Exited \n ---------------  ");
						break;

						//teacher choice2 switch.
					default:
						break;
					}
				}
			}
			else { playSound(); }
			break;

			//student.
		case 3:

			//resetting choice2.
			choice2 = 0;

			sfml_text(" ----------------------- \n Attendance \n---------------------- - ");
			//student login.
			if (stu.Login() == 1) {
				while (choice2 != 6) {
					//student menu.
					choice2 = stu.Menu();

					switch (choice2) {

					case 1:
						//attendance.
						stu.viewAttendance();
						break;
					case 2:
						//marks.
						stu.viewMarks();
						break;
					case 3:
						//grades.
						stu.viewGrades();
						break;
					case 4:
						//courses.
						stu.viewCourses();
						break;
					case 5:
						//fee status.
						stu.viewFeeStatus();
						break;
					case 6:
						sfml_text(" ---------------  \n Student Module \n Exited \n ---------------  ");
						break;

						//teacher choice2 switch.
					default:
						break;
					}
				}
			}
			else { playSound(); }
			break;

		case 4:
			sfml_text(" -----------------------  \n Program Exited \n -----------------------  ");
			ctrl = 0;
			break;

			//choice switch.
		default:
			playBKL();
			sfml_text(" -----------------------  \n Invalid Input \n -----------------------  ");
			ctrl = 0;
			break;
		}
	}
	return 0;
}