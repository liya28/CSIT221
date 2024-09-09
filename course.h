#include "student.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Course
{
	int course_id;
	string course_name;
	Student *students;
	int student_count;
	int student_capacity;
	
	Course(int id = 0, string name = "") : 
		course_id(id), course_name(name), student_count(0), student_capacity(5)
		{
			students = new Student[student_capacity];
		}
	
	~Course()
	{
		delete[] students;
	}
	
	void resizeUp()
	{
		student_capacity = student_capacity + ceil(student_capacity * 0.25);
		Student *new_students = new Student[student_capacity];
		for (int i = 0; i < student_count; i++)
		{
			new_students[i] = students[i];
		}
		delete[] students;
		students = new_students;
	}
		
	void addStudent(int student_id, string student_name, double grade)
	{
		if (student_count == student_capacity)
		{
			resizeUp();
		}
		
		int i = student_count - 1;
		while (i >= 0 && students[i].grade > grade)
		{
			students[i + 1] = students[i];
			--i;
		}
		students[i + 1] = Student(student_name, student_id, grade);
		student_count++;
	}
	
	void removeStudent(int student_id)
	{
		int index = -1;
		for (int i = 0; i < student_count; i++)
		{
			if (students[i].id == student_id)
			{
				index = i;
				break;
			}	
		}
		if (index != -1)
		{
			for (int i = index; i < student_count - 1; i++)
			{
				students[i] = students[i + 1];	
			}	
			student_count--;
		}	
	}
	
	void printStudentsInTheCourse() const
	{
        for (int i = 0; i < student_count; ++i) 
		{
            cout << "  Student ID: " << students[i].id
            	 << ", Name: " << students[i].name
                << ", Grade: " << students[i].grade << "\n";
        }
    }
};
