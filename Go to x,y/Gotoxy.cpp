#include <iostream>
#include <windows.h>
using namespace std;

//void gotoxy(int xpos, int ypos, int col, char ch)
//{
//	COORD scrn;
//	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
//	scrn.X = xpos; scrn.Y = ypos;
//	SetConsoleCursorPosition(hOuput, scrn);
//	HANDLE  screen = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(screen, col);
//	DWORD useless;
//	WriteConsole(screen, &ch, 1, (LPDWORD) &useless, NULL);
//	SetConsoleTextAttribute(screen, 15);
//	SMALL_RECT windowSize = { 0, 0, 100, 100 };
//	SetConsoleWindowInfo(screen, TRUE, &windowSize);
//}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int k = 1; k < 255; k++)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout<<k<<" I want to be nice today!"<<endl;
	}
	system("pause");
	return 0;
}