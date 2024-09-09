#include "coursearraylist.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    CourseArrayList cal;
    
    cal.addCourse(101, "Data Structures and Algorithms");
    cal.addCourse(102, "OOP 1");
    
    // Adding students to the courses
    cal.addStudentToCourse(101, 1, "Aliyah", 99.99);
    cal.addStudentToCourse(101, 2, "Clyd", 99.90);
    cal.addStudentToCourse(102, 3, "Harliy", 99.89);
    
    // Display all courses and students
    cout << "Courses and their students: " << endl;
    cal.printAllCoursesAndStudents();
    
    // Try removing a valid student from Course 101
    cal.removeStudentFromCourse(101, 2); // Remove Clyd from DSA
    cout << "\nAfter removing a student from Course 101: " << endl;
    cal.printAllCoursesAndStudents();
    
    // Remove the entire course
    cal.removeCourse(101); // Removing DSA
    cout << "\nAfter removing DSA course: " << endl;
    cal.printAllCoursesAndStudents();
    
    return 0;
}

