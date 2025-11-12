// sin hacer

#include <iostream>
using namespace std;

int sumOfDigits();

int main()
{
    sumOfDigits();
    
    return 0;
}

int sumOfDigits() {
    long long int num;
    int dig, aux;
    cout << "Enter a number: ";
    cin >> num;

    while (dig > 9) {
        while (num > 0) {
            dig += num % 10;
            num /= 10;
        }


            
    }
    cout << dig;
}