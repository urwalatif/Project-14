#pragma once
#ifndef Admin_H
#define Admin_H

#include <string>
using namespace std;

class Admin {

	string ID;
	string Password;

protected:
	int marks, P, A;
	string stuID, courseName;
	char grade;

public:
	Admin();
	virtual bool Login();
	virtual int Menu();
	virtual void countLines() {};


	~Admin();
};

#endif