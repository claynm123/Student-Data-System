#pragma once
#include "student.h"

class Roster {
	private:

	public:

		vector <Student*> classRosterArray;

		//CONSTRUCTORS
		Roster();
		Roster(const string[],unsigned int);

		//Destructor
		~Roster();

		//FUNCTIONS
		void add(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeprogram);

		void remove(string);

		void printAll();

		void printAverageDaysInCourse(string);

		void printInvalidEmails();

		void printByDegreeProgram(DegreeProgram);

};