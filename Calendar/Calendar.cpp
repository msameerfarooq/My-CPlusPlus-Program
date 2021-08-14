// Muhammad Sameer Farooq
// 18L-0986
// BS(CS)-A1

#include <iostream>
#include "Calendar.h"
using namespace std;
const int months = 12, HoursInADay = 24;
Activity *****Calendar;
int***counter = nullptr;
bool FindTheUserId(Activity*****Calendar, char* userid)
{
	for (int i = 0; i<months; i++)
	{
		for (int j = 0; j<NumberOfDaysInMonth(i); j++)
		{
			for (int k = 0; k<HoursInADay; k++)
			{
				for (int l = 0; l<counter [i][j][k]; l++)
				{
					if (strcmp(Calendar [i][j][k][l]->userid, userid)==0)
						return true;
				}
			}
		}
	}
	return false;
}
void OrderDate(Date &d1, Date &d2)
{
	if (d1.month>d2.month)
		swap(d1, d2);
	else if ((d1.month==d2.month)&&(d1.day>d2.day))
		swap(d1, d2);
}
char* InputUserId()
{
	char* userid = new char [120];
	cin.ignore();
	while (true)
	{
		cout<<"Input the userid of user : ";
		//cin.clear();
		cin.getline(userid, 120);
		if (FindTheUserId(Calendar, userid)||strcmp(userid, "0")==0||strcmp(userid, "-1")==0)
			break;
		cout<<"The userid you input doesn't exist.Try Again\n";
		cout<<"Press Enter to continue\n";
		cin.ignore();
		cin.clear();
	}
	return userid;
}
int InputDate(char datename [120], int month)
{
	int day;
	while (true)
	{
		cout<<"Input the "<<datename<<"Date : ";
		cin>>day;
		if (cin)
		{
			if (day>=0&&day<=NumberOfDaysInMonth(month-1))
				break;
		}
		cout<<"Input the valid "<<datename<<"Date.Try Again\n";
		cin.clear();
		cin.ignore(120, '\n');
	}
	return day;
}
int InputMonth(char datename [120])
{
	int month = 0;
	while (true)
	{
		cout<<"Input the "<<datename<<"Month number : ";
		cin>>month;
		if (cin)
		{
			if (month>=0&&month<13)
				break;
		}
		cout<<"Input the valid month number.Try Again\n";
		cin.clear();
		cin.ignore(120, '\n');
	}
	return month;
}
void MenuOptions()
{
	SetColour(15);
	system("CLS");
	cout<<"This Calendar Program is written by ";
	SetColour(10);
	cout<<"Muhammad Sameer Farooq";
	SetColour(15);
	cout<<" verion 1.0\n\n"
		<<"0-->Exit this console application\n"
		<<"1-->Read the data from File\n"
		<<"2-->List all the activities of a user during a time period\n"
		<<"3-->List the 5 most important activities of a user\n"
		<<"4-->Longest free period of user\n"
		<<"5-->List all the clashing activities of a pair of users\n"
		<<"6-->list all hourly slots that are free for all entered users\n"
		<<"7-->Print Activity stats for a month\n"
		<<"8-->Print Calendar stats for the whole year\n"
		<<"9-->Remove a user from the Calendar\n"
		<<"10-->Save the Calendar\n"
		<<"11-->Print a month of the Calendar\n";
}
void Menu()
{
	char* starttime = new char [120];
	char* endtime = new char [120];
	char* FileName = new char [120];
	char* userid1 = new char [120];
	char* userid2 = new char [120];
	starttime = "Starting ";
	endtime = "Ending ";
	int choice = 0;
	while (1)
	{
		Date d1, d2;
		MenuOptions();
		cout<<"\n\n\nInput your choice : ";
		cin>>choice;
		system("CLS");
		cout<<"Input 0 to go back\n";
		SetColour(12);
		if (choice==1)
		{
			Calendar = InputFromFile(Calendar);
		}
		else if (choice==2)
		{
			userid1 = InputUserId();
			if (strcmp(userid1, "0")!=0)
			{

				d1.month = InputMonth(starttime);
				if (d1.month!=0)
				{
					d1.day = InputDate(starttime, d1.month);
					if (d1.day!=0)
					{
						d2.month = InputMonth(endtime);
						if (d2.month!=0)
						{
							d2.day = InputDate(endtime, d2.month);
							if (d2.day!=0)
							{
								OrderDate(d1, d2);
								ActivityOfUser(Calendar, userid1, d1, d2);
							}
						}
					}
				}
			}
		}
		else if (choice==3)
		{
			userid1 = InputUserId();
			if (strcmp(userid1, "0")!=0)
			{
				d1.month = InputMonth(starttime);
				if (d1.month!=0)
				{
					d1.day = InputDate(starttime, d1.month);
					if (d1.day!=0)
					{
						d2.month = InputMonth(endtime);
						if (d2.month!=0)
						{
							d2.day = InputDate(endtime, d2.month);
							if (d2.day!=0)
							{
								OrderDate(d1, d2);
								MostImportantActivitiesOf(Calendar, userid1, d1, d2);
							}
						}
					}
				}
			}
		}
		else if (choice==4)
		{
			userid1 = InputUserId();
			if (strcmp(userid1, "0")!=0)
			{
				LongestFreePeriod(Calendar, userid1);
			}
		}
		else if (choice==5)
		{
			cout<<"\nFor first user\n";
			userid1 = InputUserId();
			if (strcmp(userid1, "0")!=0)
			{
				cin.clear();
				cout<<"\nFor second user\n";
				userid2 = InputUserId();
				if (strcmp(userid2, "0")!=0)
				{
					d1.month = InputMonth(starttime);
					if (d1.month!=0)
					{
						d1.day = InputDate(starttime, d1.month);
						if (d1.day!=0)
						{
							d2.month = InputMonth(endtime);
							if (d2.month!=0)
							{
								d2.day = InputDate(endtime, d2.month);
								if (d2.day!=0)
								{
									OrderDate(d1, d2);
									UserClashes(Calendar, userid1, userid2, d1, d2);
								}
							}
						}
					}
				}
			}
		}
		else if (choice==6)
		{
			int k = 0;
			char **userid = new char * [120];
			for (k = 0; k<120; k++)
				userid [k] = {};
			for (k = 0; k<120; k++)
			{
				userid [k] = InputUserId();
				if ((strcmp(userid [k], "-1")==0)||(strcmp(userid [k], "0")==0))
					break;
			}
			if (strcmp(userid [k], "0")!=0)
			{
				userid [k] = {};
				d1.month = InputMonth(starttime);
				if (d1.month!=0)
				{
					d1.day = InputDate(starttime, d1.month);
					if (d1.day!=0)
					{
						d2.month = InputMonth(endtime);
						if (d2.month!=0)
						{
							d2.day = InputDate(endtime, d2.month);
							if (d2.day!=0)
							{
								OrderDate(d1, d2);
								FreeSlotsForMeeting(Calendar, userid, d1, d2);
							}
						}
					}
				}
			}
		}
		else if (choice==7)
		{
			d1.month = InputMonth("");
			if (d1.month!=0)
			{
				ActivityStatsForAMonth(Calendar, d1.month);
			}
		}
		else if (choice==8)
		{
			CalendarStatsForTheWholeYear(Calendar);
		}
		else if (choice==9)
		{
			userid1 = InputUserId();
			if (strcmp(userid1, "0")==0)
			{
				RemoveUser(Calendar, userid1);
			}
		}
		else if (choice==10)
		{
			int i = 0;
			char*FileType = new char [5];
			cin.ignore();
			cout<<"\nInput the File Name : ";
			cin.getline(FileName, 120);
			if (strcmp(FileName, "0")!=0)
			{
				cout<<"\nInput the File Type : ";
				cin.getline(FileType, 120);
				if (strcmp(FileType, "0")!=0)
				{
					int size1 = strlen(FileName), size2 = strlen(FileType);
					for (i = size1; i<size1+size2; i++)
						FileName [i] = FileType [i-size1];
					FileName [i] = '\0';
					SaveCalendar(Calendar, FileName);
				}
			}
		}
		else if (choice==11)
		{
			int MonthNumber = InputMonth("");
			if (MonthNumber!=0)
				PrintAMonthOfCalendar(MonthNumber);
		}
		else if (choice==12)
		{
			DeallocationOfACalendar(Calendar);
		}
		else if (choice==0)
		{
			for (int i = 0; i<months; i++)
			{
				for (int j = 0; j<NumberOfDaysInMonth(i); j++)
				{
					delete[]counter [i][j];
				}
				delete[]counter [i];
			}

			delete[]counter;
			counter = nullptr;
			delete[]FileName;
			FileName = nullptr;
			//	delete[]starttime
			//  we cannot delete starttime because starttime is hardcoded in the program
			starttime = nullptr;
			//	delete[]endtime
			//  we cannot delete endtime because endtime is hardcoded in the program
			endtime = nullptr;
			delete[]userid1;
			userid1 = nullptr;
			delete[]userid2;
			userid2 = nullptr;
			break;
		}
		else
		{
			cout<<"Invalid Choice.Try Again";
			cin.clear();
			cin.ignore(120, '\n');
			continue;
		}
		cout<<endl;
		system("pause");
	}
}
int main()
{
	SetColour(15);
	Calendar = AllocationOfCalendar();
	ReturnCounter(counter);
	Menu();

	////PrintCalendar(Calendar);
	//Date d1, d2;
	//d1.day = 0;
	//d1.month = 0;
	//d2.day = 31;
	//d2.month = 11;
	//char **userid = new char * [120];
	//for (int k = 0; k<120; k++)
	//	userid [k] = {};
	//userid [0] = "user84";
	//userid [1] = "user86";
	//userid [2] = "user68";
	////sizeof(userid)/sizeof(userid [0]), idnumber = 0;
	//FreeSlotsForMeeting(Calendar, userid, d1, d2);
	///*(Calendar, "user30", d1, d2);
	//(Calendar, "user71");
	//UserClashes(Calendar, user30, user29, d1, d2);
	//ActivityStatsForAMonth(Calendar, 6);
	//CalendarStatsForTheWholeYear(Calendar);

	//UserClashes(Calendar, "user92", "user84", d1, d2);
	//RemoveUser(Calendar, "user29");
	//SaveCalendar(Calendar, "Calendar3.txt");/
	//DeallocationOfACalendar(Calendar); */


	system("pause");
	return 0;
}