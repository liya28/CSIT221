#include "student.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Section
{
	private:
		string section;
		int size;
		int capacity;
		Student *students;
		
	public:
		
		Section(string name) : size(0), capacity(5) 
		{
			this->section = name;
			students = new Student[capacity];  // Use 'new' instead of 'malloc'
	    }
	
	    ~Section() 
	    {
	        delete[] students;  // Ensure we free the allocated memory
	    }
	
	    void addStudent(Student* s)
	    {
	        if (size == capacity)
	        {
	            capacity *= 2;
	            Student* new_students = new Student[capacity];  
	            memcpy(new_students, students, size * sizeof(Student));  
	            delete[] students;  
	            students = new_students;  
	        }
	
	        students[size].name = s->name;
	
	        size_t offset = offsetof(Student, rollNumber);
	        memcpy((char*)&students[size] + offset, (char*)s + offset, sizeof(Student) - offset);
	
	        ++size;
	    }
		
		void printStudents()
		{
			int i, j;
			cout << "\nSECTION " << section << endl;
 			for (i = 0; i < size; i++)
 			{
 				cout << "\nStudent " << i + 1 << endl;
				cout << "Name: " << students[i].name << endl;
				cout << "Roll Number: " << students[i].rollNumber << endl;
				cout << "Grades:\n";
				for (j = 0; j < 5; j++)
				{
					cout << "Grade " << j + 1 << ": " << students[i].marks[j] << endl;
				}
				cout << "Total Marks: " << students[i].getTotalMarks();	
			}
			
			cout << endl;
		}
};
