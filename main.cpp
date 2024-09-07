#include <iostream>
#include "section.h"

using namespace std;

int main(int argc, char** argv) 
{
	char op;
	Section section("BSCS 2 F1");
	Student s;
	int i;
	
	do
	{
		cout << "Enter operation: ";
		cin >> op;
		
		cin.ignore();
		
		switch(op)
		{
			case 'a':
				cout << "Enter name: ";
				getline(cin, s.name);
				cout << "Enter roll number: ";
				cin >> s.rollNumber;
				cout << "Enter 5 grades:\n";
				for (i = 0; i < 5; i++)
					cin >> s.marks[i];
				section.addStudent(&s);
				break;
			
			case 'p':
				cout << "Printing..." << endl << endl;
				section.printStudents();
				break;
			
			case 'x':
				return 0;
		}
	} while (op != 'x');
	

	return 0;
}
