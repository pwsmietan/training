#include <iostream>
#include <iomanip>

using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }

    return false;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, bool isLeapYear)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return (isLeapYear) ? 29 : 28;
    }
    return 0;
}

// Function to print the calendar for a month
void printMonth(int year, int month, int startingDay)
{
    const string monthNames[] = {"January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "October", "November", "December"};

    cout << "  " << monthNames[month - 1] << " " << year << endl;
    cout << "  Sun Mon Tue Wed Thu Fri Sat" << endl;

    // Print leading spaces
    for (int i = 0; i < startingDay; i++)
    {
        cout << "    ";
    }

    int daysInMonth = getDaysInMonth(month, isLeapYear(year));
    for (int day = 1; day <= daysInMonth; day++)
    {
        cout << setw(4) << day;
        if ((day + startingDay - 1) % 7 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

int main()
{
    int year, startingDay;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter first day of the year (1 for Monday, 7 for Sunday): ";
    cin >> startingDay;

    // Adjust starting day to be 0-based (0 for Sunday, 6 for Saturday)
    startingDay = (startingDay + 6) % 7;

    for (int month = 1; month <= 12; month++)
    {
        printMonth(year, month, startingDay);

        // Update starting day for the next month
        startingDay = (startingDay + getDaysInMonth(month, isLeapYear(year))) % 7;
    }

    return 0;
}
