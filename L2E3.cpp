#include <iostream>
using namespace std;

int main()
{
   double farenheit, celsius;

   cout << "Introduce a temperature in Farenheit degrees: ";
   cin >> farenheit;

   celsius = 5.0 / 9 * (farenheit - 32);
   cout << farenheit << "ºF are equal to " << celsius << "ºC" << endl;

   return 0;
}