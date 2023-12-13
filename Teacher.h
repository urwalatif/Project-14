#pragma once
#ifndef Teacher_H
#define Teacher_H

#include "Admin.h"
#include <string>
using namespace std;

class Teacher : public Admin {

	string firstName, lastName, DepartmentName, regDate;
	string Username, Password, confirmPassword;
	char gender;
	string Qualification, Address;
	string tID, contactNo;
	int count;

	string loggedIn;


public:

	Teacher();

	friend istream& operator >> (istream& in, Teacher& obj);

	bool Login();
	int Menu();

	void saveData();
	void viewAllTeachers();
	void editTeacher();
	void DisplayTeacherID();
	void countLines();
	void MarkAttendance();
	void AssignMarks();
	void AssignGrade();

	string viewTimeTable();


	~Teacher();
};

#endif