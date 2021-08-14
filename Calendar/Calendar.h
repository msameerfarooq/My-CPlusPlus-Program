struct Date
{
	int day;
	int month;
};
struct Activity
{
	int Duration = 0;
	char userid [120];
	char title [120];
	float priority;
};
struct Priority
{
	float Prior;
	Activity *Calendar;
	Date d;
};
int NumberOfDaysInMonth(int i);
char* MonthName(int i);
void SetColour(int i);
void ReturnCounter(int***&Counter);
Activity***** AllocationOfCalendar();
Activity***** InputFromFile(Activity *****Calendar);
void PrintCalendar(Activity *****&Calendar);
void ActivityOfUser(Activity *****&Calendar, char *userid, Date start_date, Date end_date);
void MostImportantActivitiesOf(Activity*****&Calendar, char *userid, Date Start_date, Date End_Date);
void LongestFreePeriod(Activity*****&Calendar, char *userid);
void UserClashes(Activity***** &Calendar, char* userid1, char* userid2, Date Start_Date, Date End_Date);
void FreeSlotsForMeeting(Activity*****&Calendar, char **userid, Date StartDate, Date EndDate);
void PrintAMonthOfCalendar(int MonthNumber);
void ActivityStatsForAMonth(Activity*****& Calendar, int MonthNumber);
void CalendarStatsForTheWholeYear(Activity*****& Calendar);
void SaveCalendar(Activity*****Calendar, char*File);
void RemoveUser(Activity*****&Calendar, char*userid);
void DeallocationOfACalendar(Activity*****&Calendar);