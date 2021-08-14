// Muhammad Sameer Farooq
// 18L-0986
// BS(CS)-A1

#include <iostream>
#include <fstream>
#include <windows.h>
#include "Calendar.h"
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int Days = 0, TotalActivitiesInACalendarYear = 0;
const int months = 12, HoursInADay = 24, NumberOfActivitiesforDefaultValue = 1;
int*** Counter = nullptr;
int NumberOfDaysInMonth(int i)
{
	if (i<7)
	{
		if (i%2==0)
			return 31;
		else
		{
			if (i==1)return 28;
			else return 30;
		}
	}
	else
	{
		if (i%2!=0)
			return 31;
		else return 30;
	}
}
char* MonthName(int i)
{
	if (i==0)
		return "January";
	else if (i==1)
		return "February";
	else if (i==2)
		return "March";
	else if (i==3)
		return "April";
	else if (i==4)
		return "May";
	else if (i==5)
		return "June";
	else if (i==6)
		return "July";
	else if (i==7)
		return "August";
	else if (i==8)
		return "September";
	else if (i==9)
		return "October";
	else if (i==10)
		return "November";
	else
		return "December";
}
char* Suffixes(int i)
{
	if (i==0)
		return "st";
	else if (i==1)
		return "nd";
	else if (i==2)
		return "rd";
	else if (i==20)
		return "st";
	else if (i==21)
		return "nd";
	else if (i==22)
		return "rd";
	else if (i==30)
		return "st";
	else
		return "th";
}
int StartDayOfMonth(int i)
{
	if (i==1||i==10)
		return 2;
	else if (i==2||i==3||i==11)
		return 5;
	else if (i==4||i==7)
		return 1;
	else if (i==5)
		return 3;
	else if (i==6)
		return 6;
	else if (i==8)
		return 4;
	else
		return 7;

}
char* DayName(int i)
{
	if (i==1)
		return "Mon";
	else if (i==2)
		return "Tues";
	else if (i==3)
		return "Wed";
	else if (i==4)
		return "Thur";
	else if (i==5)
		return "Fri";
	else if (i==6)
		return "Sat";
	else
		return "Sun";
}
void SetColour(int i)
{
	SetConsoleTextAttribute(hConsole, i);
}
Activity***** AllocationOfCalendar()
{
	Activity*****Calendar = new Activity**** [months];
	Counter = new int ** [months];
	for (int i = 0; i<months; i++)
	{
		Calendar [i] = new Activity *** [Days = NumberOfDaysInMonth(i)];
		Counter [i] = new int * [Days];
		for (int j = 0; j<Days; j++)
		{
			Calendar [i][j] = new Activity ** [HoursInADay];
			Counter [i][j] = new int [HoursInADay];

			for (int k = 0; k<HoursInADay; k++)
			{
				Calendar [i][j][k] = new Activity * [NumberOfActivitiesforDefaultValue];
				for (int l = 0; l<NumberOfActivitiesforDefaultValue; l++)
				{
					Calendar [i][j][k][l] = new Activity [1];
				}
				Calendar [i][j][k] = nullptr;
				Counter [i][j][k] = 0;
			}
		}
	}
	return Calendar;
}
void AddActivity(Activity *****&Calendar, Activity Cal, Date d, int c)
{

	int i = 0, size = 0, a = d.month-1, b = d.day-1;
	for (i = 0; i<Counter [a][b][c]; i++);

	Activity **temp = new Activity* [i+1];

	for (i = 0; i<Counter [a][b][c]; i++)
		temp [i] = Calendar [a][b][c][i];

	size = i;
	delete[]Calendar [a][b][c];
	Calendar [a][b][c] = temp;
	Calendar [a][b][c][i] = new Activity;
	Calendar [a][b][c][i][0] = Cal;
	Counter [a][b][c] = ++i;
	TotalActivitiesInACalendarYear++;
}
void ReturnCounter(int***&Count)
{
	Count = Counter;
}
Activity***** InputFromFile(Activity *****Calendar)
{
	int StartTime = 0, EndTime = 0;
	Date d;
	char File [120];
	ifstream fin;
	bool flag = true;
	Activity *Cal = new Activity [10000];
	while (true)
	{
		cin.ignore();
		cout<<"Input the file name : ";
		cin.getline(File, 120);
		if (strcmp(File, "0")==0)
		{
			flag = false;
			break;
		}
		fin.open(File);
		if (fin.fail())
		{
			cout<<"File not found.\nMake sure that you put the file in the destination folder.\n\nTry Again.\n\n";
			cout<<"Press Enter to proceed";
		}
		else
			break;
	}
	for (int i = 0; flag&&!fin.eof(); i++)
	{
		fin>>d.day;
		fin.ignore();
		fin>>d.month;
		fin.ignore();
		fin>>StartTime;
		fin.ignore();
		fin>>EndTime;
		fin.ignore();
		Cal [i].Duration = EndTime-StartTime;
		fin.getline(Cal [i].userid, 120, ',');
		fin.ignore(120, ',');
		fin.getline(Cal [i].title, 120, ',');
		fin>>Cal [i].priority;
		AddActivity(Calendar, Cal [i], d, StartTime);
	}
	delete[]Cal;
	Cal = nullptr;
	fin.close();
	if (flag)
		cout<<"Data from "<<File<<" has been read successfully\n";
	return Calendar;
}
void PrintCalendar(Activity *****&Calendar)
{
	for (int i = 0; i<months; i++)
	{
		Days = NumberOfDaysInMonth(i);
		for (int j = 0; j<Days; j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					cout<<j+1<<Suffixes(j)<<"\t"<<MonthName(i)<<"\t"<<Calendar [i][j][k][l]->title<<"\t"<<Calendar [i][j][k][l]->userid<<endl<<endl;
				}
			}
		}
	}
}
void ActivityOfUser(Activity *****&Calendar, char *userid, Date start_date, Date end_date)
{
	cout<<endl<<endl;
	int Activities = 0;
	start_date.month--; end_date.month--; start_date.day--; end_date.day--;
	for (int i = start_date.month; i<=end_date.month; i++)
	{
		Days = NumberOfDaysInMonth(i);
		for (int j = start_date.day; j<=end_date.day&&j<Days; j++)
		{
			for (int k = 0; k<24; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					if (strcmp(Calendar [i][j][k][l]->userid, userid)==0)
					{
						SetColour(15);
						cout<<j+1<<Suffixes(j)<<"\t"<<MonthName(i)<<"\t";
						if (strlen(MonthName(i))<8)
							cout<<"\t";
						SetColour(12);
						cout<<Calendar [i][j][k][l]->title<<"\t";
						SetColour(10);
						if (strlen(Calendar [i][j][k][l]->title)<16)
							cout<<"\t";
						cout<<Calendar [i][j][k][l]->Duration<<"\tHours"<<endl<<endl;
						Activities++;
					}
				}
			}
		}
	}
	if (Activities==0)
		cout<<"\nThere is no activity of "<<userid<<" from "<<start_date.day+1<<Suffixes(start_date.day)<<" "<<MonthName(start_date.month)<<" to "<<end_date.day+1<<Suffixes(end_date.day)<<" "<<MonthName(end_date.month)<<endl<<endl;
}
void MostImportantActivitiesOf(Activity*****&Calendar, char *userid, Date Start_date, Date End_Date)
{
	int count = 0;
	Priority *ImportantActivities = new Priority [50];
	for (int i = Start_date.month-1; i<End_Date.month; i++)
	{
		Days = NumberOfDaysInMonth(i);
		for (int j = Start_date.day-1; j<End_Date.day&&j<Days; j++)
		{
			for (int k = 0; k<24; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					if (strcmp(Calendar [i][j][k][l]->userid, userid)==0)
					{
						ImportantActivities [count].Prior = Calendar [i][j][k][l]->priority;
						ImportantActivities [count].Calendar = Calendar [i][j][k][l];
						ImportantActivities [count].d.day = j;
						ImportantActivities [count++].d.month = i;
					}
				}
			}
		}

	}
	for (int i = 0; i<=count; i++)
	{
		for (int j = i; j<=count; j++)
		{
			if (ImportantActivities [i].Prior<ImportantActivities [j].Prior)
				swap(ImportantActivities [i], ImportantActivities [j]);
		}
	}
	for (int i = 0; i<5&&i<count; i++)
	{
		SetColour(15);
		cout<<ImportantActivities [i].d.day+1<<Suffixes(ImportantActivities [i].d.day)<<"\t"<<MonthName(ImportantActivities [i].d.month)<<"\t";
		if (strlen(MonthName(ImportantActivities [i].d.month))<8)
			cout<<"\t";
		SetColour(12);
		cout<<ImportantActivities [i].Calendar->title<<"\t\t";
		SetColour(10);
		cout<<ImportantActivities [i].Calendar->priority<<endl<<endl;
	}
	delete[]ImportantActivities;
	ImportantActivities = nullptr;
	SetColour(12);
}
void LongestFreePeriod(Activity*****&Calendar, char *userid)
{
	bool flag = false;
	int Period = 0, max = 0;
	Date Start_Date, End_Date, StartDate, EndDate;
	Start_Date.day = 0;
	Start_Date.month = 0;
	End_Date.day = 0;
	End_Date.month = 0;
	for (int i = 0; i<months; i++)
	{
		Days = NumberOfDaysInMonth(i);
		for (int j = 0; j<NumberOfDaysInMonth(i); j++)
		{
			if (flag)
				Period++;
			else
			{
				if (Period>max)
				{
					max = Period;
					StartDate = Start_Date;
					EndDate = End_Date;
				}
				Period = 0;
			}
			flag = true;
			for (int k = 0; k<HoursInADay&&flag; k++)
			{
				for (int l = 0; l<Counter [i][j][k]&&flag; l++)
				{
					if (strcmp(Calendar [i][j][k][l]->userid, userid)==0)
					{
						Start_Date = End_Date;
						End_Date.month = i;
						End_Date.day = j;
						flag = false;
					}
				}
			}
		}
	}
	cout<<endl<<StartDate.day+1<<Suffixes(StartDate.day)<<" "<<MonthName(StartDate.month)<<endl<<EndDate.day+1<<Suffixes(EndDate.day)<<" "<<MonthName(EndDate.month)<<endl<<endl;
}
void UserClashes(Activity***** &Calendar, char* userid1, char* userid2, Date Start_Date, Date End_Date)
{
	Activity **ClashingActivities = new Activity* [365], *Activity1 = new Activity, *Activity2 = new Activity;
	for (int i = 0; i<365; i++)
		ClashingActivities [i] = new Activity [365];
	bool flag1 = false, flag2 = false;
	int time1 = 0, time2 = 0, count = 0, count2 = 0;
	Date *d1 = new Date [365], *d2 = new Date [365];//use to store the date for clashing activities
	for (int i = Start_Date.month-1; i<End_Date.month; i++)
	{
		Days = NumberOfDaysInMonth(i);
		for (int j = Start_Date.day; j<End_Date.day&&j<Days; j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					if (((strcmp(Calendar [i][j][k][l]->userid, userid1)==0)||flag1)||((strcmp(Calendar [i][j][k][l]->userid, userid2)==0)||flag2))
					{
						if (strcmp(Calendar [i][j][k][l]->userid, userid1)==0)
						{
							flag1 = true;
							time1 = k;
							Activity1 = Calendar [i][j][k][l];
						}
						if (strcmp(Calendar [i][j][k][l]->userid, userid2)==0)
						{
							flag2 = true;
							time2 = k;
							Activity2 = Calendar [i][j][k][l];
						}
						if (flag1&&k>time1+Calendar [i][j][k][l]->Duration)
						{
							flag1 = false;
							time1 = 0;
						}
						if (flag2&&k>time2+Calendar [i][j][k][l]->Duration)
						{
							flag2 = false;
							time2 = 0;
						}
						if (flag1&&flag2)
						{
							ClashingActivities [count] = Activity1;
							d1 [count].day = j;
							d1 [count++].month = i;
							ClashingActivities [count] = Activity2;
							d1 [count].day = j;
							d1 [count++].month = i;
							flag1 = false;
							flag2 = false;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i<count; i++)
		cout<<d1 [i].day+1<<Suffixes(d1 [i].day)<<"\t"<<MonthName(d1 [i].month+1)<<"\t"<<ClashingActivities [i]->title<<"\t"<<ClashingActivities [i]->Duration<<" Hours"<<"\t"<<ClashingActivities [i]->userid<<endl;

	delete[]ClashingActivities;
	ClashingActivities = nullptr;
	Activity1 = nullptr;
	Activity2 = nullptr;
	delete[]d1;
	d1 = nullptr;
	delete[]d2;
	d2 = nullptr;
}
void FreeSlotsForMeeting(Activity*****&Calendar, char **userid, Date StartDate, Date EndDate)
{
	int NumberOfUserids = 0, idnumber = 0;
	for (int i = 0; userid [i]!=NULL; i++)
		NumberOfUserids++;
	int* FreeSlots = new int [24];
	bool *flag = new bool [NumberOfUserids], FreeSlot = true, FreeHour = false;
	int Duration = 0;
	for (int i = StartDate.month-1; i<EndDate.month; i++)
	{
		for (int j = StartDate.day-1; j<EndDate.day&&j<NumberOfDaysInMonth(i); j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				FreeSlots [k] = 0;
				for (int l = 0; l<Counter [i][j][k];)
				{
					if (strcmp(Calendar [i][j][k][l]->userid, userid [idnumber])==0)
					{
						Duration = Calendar [i][j][k][l]->Duration;
						for (int m = 0; m<Duration; m++)
						{
							FreeSlots [k++] = -1;
						}
					}
					else
					{
						idnumber++;
						if (idnumber>=NumberOfUserids)
							l++;
					}
					idnumber %= NumberOfUserids;
				}
			}
			cout<<"On "<<MonthName(i)<<" "<<j+1<<" Free Hours are ";
			for (int k = 0; k<HoursInADay; k++)
			{
				if (FreeSlots [k]==0)
					cout<<k<<" ";
			}
			cout<<endl;
		}
	}
}
void PrintAMonthOfCalendar(int MonthNumber)
{
	int i = MonthNumber-1;
	int DayNumber = StartDayOfMonth(i+1);
	bool FreeDay = true, flag = false;
	int size = strlen(MonthName(i)), temp = 0;
	cout<<endl<<endl;
	SetColour(11);
	for (int j = 0; j<26-size/2; j++)
		cout<<"~";
	cout<<"  ";
	cout<<MonthName(i);
	cout<<"  ";
	for (int j = 0; j<26-size/2; j++)
		cout<<"~";
	if (i%2!=0)
		cout<<"~";
	SetColour(10);
	cout<<endl<<endl<<endl;
	cout<<"  ";
	for (int j = 1; j<8; j++)
	{
		if (j>5)
			SetColour(14);
		cout<<DayName(j)<<"     ";
	}
	SetColour(15);
	for (int j = 0; j<DayNumber+NumberOfDaysInMonth(i)-1||j%7!=0; FreeDay = true, j++)
	{
		if (j+1==DayNumber)
			flag = true;
		if (flag)
			temp++;
		if (j%7==0)
		{
			cout<<endl;
			for (int w = 0; w<57; w++)
			{
				cout<<"_";
			}
			cout<<endl<<endl;
			for (int w = 0; w<8; w++)
			{
				cout<<"|\t";
			}
			cout<<endl;
		}
		if (temp<=NumberOfDaysInMonth(i)&&temp!=0)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<Counter [i][temp-1][k]; l++)
				{
					FreeDay = false;
					if (!FreeDay)
						break;
				}
				if (!FreeDay)
					break;
			}
		}
		else
			FreeDay = false;
		if (j%7==0)
			cout<<"|   ";
		if (temp<=NumberOfDaysInMonth(i))
		{
			if (FreeDay)
				SetColour(14);
			if (temp!=0)
				cout<<temp;
			else
				cout<<" ";
		}
		else
			cout<<"  ";
		SetColour(15);
		if ((temp)/10==0)
			cout<<" ";
		cout<<"  |   ";
		if ((j+1)%7==0)
		{
			cout<<endl;
			for (int w = 0; w<8; w++)
			{
				cout<<"|\t";
			}
		}
	}
	cout<<endl;
	for (int w = 0; w<57; w++)
	{
		cout<<"_";
	}
	SetColour(12);
}
void ActivityStatsForAMonth(Activity*****& Calendar, int MonthNumber)
{
	int i = --MonthNumber, TotalActivitiesInAMonth = 0, BusiestDay = 0, ImportantDay = 0;
	Days = NumberOfDaysInMonth(i);
	int *NumberOfActivities = new int [Days];
	float *Priorities = new float [Days];
	for (int j = 0; j<Days; j++)
	{
		Priorities [j] = 0;
		NumberOfActivities [j] = 0;
		for (int k = 0; k<HoursInADay; k++)
		{
			for (int l = 0; l<Counter [i][j][k]; l++)
			{
				TotalActivitiesInAMonth++;
				NumberOfActivities [j]++;
				Priorities [j] += Calendar [i][j][k][l]->priority;
			}
		}
		Priorities [j] /= NumberOfActivities [j];
	}
	cout<<"There are "<<TotalActivitiesInAMonth<<" total activities in "<<MonthName(i)<<endl;
	cout<<"Average number of activities per day are "<<TotalActivitiesInAMonth/Days<<endl;
	int maxActivity = NumberOfActivities [0];
	float maxPriority = Priorities [0];
	for (int j = 0; j<Days; j++)
	{
		if (maxActivity<NumberOfActivities [j])
		{
			maxActivity = NumberOfActivities [j];
			BusiestDay = j;
		}
		if (maxPriority<Priorities [j])
		{
			maxPriority = Priorities [j];
			ImportantDay = j;
		}
	}
	cout<<"The busiest day of month is "<<BusiestDay+1<<Suffixes(BusiestDay)<<" "<<MonthName(i)<<endl;
	cout<<"The number of activities in a busiest day is "<<NumberOfActivities [BusiestDay]<<endl;
	cout<<"The day with highest average priority of the activities is "<<ImportantDay+1<<Suffixes(ImportantDay)<<" "<<MonthName(i)<<endl;
	cout<<"The number of activities in the most important day is "<<NumberOfActivities [ImportantDay]<<endl;
	delete[]NumberOfActivities;
	NumberOfActivities = nullptr;
}
void CalendarStatsForTheWholeYear(Activity*****& Calendar)
{
	int *NumberOfActivities = new int [months];
	for (int i = 0; i<months; i++)
	{
		NumberOfActivities [i] = 0;
		for (int j = 0; j<NumberOfDaysInMonth(i); j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					NumberOfActivities [i]++;
				}
			}
		}
	}
	int MaxActivityInAMonth = NumberOfActivities [0], BusiestMonth = 0;
	for (int i = 0; i<months; i++)
	{
		if (MaxActivityInAMonth<NumberOfActivities [i])
		{
			MaxActivityInAMonth = NumberOfActivities [i];
			BusiestMonth = i;
		}
	}
	cout<<"Total Number of Activities in a Calendar Year is "<<TotalActivitiesInACalendarYear<<endl;
	cout<<"Average number of Activities per month is "<<TotalActivitiesInACalendarYear/months<<endl;
	cout<<"The busiest month of the year is "<<MonthName(BusiestMonth)<<endl;
	cout<<"Number of Activities in a busiest month is "<<MaxActivityInAMonth<<endl;

	delete[]NumberOfActivities;
	NumberOfActivities = nullptr;
}
void SaveCalendar(Activity*****Calendar, char*File)
{
	ofstream fout;
	fout.open(File);
	int activitysaves = 0;
	for (int i = 0; i<months; i++)
	{
		Days = NumberOfDaysInMonth(i);
		for (int j = 0; j<Days; j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					if (activitysaves!=0)
						fout<<endl;
					fout<<j+1<<"/"<<i+1<<","<<k<<","<<k+Calendar [i][j][k][l]->Duration<<","<<Calendar [i][j][k][l]->userid<<","<<"act"<<++activitysaves<<","<<Calendar [i][j][k][l]->title<<","<<Calendar [i][j][k][l]->priority;
				}
			}
		}
	}
	fout.close();
	cout<<"\nCalendar has been saved to the file "<<File<<" successfully!\n";
}
void RemoveUser(Activity*****&Calendar, char*userid)
{
	for (int i = 0; i<months; i++)
	{
		Days = NumberOfDaysInMonth(i);
		for (int j = 0; j<Days; j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					if (strcmp(Calendar [i][j][k][l]->userid, userid)==0)
					{
						delete[]Calendar [i][j][k][l];
						for (int m = l; m+1<Counter [i][j][k]; m++)
						{
							Calendar [i][j][k][m] = Calendar [i][j][k][m+1];
						}
						Counter [i][j][k]--;
					}
				}
			}
		}
	}

}
void DeallocationOfACalendar(Activity*****&Calendar)
{
	for (int i = 0; i<months; i++)
	{
		for (int j = 0; j<NumberOfDaysInMonth(i); j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<Counter [i][j][k]; l++)
				{
					delete[]Calendar [i][j][k][l];
				}
				delete[]Calendar [i][j][k];
				Counter [i][j][k] = 0;
			}
			delete[]Calendar [i][j];
		}
		delete[]Calendar [i];
	}
	delete[]Calendar;
	Calendar = nullptr;
	cout<<"\n\nCalendar has been Deallocated successfully!\n\n";
}