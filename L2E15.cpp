#include <iostream>
using namespace std;

int main()
{
    double quantity, conversion;
    bool loop = true;
    char unit;

    while (loop == true){
        cout << "Enter a quantity and its respective unit: ";
        cin >> quantity;
        cin >> unit;

        if (quantity == 0)
            loop = false;

        else if (unit == 'i'){
            conversion = quantity * 2.54;
            cout << quantity << " inches is equal to " << conversion << " cm";
        }
        else if (unit == 'm'){
            conversion = quantity * 1609.344;
            cout << quantity << " miles is equal to " << conversion << " m";
        }
        else if (unit == 'f'){
            conversion = (quantity - 32) * 5.0 / 9.0;
            cout << quantity << "º Fahrenheit is equal to " << conversion << "ºC";
        }
        else if (unit == 'g'){
            conversion = quantity * 3.78541;
            cout << quantity << " gallons is equal to " << conversion << " L";
        }
        else if (unit == 'o'){
            conversion = quantity * 28.3495;
            cout << quantity << " ounces is equal to " << conversion << " g";
        }
        else if (unit == 'p'){
            conversion = quantity * 0.453592;
            cout << quantity << " pounds is equal to " << conversion << " kg";
        }
        cout << endl << endl;
    }
   return 0;
}