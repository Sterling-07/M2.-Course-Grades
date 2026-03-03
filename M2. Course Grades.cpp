// M2. Course Grades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
	printData(numStudents, students);

	for (int a = 0; a < numStudents; a++)
	{
		delete[] students[a].testScores;
	}
	delete[] students;
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
	cout << setw(27) << "Student Information\n";
	cout << "----------------------------------\n";
	cout << setw(6) << "Name" << setw(4) << "|" << setw(4) << "ID" << setw(3) << "|" << setw(8) 
		<< "Average" << setw(2) << "|" << setw(7) << "Letter" << endl;
	cout << setw(8) << students[0].name << setw(2) << "|" << setw(5) << students[0].id << setw(2) 
		<< "|" << setw(6) << students[0].average << setw(4) << "|" << setw(4) << students[0].letter << endl;
	cout << setw(8) << students[1].name << setw(2) << "|" << setw(5) << students[1].id << setw(2) 
		<< "|" << setw(6) << students[1].average << setw(4) << "|" << setw(4) << students[1].letter << endl;
	cout << setw(7) << students[2].name << setw(3) << "|" << setw(5) << students[2].id << setw(2) 
		<< "|" << setw(6) << students[2].average << setw(4) << "|" << setw(4) << students[2].letter << endl;
	cout << setw(6) << students[3].name << setw(4) << "|" << setw(5) << students[3].id << setw(2) 
		<< "|" << setw(6) << students[3].average << setw(4) << "|" << setw(4) << students[3].letter << endl;
	cout << setw(6) << students[4].name << setw(4) << "|" << setw(5) << students[4].id << setw(2) 
		<< "|" << setw(6) << students[4].average << setw(4) << "|" << setw(4) << students[4].letter << endl;
	cout << setw(6) << students[5].name << setw(4) << "|" << setw(5) << students[5].id << setw(2) 
		<< "|" << setw(6) << students[5].average << setw(4) << "|" << setw(4) << students[5].letter << endl;
	cout << setw(8) << students[6].name << setw(2) << "|" << setw(5) << students[6].id << setw(2) 
		<< "|" << setw(6) << students[6].average << setw(4) << "|" << setw(4) << students[6].letter << endl;
	cout << setw(8) << students[7].name << setw(2) << "|" << setw(5) << students[7].id << setw(2) 
		<< "|" << setw(4) << students[7].average << setw(6) << "|" << setw(4) << students[7].letter << endl;
	cout << setw(6) << students[8].name << setw(4) << "|" << setw(5) << students[8].id << setw(2) 
		<< "|" << setw(6) << students[8].average << setw(4) << "|" << setw(4) << students[8].letter << endl;
	cout << setw(6) << students[9].name << setw(4) << "|" << setw(5) << students[9].id << setw(2) 
		<< "|" << setw(6) << students[9].average << setw(4) << "|" << setw(4) << students[9].letter << endl;
}
