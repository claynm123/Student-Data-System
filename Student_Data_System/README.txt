This back-end uses an object-oriented approach, creating a "roster" object that nests "student" object pointers within an array.
"Student" objects have their own private data and public getter/setter functions found in Student.cpp.

For my applications of programming class, I made this back-end for a C++ application that manages student data.
 
It's main() function currently runs single-case tests for the following functions;

- Creating a class roster from string/string-array inputs (using custom constructor)
- Printing all entries from a class roster
- Printing roster entries with invalid emails 
- Printing average days left in classes for each student
- Printing students by specified degree program
- Removal of student from roster
- Error message triggered by invalid removal
- Destructor for roster class

Memory that is dynamically allocated for pointers within a "classRosterArray" is dealt with
by the roster destructor "~Roster()".
Any further dynamic memory implementations (pointers) must include it's
own destruction.