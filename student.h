#include <string>
#include <cstdlib>

using namespace std;

struct Student
{
	string name;
	int rollNumber;
	int *marks;
	int totalMarks;
	
	Student() : name(""), rollNumber(0), totalMarks(0)
	{
		marks = (int*)malloc(5 * sizeof(int));
	}
	
	int getTotalMarks()
	{
		int sum = 0, i;
		for (i = 0; i < 5; i++)
			sum += marks[i];
		return sum;
	}
};
