// importing some library that we can you for our program
#include <iostream> // for using cout, cin and other input Output functions...
#include <iomanip> // for manipulation of the console for example:- cout << setfill('-') << setw(72) << ' '; will fill the line with -(dashes) x72
#include <stdlib.h> // the stdlib or the standard library is for using the exit(0) for exiting out of the program and the system() function for using system commands like color a.....
#include <stdio.h> // the stdlib or the standard input output is just like iostream but C programmer use this library most of the time but we need printf() function for our program
#include <windows.h> // For setting the color on texts
#include <conio.h> // for using the function getch()
#include <ctype.h> // for checking if the entered year is number or not

using namespace std;


// Defining two CONSTANTS identifiers CHAR_FILL for filling the table row and EMPTY_FILL for resetting setfill to empty char fill
#define CHAR_FILL '-'
#define EMPTY_FILL ' '



/*************************************Declaring global identifers******************************/
const int ZEMENBLUE = 5500;


/*******************/
// for counting gDay
int greDay = 11;
int gNumDays;
// month for counting month
int month = 1;
/*******************/
/*********************************************************************************************/

/****************main function********************/
int main(void)
{
	// Declaring local identifers
	int year, ameteAlem, leapYear, ethNDays, startDay, numDays, gLeapYear;
	int fStartDay, greYear, tempYear = 0;;
	// the char identifyer is for asking if the using wants to enter a year again
	char ask;
	// console identifyer is for getting the console the output handle
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	// this memeory constants is for the color usage
	const int color_red = 12, color_white = 15, color_blue = 1, 
			  color_green = 2, color_yellow = 14, color_green_b = 100;

	// Setting the text color to white
	SetConsoleTextAttribute(console, color_white);
	// The program rans at least one time.
	do
	{
		// prompt the user and get the value
		cout << "Enter a year: ";
		cin >> year;
		///scanf("%d ", &year);
	  
	  	// Check the year value if it is a -ve value if it is the program will display an error and exit out
	  	// of the running program
		if (year<0)
		{
			// This part is for changing the color of the outputed text to red
			SetConsoleTextAttribute(console, color_red);
			cout << "\n invalid year!!! -- Can't be a negative number ";
			// After printing the text is will reset the rest of the greDay to color_white
			SetConsoleTextAttribute(console, color_white);
			// And exit out of the program
			exit(0);
		}
		

		// Adding + 7 to the given year if the ethiopian month is less than 3
		if (month < 3)
			tempYear = year+7;
		else
			// else + 8
			tempYear = year + 8;

		/*Get Start Day*/
		if (tempYear % 4 != 0)
			greDay = 12;
		else
			greDay = 11;
		/**************/


		/* REST */
		month = 1;
		/*******/

		ameteAlem = ZEMENBLUE + year;

		// Calculate leapYear
		leapYear = ((ameteAlem + 1) % 4 == 0);

		// Calculate number of ethiopian days;
		ethNDays = (ameteAlem - 1) * 365 + (ameteAlem - 1) / 4;
		if ((ameteAlem-1) % 4 == 3)
			ethNDays += 1;
		ethNDays += 1;
		startDay = ethNDays % 7;
		if (startDay == 6)
			startDay = 0;
		else
			startDay++;
		/*if (startDay == 6)
		{
			startDay -= 6;
		}*/

		//cout << endl << startDay << endl;
		//system("PAUSE");
		// Getting the starting day of the year
		//if (startDay != 6)
		//	startDay = startDay + 1;
		//else
		//	startDay = startDay - 4;
		//cout << endl << startDay << endl;
		//system("PAUSE");

		/*Year Output*/
		int yearName = ((year - 7) % 4);

		// checking and outputing the year name by it's remindar
		switch (yearName)
		{
			case 0:
				// Checking the year type and setting all the year with diffrent color and outputing it
				SetConsoleTextAttribute(console, color_red);
				cout << endl << "Yohaness" << endl;
				SetConsoleTextAttribute(console, color_white);
				break;
			case 1:
				SetConsoleTextAttribute(console, color_yellow);
				cout << endl << "Matewos" << endl;
				SetConsoleTextAttribute(console, color_white);
				break;
			case 2:
				SetConsoleTextAttribute(console, color_green);
				cout << endl << "Mareqos" << endl;
				SetConsoleTextAttribute(console, color_white);
				break;
			default:
				SetConsoleTextAttribute(console, color_blue);
				cout << endl << "Loqas" << endl;
				SetConsoleTextAttribute(console, color_white);
				break;
		}


		// Starting of the main month loop of the ethipian calendar
		while (month <= 13)
		{
	
			//int gFirstDay = (tempYear + (tempYear - 1) / 4 - (tempYear - 1) / 100 + (tempYear - 1) / 400) % 7;
			gLeapYear = ((tempYear % 400 == 0) || (tempYear % 100 == 0) || (tempYear % 4 == 0));

			if (month < 3)
				tempYear = year+7;
			else
				tempYear = year + 8;

			/*Get Start Day*/
			//if (tempYear % 4 != 0)
			//	greDay = 12;
			//else
			//	greDay = 11;
			/**************/
			//cout << fStartDay;
			//exit(0);

			/**********************************************************************************************************************/
			// this part is for outputing the name of the month and setting the ethipian numbers of day
			// and the gre number of day
			switch (month)
			{
				case 1:
					SetConsoleTextAttribute(console, 1);
					cout << "\nMeskerm/" << year << "\t\t\t\t\t\tSep/Oct " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 30;
					break;
				case 2:
					SetConsoleTextAttribute(console, 2);
					cout << "\nTikimt/" << year << "\t\t\t\t\t\tOct/Nov " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 31;
					break;
				case 3:
					SetConsoleTextAttribute(console, 3);
					cout << "\nHidar/" << year << "\t\t\t\t\t\tNov/Dec " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 30;
					break;
				case 4:
					SetConsoleTextAttribute(console, 4);
					cout << "\nTasas/" << year << "\t\t\t\t\t\tDec/Jan " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 31;
					break;
				case 5:
					SetConsoleTextAttribute(console, 5);
					cout << "\nTir/" << year << "\t\t\t\t\t\tJan/Feb " << tempYear << endl;
					SetConsoleTextAttribute(console,  color_white);
					numDays = 30;
					gNumDays = 31;
					break;
				case 6:
					SetConsoleTextAttribute(console, 6);
					cout << "\nYekatit/" << year << "\t\t\t\t\t\tFeb/Mar " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 28 + gLeapYear; 
					break;
				case 7:
					SetConsoleTextAttribute(console, 7);
					cout << "\nMegabit/" << year << "\t\t\t\t\t\tMar/Apr " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 31;
					break;
				case 8:
					SetConsoleTextAttribute(console, 8);
					cout << "\nMiyaziya/" << year << "\t\t\t\t\t\tApr/May " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 30;
					break;
				case 9:
					SetConsoleTextAttribute(console, 9);
					cout << "\nGenbot/" << year << "\t\t\t\t\t\tMay/Jun " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 31;
					break;
				case 10:
					SetConsoleTextAttribute(console, 10);
					cout << "\nSene/" << year << "\t\t\t\t\t\tJun/Jul " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 30;
					break;
				case 11:
					SetConsoleTextAttribute(console, 11);
					cout << "\nHamle/" << year << "\t\t\t\t\t\tJul/Aug " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 31;
					break;
				case 12:
					SetConsoleTextAttribute(console, 12);
					cout << "\nNehase/" << year << "\t\t\t\t\t\tAug/Sep " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 30;
					gNumDays = 31;
					break;
				case 13:
					SetConsoleTextAttribute(console, 13);
					cout << "\nPagume/" << year << "\t\t\t\t\t\tSep " << tempYear << endl;
					SetConsoleTextAttribute(console, color_white);
					numDays = 5 + leapYear;
					break;
				default:
					// Optional
					SetConsoleTextAttribute(console, 233);
					cout << "\n End" << endl;
					SetConsoleTextAttribute(console, color_white);
					break;
			}
			/***********************************************************************************************************************************************/
			// printting the table header for every month
			//printHeader();
			cout << setfill(CHAR_FILL) << setw(72) << ' ' << endl;
			SetConsoleTextAttribute(console, 27);
			cout << '|' <<  "   EHU   ";
			SetConsoleTextAttribute(console, color_white);
			SetConsoleTextAttribute(console, 47);
			cout  << '|' << "   SEG   ";
			SetConsoleTextAttribute(console, color_white);
			SetConsoleTextAttribute(console, 57);
			cout << '|' << "   MAK   ";
			SetConsoleTextAttribute(console, color_white);
			SetConsoleTextAttribute(console, 67);
			cout  << '|' << "   REB   ";
			SetConsoleTextAttribute(console, color_white);
			SetConsoleTextAttribute(console, 87);
			cout << '|' << "   HAM   ";
			SetConsoleTextAttribute(console, 98);
			cout  << '|' << "   ARB   ";
			SetConsoleTextAttribute(console, color_white);
			SetConsoleTextAttribute(console, 19);
			cout  << '|' << "   QID   " << '|' << endl;
			SetConsoleTextAttribute(console, color_white);
			cout << setw(72) << ' ' << endl;
			// declaring day var for printing 7 days in a table row
			int day=1;
			// this part is for printing an empty cell
			//printEmptyCell(startDay);
			//if (startDay != 6 && startDay <= 4)
			//	startDay += 2;
			for (int s = 1; s<=startDay; s++)
				cout << setfill(EMPTY_FILL) << '|' << setw(10);
			int shift = startDay;
			// This is for shift the cell one time in a table
			int swth = 1;
			int swth_color = 1;
			/*************************************************************************************************************************/
			// this loop is for printing the day in the table
			while (day <= numDays)
			{
				// printing the day in printDay function with day, 1 passed as an argument day is the day to print and 1 is the position
				// if pos is == 1 the day will be printed to the right else to the left
				//printDay(day, 1);
				if (startDay == 0)
				{
					//SetConsoleTextAttribute(console, color_red);
					cout << setfill(EMPTY_FILL) << '|';
					if (month == 1 && day == 1 || month == 1 && day == 17)
					{
						SetConsoleTextAttribute(console, color_green_b);
					}
					else if (month == 3 && day == 28)
					{
						SetConsoleTextAttribute(console, color_green_b);
					}
					else if (month == 4 && day == 11)
					{
						SetConsoleTextAttribute(console, color_green_b);
					}
					else if (month == 5 && day == 12)
					{
						SetConsoleTextAttribute(console, color_green_b);
					}
					else if (month == 7 && day == 23 || month == 7 && day == 27)
					{
						SetConsoleTextAttribute(console, color_green_b);
					}
					else
					{
						SetConsoleTextAttribute(console, color_red);
					}
					cout  << setw(9) << right << day;
					SetConsoleTextAttribute(console, color_white);
				}
				else
				{
					// this part is for checking the holidays and and changing the text color and the background
					// color of the selected holiday
					if (month == 1 && day == 1 || month == 1 && day == 17)
					{
						cout << setfill(EMPTY_FILL) << '|';
						// chaning only the selected color
						SetConsoleTextAttribute(console, color_green_b);
						cout << setw(9) << right << day;
						SetConsoleTextAttribute(console, color_white);
					}
					else if (month == 3 && day == 28)
					{
						cout << setfill(EMPTY_FILL) << '|';
						SetConsoleTextAttribute(console, color_green_b);
						cout << setw(9) << right << day;
						SetConsoleTextAttribute(console, color_white);
					}
					else if (month == 4 && day == 11)
					{
						cout << setfill(EMPTY_FILL) << '|';
						SetConsoleTextAttribute(console, color_green_b);
						cout << setw(9) << right << day;
						SetConsoleTextAttribute(console, color_white);
					}
					else if (month == 5 && day == 12)
					{
						cout << setfill(EMPTY_FILL) << '|';
						SetConsoleTextAttribute(console, color_green_b);
						cout << setw(9) << right << day;
						SetConsoleTextAttribute(console, color_white);
					}
					else if (month == 7 && day == 23 || month == 7 && day == 27)
					{
						cout << setfill(EMPTY_FILL) << '|';
						SetConsoleTextAttribute(console, color_green_b);
						cout << setw(9) << right << day;
						SetConsoleTextAttribute(console, color_white);
					}
					else
						cout << setfill(EMPTY_FILL) << '|' << setw(9) << right << day;
				}
				// check if the startday is equal to 6
				if (startDay == 6)
				{
					// if it is the table row will be closed and starting printing the gregorinan day
					cout << '|';
					cout << endl << '|';

					//if (greDay > 9)
					//	greDay = 1;

					if (swth == 1)
					{
						//printGreDay(shift-1, 0);
						int cell = 0;
						switch (month)
						{
							case 1:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 2:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 3:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 4:
							case 5:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 6:
								if (greDay >= 28)
									greDay = 1;
								break;
							case 7:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 8:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 9:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 10:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 11:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 12:
								if (greDay >= 31)
									greDay = 1;
								break;
							default:
								//cout << "End";
								break;

						}
						if (shift)
						{
							for (int s = 0; s<=shift-1; s++)
								printf("         |");
							if (greDay/10 == 0)
							{
								for (int i=0; i<=5-(shift-1); i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d        |", greDay);
									greDay += 1;
								}
							} else
							{
								for (int i=0; i<=5-(shift-1); i++)
								{
									if (greDay > gNumDays)
										greDay =1;
									printf("%d       |", greDay);
									greDay += 1;
								}
							}
						} else if (cell)
						{
							if (greDay/10 == 0)
							{
								for (int i=0; i<=0-1; i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d        |", greDay);
									greDay += 1;
								}
							} else
							{
								for (int i=0; i<=0-1; i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d       |", greDay);
									greDay += 1;
								}
							}
						}	else
						{
							if (greDay/10 == 0)
							{
								for (int i=0; i<=6; i++)
								{
									if (greDay > gNumDays)
										greDay =1;
									printf("%d        |", greDay);
									greDay += 1;
								}
							}
							else 
							{
								for (int i=0; i<=6; i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d       |", greDay);
									greDay += 1;
								}
							}
						} // end
						//greDay++;
						swth = 0;
					} else 
					{
						//printGreDay(0, 0);
						switch (month)
						{
							case 1:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 2:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 3:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 4:
							case 5:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 6:
								if (greDay >= 28)
									greDay = 1;
								break;
							case 7:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 8:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 9:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 10:
								if (greDay >= 30)
									greDay = 1;
								break;
							case 11:
								if (greDay >= 31)
									greDay = 1;
								break;
							case 12:
								if (greDay >= 31)
									greDay = 1;
								break;
							default:
								//cout << "End";
								break;

						}
						if (0)
						{
							for (int s = 0; s<=0; s++)
								printf("         |");
							if (greDay/10 == 0)
							{
								for (int i=0; i<=5-0; i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d        |", greDay);
									greDay += 1;
								}
							} else
							{
								for (int i=0; i<=5-0; i++)
								{
									if (greDay > gNumDays)
										greDay =1;
									printf("%d       |", greDay);
									greDay += 1;
								}
							}
						} else if (0)
						{
							if (greDay/10 == 0)
							{
								for (int i=0; i<=0-1; i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d        |", greDay);
									greDay += 1;
								}
							} else
							{
								for (int i=0; i<=0-1; i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d       |", greDay);
									greDay += 1;
								}
							}
						}	else
						{
							if (greDay/10 == 0)
							{
								for (int i=0; i<=6; i++)
								{
									if (greDay > gNumDays)
										greDay =1;
									printf("%d        |", greDay);
									greDay += 1;
								}
							}
							else 
							{
								for (int i=0; i<=6; i++)
								{
									if (greDay > gNumDays)
										greDay = 1;
									printf("%d       |", greDay);
									greDay += 1;
								}
							}
						}
						//greDay++;
					}
					cout << endl << '|' << setfill(CHAR_FILL) << setw(71) << ' ';
					cout << endl;
					startDay = 0;
				}
				else 
				{
					startDay = startDay + 1;
				}
				day = day + 1;
			}
			/*************************************************************************************************************************/

			//if (greDay > 9)
			//	greDay = 1;

			if (month != 3 && month != 10)
			{
				cout << '|';
				cout << endl << '|';
				//printGreDay(0, startDay);
				shift = 0;
				int cell = startDay;
				switch (month)
				{
					case 1:
						if (greDay >= 30)
							greDay = 1;
						break;
					case 2:
						if (greDay >= 31)
							greDay = 1;
						break;
					case 3:
						if (greDay >= 30)
							greDay = 1;
						break;
					case 4:
					case 5:
						if (greDay >= 31)
							greDay = 1;
						break;
					case 6:
						if (greDay >= 28)
							greDay = 1;
						break;
					case 7:
						if (greDay >= 31)
							greDay = 1;
						break;
					case 8:
						if (greDay >= 30)
							greDay = 1;
						break;
					case 9:
						if (greDay >= 31)
							greDay = 1;
						break;
					case 10:
						if (greDay >= 30)
							greDay = 1;
						break;
					case 11:
						if (greDay >= 31)
							greDay = 1;
						break;
					case 12:
						if (greDay >= 31)
							greDay = 1;
						break;
					default:
						//cout << "End";
						break;

				}
				if (shift)
				{
					for (int s = 0; s<=shift-1; s++)
						printf("         |");
					if (greDay/10 == 0)
					{
						for (int i=0; i<=5-shift; i++)
						{
							if (greDay > gNumDays)
								greDay = 1;
							printf("%d        |", greDay);
							greDay += 1;
						}
					} else
					{
						for (int i=0; i<=5-shift; i++)
						{
							if (greDay > gNumDays)
								greDay =1;
							printf("%d       |", greDay);
							greDay += 1;
						}
					}
				} else if (cell)
				{
					if (greDay/10 == 0)
					{
						for (int i=0; i<=cell-1; i++)
						{
							if (greDay > gNumDays)
								greDay = 1;
							printf("%d       |", greDay);
							greDay += 1;
						}
					} else
					{
						for (int i=0; i<=cell-1; i++)
						{
							if (greDay > gNumDays)
								greDay = 1;
							printf("%d       |", greDay);
							greDay += 1;
						}
					}
				}	else
				{
					if (greDay/10 == 0)
					{
						for (int i=0; i<=6; i++)
						{
							if (greDay > gNumDays)
								greDay =1;
							printf("%d        |", greDay);
							greDay += 1;
						}
					}
					else 
					{
						for (int i=0; i<=6; i++)
						{
							if (greDay > gNumDays)
								greDay = 1;
							printf("%d       |", greDay);
							greDay += 1;
						}
					}
				}
				//greDay++;
				cout << endl << '|' << setfill(CHAR_FILL) << setw(71) << ' ';
				cout << endl;
			}

			//cout << '|' << endl << setfill(CHAR_FILL) << setw(72) << ' ';
			cout << endl << endl << endl;

			/*************************************************************************************************************************/
			// this part is for printing the Holydays if we wants to add more holydays we can create more switch case 
			// based on the given month
			switch (month)
			{
				case 1:
					SetConsoleTextAttribute(console, 2 /* 2 is for green */);
					cout << endl << " 1 Ethiopian New Year \n";
					SetConsoleTextAttribute(console, color_white);
					SetConsoleTextAttribute(console, 2 /* 2 is for green */);
					cout << endl << " 17 Mekel \n";
					SetConsoleTextAttribute(console, color_white);
					break;
				case 2:
					cout << endl << " Thanksgiving (4th Thursday of November) \n";
					cout << endl << " Halloween \n";
					cout << endl << " Diwali \n";
					break;
				case 3:
					if (((year + 1) % 4 == 0) && ((((year + 1) % 100) !=0) || ((year + 1) % 400 == 0)))
					{
						SetConsoleTextAttribute(console, 2 /* 2 is for green */);
						cout << endl << " 28 Gena \n";
						SetConsoleTextAttribute(console, color_white);
					}
					else
					{
						SetConsoleTextAttribute(console, 2 /* 2 is for green */);
						cout << endl << " 29 Gena \n";
						SetConsoleTextAttribute(console, color_white);
					}
					break;
				case 4:
					SetConsoleTextAttribute(console, 2 /* 2 is for green */);
					cout << endl << " 11 Timket \n ";
					SetConsoleTextAttribute(console, color_white);
					cout << endl << " End of Chinese new year \n";
					cout << endl << " Christmas \n";
					cout << endl << " New Year \n";
					break;
				case 5:
					SetConsoleTextAttribute(console, 2 /* 2 is for green */);
					cout << endl << " 12 Adwa Dil Beal \n";
					SetConsoleTextAttribute(console, color_white);
					cout << endl << " Basanta (India spring holiday) \n";
					cout << endl << " Valentine's Day (Feb 14) \n";
					break;
				case 6:
					cout << endl << " Basanta (India spring holiday) \n";
					cout << endl << " Women's day \n";
					break;
				case 7:
					cout << endl << " Easter (March equinox) \n";
					cout << endl << " Start of Chinese New Year \n";
					cout << endl << " April's fool day \n";
					SetConsoleTextAttribute(console, 2 /* 2 is for green */);
					cout << endl << " 23 Alem aqef yelab aderoch ken\n";
					SetConsoleTextAttribute(console, color_white);
					SetConsoleTextAttribute(console, 2 /* 2 is for green */);
					cout << endl << " 27 Yearbenoch ken \n";
					SetConsoleTextAttribute(console, color_white);
					break;
				case 8:
					cout << endl << " Easter (March equinox) \n";
					break;
				case 9:
					cout << endl << " Spring Bank Holiday (Last monday of may) \n";
				default:
					break;

			}
			/*************************************************************************************************************************/
			month++;
			cout << "\n\n====> Press '";
			SetConsoleTextAttribute(console, color_red); 
			cout << 'q'; 
			SetConsoleTextAttribute(console, color_white);
			cout << "' if you want to quit.\n\n"; 
			if (getch() == 'q')
			{
				SetConsoleTextAttribute(console, 144);
				cout << "\t\t\t\tHave a nice day!!!     \t\t\t";
				SetConsoleTextAttribute(console, color_white);
				exit(0);
			}

		}
		// ask if the user wants to enter a year and load the calendar again
		// if 'y' or 'Y' the loop will continue
		cout << endl << "==> Do you want to go again[Y]: ";
		cin >> ask;
	} while (ask == 'y' || ask == 'Y');
	SetConsoleTextAttribute(console, 144);
	cout << "\t\t\t\tHave a nice day!!!     \t\t\t";
	SetConsoleTextAttribute(console, color_white);

	/*cout << "\nAmeteAlem: " << ameteAlem;
	cout << "\nLeapYear: " << leapYear;
	cout << "\nNo of ethiopian days: " << ethNDays;
	cout << "\nStarting day: " << startDay;*/
	return 0;
}
