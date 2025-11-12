/*
Declare an enumerated type for workdays (tWorkday)
Create a function workdayToStr()
Create a main program to ask the user for the total sales of each workday in a week, and print the total sales of the week (with 2 decimals)
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum tWorkday { Monday, Tuesday, Wednesday, Thursday, Friday };

string workdayToStr(tWorkday day);

int main() {
   tWorkday workday = Monday;
   double sales, totalSales = 0;
   
   while (workday <= Friday) {
      cout << workdayToStr(workday) << " total sales: ";
      cin >> sales;
      totalSales += sales;
      // workday++ does not work!
      workday = tWorkday(int(workday) + 1);
   }
   cout << "Week total sales = $" << fixed << setprecision(2) << totalSales << endl;
   
   return 0;
}

string workdayToStr(tWorkday day) {
   string str;
   
   if (day == Monday)
      str = "Monday";
   else if (day == Tuesday)
      str = "Tuesday";
   else if (day == Wednesday)
      str = "Wednesday";
   else if (day == Thursday)
      str = "Thursday";
   else 
      str = "Friday";

   return str;
}