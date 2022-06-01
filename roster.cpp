#include <iostream>
#include <string>
using namespace std;


#include "student.h"
#include "degree.h"
#include "roster.h"



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysinCourse2, int daysIncourse3, Degree degreeProg) {

	int averageDays[3] = { daysInCourse1,daysinCourse2,daysIncourse3 };
	classRosterArray[studentCount] = new student(studentID, firstName, lastName, emailAddress, age, averageDays, degreeProg);
	++studentCount;
}


void Roster::remove(string studentID) {

	bool studentwasRemoved = false;
	int i = 0;

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] != NULL) {

			if (classRosterArray[i]->getStudentID() == studentID) {
				classRosterArray[i] = nullptr;
				studentwasRemoved = true;
			}
		}
	}

	if (studentwasRemoved == false) {
		cout << "Student with this ID does not exist: " << studentID << endl;
	}
}


void Roster::printAll() {
	cout << "PrintAll: " << endl << endl;
	int i = 0;
	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->print();
			cout << endl << endl;
		}
	}

}


void Roster::printAverageDaysInCourse(string studentID) {

	int i = 0;

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			int average = 0;
			average = (classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2]) / 3;
			cout << "Student ID: " << studentID << " Average days it took to complete courses: " << average << endl << endl;
		}
	}
}


void Roster::printInvalidEmails() {
	int i = 0;

	for (int i = 0; i < 5; ++i) {
		string invalidEmail = classRosterArray[i]->getEmailAddress();

		if (invalidEmail.find("@") == -1 || invalidEmail.find(".") == -1 || invalidEmail.find(" ") != -1) {
			cout << invalidEmail << " is not a valid email." << endl << endl;
		}
	}
}


void Roster::printByDegreeProgram(Degree degreeProgram) {
	int i = 0;
	Degree d = degreeProgram;
	string degree;

	
	if (d == 0) {
		degree = "SECURITY";
	}
	else if (d == 1) {
		degree = "NETWORK";
	}
	else if (d == 2) {
		degree = "SOFTWARE";
	}

	cout << "Students in " << degree << " program:" << endl << endl;

	
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	int i = 0;
	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
}
