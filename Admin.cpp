#include "Admin.h"
#include <iostream>
#include <string>
using namespace std;


Admin::Admin() {

	//default admin login info.
	ID = "admin";
	Password = "admin";

	marks = P = A = 0;
	courseName = stuID = " ";
	grade = '-';
}

bool Admin::Login() {

	string id, pass;
	string I_D = "Hina Iqbal";
	string pa_ss="oop123";

	while (1) {
		system("cls");
		cout << " --------------------------------------- " << endl;
		cout << "                  LOGIN                  " << endl;
		cout << " --------------------------------------- " << endl << endl;
		cout << "    ID (Hina Iqbal)          :"; cin >> id;
		cout << "    PASSWORD (oop123)        :"; cin >> pass;
		cout << " --------------------------------------- " << endl;

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

int Admin::Menu() {

	int choice;

	system("cls");
	cout << "------------------------------------" << endl;
	cout << "                MENU                " << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "                               Press" << endl << endl;
	cout << " Add Student                     (1)" << endl;
	cout << " View Students                   (2)" << endl;
	cout << " Edit Student                    (3)" << endl;
	cout << " Exit                            (4)" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while (!(choice > 0 && choice < 5)) {
		cout << "Invalid Choice!  Please Enter Again: ";
		cin >> choice;
	}
	return choice;
}

Admin::~Admin() {}