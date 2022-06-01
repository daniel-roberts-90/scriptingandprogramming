#include <iostream>
#include <string>
#include <sstream>


#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

int main() {

	cout << "Course: Scripting and Programming  Applications  C867\n";
	cout << "Programming language used: C++\n";
	cout << "Student ID: #009198202\n";
	cout << "Name: Daniel Roberts" << endl << endl;






	
	string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Daniel, Roberts,drob839@wgu.edu,31,14,14,10,SOFTWARE,"
	};

	
	Roster classRoster;
	Degree degreeProgram;


	int i = 0;

	
	for (i = 0; i < 5; ++i) {

		string tempData = studentData[i];
		string studentInfo[9];
		string temp;
		stringstream input(tempData);

		int x = 0;
		while (getline(input, temp, ','))
		{
			studentInfo[x] = temp;
			
			++x;
		}

		
		if (studentInfo[8] == "SECURITY")
		{
			degreeProgram = Degree::SECURITY;
		}
		else if (studentInfo[8] == "SOFTWARE") {
			degreeProgram = Degree::SOFTWARE;
		}
		else if (studentInfo[8] == "NETWORK") {
			degreeProgram = Degree::NETWORK;
		}

		
		classRoster.add(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3], stoi(studentInfo[4]), stoi(studentInfo[5]), stoi(studentInfo[6]), stoi(studentInfo[7]), degreeProgram);

	}

	classRoster.printAll();
	classRoster.printInvalidEmails();
	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");
	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");


}
