#include <iostream>
using namespace std;
#include <vector>

#include "roster.h"


int main()
{
	const string studentData[] =
		{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Clay,Metz,cmetz16@wgu.edu,23,9,8,7,SOFTWARE" };

	cout << "Scripting and Programming - Applications - C867" << endl
	<< "Written in C++ " << endl
	<< "Student ID: 011047314 - Clayton Metz" << endl << endl;
	
	//The constructor of Roster class does the following:
	//1.Parses studentData string array 
	//2.Creates student objects for each student with parsed data
	//3.Adds pointers to student objects to the Roster's classRosterArray
	Roster* classRoster = new Roster(studentData , 5);
	
	classRoster->printAll();
	classRoster->printInvalidEmails();

	for (unsigned int i = 0; i < 5; i++) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i] ->GetID());
	}

	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");

	classRoster->~Roster();
	delete classRoster;
}
