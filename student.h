#pragma once

#include <string>
#include "degree.h"
using namespace std;

class student {

private:
	
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int Age;
	int NumDays[3];
	Degree degree;

public:

	
	student();
	void print();


	
	student(string sID, string firstN, string lastN, string emailAdd, int addAge, int* noDays, Degree degreeProg);

	
	void setStudentID(string setstudentID);
	string getStudentID() const;

	void setFirstName(string setfirstName);
	string getFirstName() const;

	void setLastName(string setlastName);
	string getLastName() const;

	void setEmailAddress(string setemailAddress);
	string getEmailAddress() const;

	void setAge(int setAge);
	int getAge() const;

	void setDegreeProgram(Degree setdegreeProgram);
	string getDegreeProgram() const;

	void setNumDays(int class1, int class2, int class3);
	int* getNumDays();








};
