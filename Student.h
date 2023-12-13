#pragma once
#ifndef Student_H
#define Student_H

#include "Admin.h"
#include <string>
using namespace std;

class Student : public Admin {

	string firstName, lastName, DepartmentName, regDate;
	char gender;
	string contactNo, BloodGroup, Address;
	bool feeStatus;
	int marks;
	string sID;
	int count;

	string loggedIn;

public:

	Student();

	friend istream& operator >> (istream& in, Student& obj);

	bool Login();
	int Menu();
	void saveData();
	void viewAllStudents();
	void editStudent();
	void DisplayRollNo();
	void countLines();
	void viewMarks();
	void viewGrades();
	void viewCourses();
	void viewFeeStatus();
	void viewAttendance();

	~Student();
};

#endif