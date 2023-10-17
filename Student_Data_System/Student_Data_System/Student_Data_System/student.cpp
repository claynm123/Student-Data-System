#include <iostream>
using namespace std;
#include <vector>
#include "student.h"


//CONSTRUCTOR
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
unsigned int age, vector<unsigned int> daysLeft, DegreeProgram degree) {
	SetID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmail(emailAddress);
	SetAge(age);
	SetDaysLeft(daysLeft);
	SetDegree(degree);
}

//Start of GETTERS
const string Student::GetID() {
	return this->studentID;
}

const string Student::GetFirstName() {
	return this->firstName;
}

const string Student::GetLastName() {
	return this->lastName;
}

const string Student::GetEmail() {
	return this->emailAddress;
}

const unsigned int Student::GetAge() {
	return this->age;
}

const vector<unsigned int> Student::GetDaysLeft() {
	return this->daysLeft;
}

const DegreeProgram Student::GetDegree() {
	return this->degree;
}

//Start of SETTERS
void Student::SetID(string id) {
	this->studentID = id;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmail(string email) {
	this->emailAddress = email;
}
void Student::SetAge(unsigned int age) {
	this->age = age;
}
void Student::SetDaysLeft(vector<unsigned int> daysLeft) {
	this->daysLeft = daysLeft;
}
void Student::SetDegree(DegreeProgram degree) {
	this->degree = degree;
} 

//PRINT Function//
void Student::print() {
	
	string tempDegreeStr;

	switch (this->degree) {
	case 0:
		tempDegreeStr = "SECURTIY";
		break;
	case 1:
		tempDegreeStr = "NETWORK";
		break;
	case 2:
		tempDegreeStr = "SOFTWARE";
		break;
	case 3:
		tempDegreeStr = "INVALID";
		break;
	}

	cout << this->studentID << "    "
	<< "First Name: " << this->firstName << "    "
	<< "Last Name: " << this->lastName << "    "
	<< "Age: " << this->age << "    " 
	<< "daysInCourse: {" << this->daysLeft[0] << ", " << this->daysLeft[1] << ", " << this->daysLeft[1] << "}    "
	<< "Degree Program: " << tempDegreeStr << "    "
	<< endl;
}
