#include <string>

using namespace std;

struct Student
{
	string name;
	int id;
	double grade;	
	
	Student(string name = "", int id = 0, double grade = 0.0) : name(name), id(id), grade(grade) {}
};
