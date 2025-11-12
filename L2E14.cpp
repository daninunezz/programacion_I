#include <iostream>
using namespace std;

int main()
{
    int num = 1;

    while (num != 0){
        cout << "Enter a number: ";
        cin >> num;
        if (num >= 0){
            if (num % 2 != 0)
                cout << "The number you entered is odd" << endl;
            else
                cout << "The number you entered is even"  << endl;
        }
    }
    return 0;
}
