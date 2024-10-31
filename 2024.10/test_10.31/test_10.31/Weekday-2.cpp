// #include "stdafx.h"
#include <iostream>

using namespace std;

bool IsCorrect(int y, int m, int d);

int getResult(int y, int m, int d);

int maxA[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int year, month, day;
	while (1)
	{
		cout << "����������(yy/mm/dd)��";
		cin >> year;
		cin.ignore(1, '/');
		cin >> month;
		cin.ignore(1, '/');
		cin >> day;
		bool valid = IsCorrect(year, month, day);
		while (!valid)
		{
			cout << "�����������������(yy/mm/dd):";
			cin >> year;
			cin.ignore(1, '/');
			cin >> month;
			cin.ignore(1, '/');
			cin >> day;
			valid = IsCorrect(year, month, day);
		}
		maxA[1] = 28;
		int result = getResult(year, month, day);
		cout << year << "��" << month << "��" << day << "��������";
		switch (result)
		{
		case 0:
			cout << "һ!\n";
			break;
		case 1:
			cout << "��!\n";
			break;
		case 2:
			cout << "��!\n";
			break;
		case 3:
			cout << "��!\n";
			break;
		case 4:
			cout << "��!\n";
			break;
		case 5:
			cout << "��!\n";
			break;
		case 6:
			cout << "��!\n";
			break;
		default:
			cout << "������ִ���!\n";
			break;
		}
		cout << endl << endl;
	}

	return 0;
}
bool IsCorrect(int y, int m, int d)                                
{                                                                  // 1
	if (y < 1)                                                     // 2
		return false;                                              // 3
	else
	{
		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))    // 4
			maxA[1] = 29;                                          // 5
		if (m < 0 || m > 12)                                       // 6
			return false;                                          // 7
		else
		{
			if (d > maxA[m - 1])                                   // 8
				return false;                                      // 9
			else
				return true;                                       // 10
		}
	}
}                                                                  // 11
int getResult(int y, int m, int d)
{																 // 1
	long totalDays = 0;                                          // 2
	for (int i = 1; i < y; i++)                                  // 3
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))  
			totalDays += 366;                                    
		else
			totalDays += 365;                                    
	}
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))      // 4
		maxA[1] = 29;                                            // 5
	else
		maxA[1] = 28;                                            // 6
	for (int i = 1; i < m; i++)                                  // 7
	{
		totalDays += maxA[i - 1];                                 
	}
	totalDays += (d - 1);                                        // 8
	maxA[1] = 28;                                                // 9
	return (totalDays % 7);                                      // 10
}

