#include <bits/stdc++.h>

using namespace std;

//=================================================STRUCTURES===============================================

struct DateTime
{
	struct Date
	{
		int day,month,year;
		
	} date;
	
	struct Time
	{
		int hour,min;
		
	} time;
};

struct Note
{
	string FacultyName;
	
	int LevelOfStrictness;
	
	string Others;
};

struct subject
{
	struct DateTime StartTime,EndTime;
	
	string ClassName,ClassType;
	
	int ThresholdPercentage,MaxPossiblePercentage;
	
	struct Note notes;
	
};

struct students
{
	string name;
	
	struct subject *subjects;
	
	int MaxSubjects;
	
} *student;

//==============================================FUNCTIONS==================================================

void PrintStudentSubjects(int x)
{
	int i,n;
	
	n=student[x-1].MaxSubjects;
	
	for(i=0;i<n;i++)
	cout<<student[x-1].subjects[i].ClassName<<'\n';
}

//================================================MAIN=====================================================

int main(void)
{
	int NStudents,Subjects,i,j;
	
	cout<<"Enter Number of Students:- ";
	
	cin>>NStudents;
	
	student=(struct students*)malloc(sizeof(struct students)*NStudents);
	
	cout<<'\n';
	
	for(i=1;i<=NStudents;i++)
	{
		cout<<"Enter Number of Subjects for "<<i<<" Student:- ";
		
		cin>>Subjects;
		
		student[i].MaxSubjects=Subjects;
		
		student[i].subjects=(struct subject*)malloc(sizeof(struct subject)*Subjects);
		
		cout<<'\n';
		
		for(j=1;j<=Subjects;j++)
		{
			cout<<"Enter the name of Subject "<<j<<" :- ";
			
			cin>>student[i].subjects[j-1].ClassName;
		}
		
		PrintStudentSubjects(i);
	}
	
	return 0;
}

