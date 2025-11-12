//sin hacer

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

    while (num != 0) {
        aux = num % 10;
        dig += aux;
        num /= 10;
    }
    cout << dig;
}
