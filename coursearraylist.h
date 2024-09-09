#include "course.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class CourseArrayList
{
	private:
		Course *courses;
		int course_count;
		int course_capacity;
		
		void resizeUp()
		{
			course_capacity = course_capacity + ceil(course_capacity * 0.25);
			Course *new_courses = new Course[course_capacity];
			for (int i = 0; i < course_count; i++)
			{
				new_courses[i] = courses[i];
			}
			delete[] courses;
			courses = new_courses;
		}
			
	public:
		
		CourseArrayList() : course_count(0), course_capacity(5)
		{
			courses = new Course[course_capacity];
		}
		
		~CourseArrayList()
		{
			delete[] courses;
		}
		
		void addCourse(int course_id, string course_name)
		{
			if (course_count == course_capacity)
			{
				resizeUp();
			}
			
			courses[course_count] = Course(course_id, course_name);
			course_count++;
		}
		
		void removeCourse(int course_id)
		{
			int index = -1;
			for (int i = 0; i < course_count; i++)
			{
				if (courses[i].course_id == course_id)
				{
					index = i;
					break;
				}
			}
			
			if (index != -1)
			{
				for (int i = index; i < course_count - 1; i++)
				{
					courses[i] = courses[i + 1];
				}
				course_count--;
			}
		}
		
		void addStudentToCourse(int course_id, int student_id, string student_name, double grade)
		{
			for (int i = 0; i < course_count; i++)
			{
				if (courses[i].course_id == course_id)
				{
					courses[i].addStudent(student_id, student_name, grade);
					return;
				}
			}
			
			cout << "Course not found!" << endl;
		}
		
		void removeStudentFromCourse(int course_id, int student_id)
		{
			for (int i = 0; i < course_count; i++)
			{
				if (courses[i].course_id == course_id)
				{
					courses[i].removeStudent(student_id);
					return;
				}
			}
			
			cout << "Course not found!" << endl;
		}
		
		void printAllCoursesAndStudents()
		{
			for (int i = 0; i < course_count; i++)
			{
				cout << "Course ID: " << courses[i].course_id << ", Course Name: " << courses[i].course_name << endl;
				courses[i].printStudentsInTheCourse();
				cout << endl;
			}
		}
		
		int getCourseCount() const
		{
			return course_count;	
		}	
};	
