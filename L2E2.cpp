#include <iostream>
using namespace std;

int main()
{
   float radius;
   float height;
   double volume;
   double pi = 3.141592;

   cout << "Introduce the radius: ";
   cin >> radius;
   cout << "Introduce the height: ";
   cin >> height;

   volume = (pi * radius * radius * height) / 3;
   cout << "The volume is equal to " << volume << endl;
   
   return 0;
}