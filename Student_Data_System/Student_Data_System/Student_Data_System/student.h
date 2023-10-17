#pragma once
#include "degree.h"


class Student {
	public: 
		//CONSTRUCTOR
		Student(string studentID, string firstName,
			string lastName, string emailAddress, unsigned int age,
			vector<unsigned int> daysLeft, DegreeProgram degree);
		
		//GETTERS
		const string GetID();
		const string GetFirstName();
		const string GetLastName();
		const string GetEmail();
		const unsigned int GetAge();
		const vector<unsigned int> GetDaysLeft();
		const DegreeProgram GetDegree();

		//SETTERS
		void SetID(string);
		void SetFirstName(string);
		void SetLastName(string);
		void SetEmail(string);
		void SetAge(unsigned int);
		void SetDaysLeft(vector<unsigned int>);
		void SetDegree(DegreeProgram);

		//PRINT function
		void print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		unsigned int age;
		vector<unsigned int> daysLeft;
		DegreeProgram degree;
};