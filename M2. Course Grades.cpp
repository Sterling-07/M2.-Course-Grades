// M2. Course Grades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct student 
{
	string name;
	int id;
	int* testScores;
	double average;
	char letter;
};

void readData(int &numStudents, int &numTests, student* &students);
void calcAverage(double &avg, int& numStudents, int& numTests, student* students);
void getLetterGrade(int &numStudents, student* students);
void printData(int &numStudents, student* students);

int main()
{
	int numStudents, numTests;
	double avg;
	student* students = nullptr;

	readData(numStudents, numTests, students);
	calcAverage(avg, numStudents, numTests, students);
	getLetterGrade(numStudents, students);

	for (int a = 0; a < numStudents; a++)
	{
		cout << students[a].letter << " ";
		cout << endl;
	}

	return 0;
}

void readData(int& numStudents, int& numTests, student* &students)
{
	ifstream inputfile("student data.txt");
	if (!inputfile)
	{
		cout << "There was an error opening the file.\n";
	}

	inputfile >> numStudents >> numTests;

	students = new student[numStudents];

	for (int a = 0; a < numStudents; a++)
	{
		inputfile >> students[a].name;
		inputfile >> students[a].id;

		students[a].testScores = new int[numTests];
		for (int b = 0; b < numTests; b++)
		{
			inputfile >> students[a].testScores[b];
		}
	}
}

void calcAverage(double &avg, int& numStudents, int& numTests, student* students)
{
	for (int a = 0; a < numStudents; a++)
	{
		avg = 0;
		for (int b = 0; b < numTests; b++)
		{
			avg += students[a].testScores[b];
		}
		students[a].average = avg / numTests;
	}
}

void getLetterGrade(int& numStudents, student* students)
{
	for (int a = 0; a < numStudents; a++)
	{
		if (students[a].average >= 90 && students[a].average <= 100)
		{
			students[a].letter = 'A';
		}
		else if (students[a].average >= 80)
		{
			students[a].letter = 'B';
		}
		else if (students[a].average >= 70)
		{
			students[a].letter = 'C';
		}
		else if (students[a].average >= 60)
		{
			students[a].letter = 'D';
		}
		else
		{
			students[a].letter = 'F';
		}
	}
}

void printData(int& numStudents, student* students)
{

}
