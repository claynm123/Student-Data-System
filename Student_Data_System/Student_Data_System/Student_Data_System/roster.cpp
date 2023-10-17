#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#include "roster.h"


//DEFAULT CONSTRUCTOR
Roster::Roster() {

}

//CONSTRUCTOR WITH STRING ARRAY PARAMETER
Roster::Roster(const string studentData[], unsigned int size) {

	string tempID;
	string tempFirst;
	string tempLast;
	string tempEmail;
	unsigned int tempAge = 0;
	vector<unsigned int> tempDaysIn;
	DegreeProgram tempDegree;

	for (unsigned int i = 0; i < size ; i++) {


        //vector<unsigned int> tempDaysIn(3, 0); 
		
		stringstream datStream(studentData[i]);
		unsigned int counter = 0;
		
		while (datStream.good()) {

			string subString;
			getline(datStream, subString, ',');

			switch (counter) {
			case 0: tempID = subString;
				break;
			case 1: tempFirst = subString;
				break;
			case 2: tempLast = subString;
				break;
			case 3: tempEmail = subString;
				break;
			case 4: tempAge = stoi(subString);
				break;
			case 5: tempDaysIn.push_back(stoi(subString));
				break;
			case 6: tempDaysIn.push_back(stoi(subString));
				break;
			case 7: tempDaysIn.push_back(stoi(subString));
				break;
			case 8: 

				if (subString == "SOFTWARE") {
					tempDegree = SOFTWARE;
				}
				else if (subString == "NETWORK") {
					tempDegree = NETWORK;
				}
				else if (subString == "SECURITY") {
					tempDegree = SECURITY;
				}
				else {
					tempDegree = INVALID;
				}
				break;
			}

			counter++;
		}
		Student* newStu = new Student (tempID, tempFirst, tempLast, tempEmail, tempAge, tempDaysIn, tempDegree);
		this->classRosterArray.push_back(newStu);
		tempDaysIn.clear();
	}
}

//DESTRUCTOR
Roster::~Roster() {
	for (unsigned int i = 0; i < this->classRosterArray.size(); i++) {
		delete this->classRosterArray[i];
	}
	this->classRosterArray.clear();
}

//FUCTION TO ADD NEW STUDENT TO A ROSTER
void Roster::add(string studentID, string firstName, string lastName,
string emailAddress, int age, int daysInCourse1, int daysInCourse2,
int daysInCourse3, DegreeProgram degreeProgram) {

	vector<unsigned int> daysInTempVect;
	daysInTempVect.push_back(daysInCourse1);
	daysInTempVect.push_back(daysInCourse2);
	daysInTempVect.push_back(daysInCourse3);

	Student* studentToAdd = new Student(studentID, firstName, lastName, emailAddress,
		age, daysInTempVect, degreeProgram);

	this->classRosterArray.push_back(studentToAdd);
}

//REMOVES A STUDENT FROM classRosterArray
void Roster::remove(string studentID) {
	bool removeSuccess = false;
	for (unsigned int i = 0; i < classRosterArray.size(); i++) {
		if (this->classRosterArray[i]->GetID() == studentID) {
			delete this->classRosterArray[i];
			this->classRosterArray.erase(this->classRosterArray.begin() + i);
			removeSuccess = true;
		}
	}
	if (removeSuccess == false) {
		cout << "Student removal unsuccessful. No student with id: " << studentID 
			<< " found." << endl << endl;
	}
} 

//PRINTS ALL STUDENTS' DATA
void Roster::printAll() {
cout << "Printing all students' data:" << endl;
	for (unsigned int i = 0; i < this->classRosterArray.size(); i++) {
		this->classRosterArray[i]->print();
	}
	cout << endl;
}
//PRINTS AVERAGE OF DAYS LEFT IN COURSES
void Roster::printAverageDaysInCourse(string studentID) {

	unsigned int vectorSize = classRosterArray.size();

	for (unsigned int i = 0; i < vectorSize; i++) {

		if (this->classRosterArray[i]->GetID() == studentID) {
			
			cout << "For student: "
			<< this->classRosterArray[i]->GetFirstName() << " "
			<< this->classRosterArray[i]->GetLastName() << " , "
			<< "ID: " << this->classRosterArray[i]->GetID() << " :" << endl
			<< "Average number of days left in classes: "

			<< ( this->classRosterArray[i]->GetDaysLeft().at(0) + 
				this->classRosterArray[i]->GetDaysLeft().at(1) + 
				this->classRosterArray[i]->GetDaysLeft().at(2) ) / 3 
			<< endl << endl;
			goto escapePoint;
		}
	}
	escapePoint:;
}

void Roster::printInvalidEmails() {

	unsigned int vectorSize = classRosterArray.size();

	for (unsigned int i = 0; i < vectorSize; i++) {

		string tempEmail = this->classRosterArray[i]->GetEmail();
		bool containsAtSymbol = false;
		bool containsPeriod = false;

		for(unsigned int x = 0; x < tempEmail.size(); x++) {
		
			if (isspace(tempEmail.at(x)) ) {
				cout << "Email : " << tempEmail << " contains a space, which is invalid!" << endl;
			}
			if (tempEmail.at(x) == '@') {
				containsAtSymbol = true;
			}
			if (tempEmail.at(x) == '.') {
				containsPeriod = true;
			}
		}

		if (containsPeriod == false || containsAtSymbol == false) {
			cout << "Email : " << tempEmail << " does not contain both a period and \"@\", which is invalid." << endl;
		}
	}

	cout << endl;
}

void Roster::printByDegreeProgram(const DegreeProgram degreeProgram) {

	unsigned int vectorSize = classRosterArray.size();

	cout << "Printing all students with degree program " << degreeProgram << ":" << endl;
	for (unsigned int i = 0; i < vectorSize; i++) {
		if (this->classRosterArray.at(i)->GetDegree() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
	cout << endl;
}


//UNUSED - PURPOSE REFITTED INTO CONSTRUCTOR #2
/*void Roster::ParseData(string inputString[]) {
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Clay,Metz,cmetz16@wgu.edu,23,9,8,7,SOFTWARE" };
	
	string tempID;
	string tempFirst;
	string tempLast;
	string tempEmail;
	unsigned int tempAge;
	vector<unsigned int> tempDaysIn;
	DegreeProgram tempDegree;

	stringstream datStream(studentData[0]);

	unsigned int counter = 0;

	while (datStream.good()) {

		string subString;
		getline(datStream,subString,',');

		switch (counter) {
			case 0: tempID = subString;
				break;
			case 1: tempFirst = subString;
				break;
			case 2: tempLast = subString;
				break;
			case 3: tempEmail = subString;
				break;
			case 4: tempAge = stoi(subString);
				break;
			case 5: tempDaysIn.push_back(stoi(subString));
				break;
			case 6: tempDaysIn.push_back(stoi(subString));
				break;
			case 7: tempDaysIn.push_back(stoi(subString));
				break;
			case 8: tempDegree.addDegree(subString);
		}

	}
}*/