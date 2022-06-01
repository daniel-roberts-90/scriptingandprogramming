#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"


student::student() {

	studentID = "NONE";
	Age = -1;
	firstName = "NOFIRSTNAME";
	lastName = "NOLASTNAME";
	emailAddress = "NOEMAIL";
	for (int i = 0; i < 3; ++i) {
		NumDays[i] = 0;
	}
}



student::student(string sID, string firstN, string lastN, string emailAdd, int addAge, int* noDays, Degree degreeProgram) {
	studentID = sID;
	firstName = firstN;
	lastName = lastN;
	emailAddress = emailAdd;
	Age = addAge;
	NumDays[0] = noDays[0];
	NumDays[1] = noDays[1];
	NumDays[2] = noDays[2];
	degree = degreeProgram;
}



void student::print() {
	cout << "Student ID: " << getStudentID() << endl;
	cout << "First Name: " << getFirstName() << endl;
	cout << "Last Name: " << getLastName() << endl; 
	cout << "Age: " << getAge() << endl;
	cout << "Email Address: " << getEmailAddress() << endl;
	cout << "Degree Program: " << getDegreeProgram() << endl;
	cout << "Days in Course: " << NumDays[0] << " " << NumDays[1] << " " << NumDays[2] << endl << endl;
}



void student::setStudentID(string setstudentID) {
	studentID = setstudentID;
}

string student::getStudentID() const {
	return studentID;
}


void student::setFirstName(string setfirstName) {
	firstName = setfirstName;
}

string student::getFirstName() const {
	return firstName;
}


void student::setLastName(string setlastName) {
	lastName = setlastName;
}

string student::getLastName() const {
	return lastName;
}


void student::setEmailAddress(string setemailAddress) {
	emailAddress = setemailAddress;
}

string student::getEmailAddress() const {
	return emailAddress;
}


void student::setAge(int setAge) {
	Age = setAge;
}

int student::getAge() const {
	return Age;
}


void student::setNumDays(int class1, int class2, int class3) {
	NumDays[0] = class1;
	NumDays[1] = class2;
	NumDays[2] = class3;
}

int* student::getNumDays() {
	return NumDays;
}



void student::setDegreeProgram(Degree setdegreeProgram) {
	degree = setdegreeProgram;
}

string student::getDegreeProgram() const {
	string network = "NETWORK";
	string software = "SOFTWARE";
	string security = "SECURITY";
	string error = "ERROR";

	
	if ((int)degree == 0) {
		return security;
	}
	else if ((int)degree == 1) {
		return network;
	}
	else if ((int)degree == 2) {
		return software;
	}
	else {
		return error;
	}
}
