#include <iostream>
using namespace std;
#include <string>

bool leapYear(int y);

int main() {

    int day, month, year, nYears, aux, totDays = 0;
    string weekDayStr;
    cout << "Enter a date (dd mm yyyy): ";
    cin >> day >> month >> year;

    nYears = year - 1900;
    aux = nYears / 4;
    totDays += nYears * 365 + aux;

    for (int i = 1; i < month ; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            totDays += 31;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11) {
            totDays += 30;
        }
        else if (i == 2 && leapYear(year)) {
            totDays += 29;
        }
        else 
            totDays += 28;
    }

    totDays += day - 1;


    switch (totDays % 7) {

        case 0: 
            weekDayStr = "Monday";
            break;
        case 1:
            weekDayStr = "Tuesday";
            break;
        case 2:
            weekDayStr = "Wednesday";
            break;
        case 3:
            weekDayStr = "Thursday";
            break;
        case 4:
            weekDayStr = "Friday";
            break;
        case 5:
            weekDayStr = "Saturday";
            break;
        case 6:
            weekDayStr = "Sunday";
            break;
    }
    cout << weekDayStr << endl;

    return 0;
}

bool leapYear(int y) {
    bool leap;
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
            leap = true;
        }
        else
            leap = false;
        return leap;
    }
