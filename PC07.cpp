#include <iostream>
using namespace std;

typedef int tNumbers[10];
typedef bool tEven[10];

int sum(tNumbers nums);
bool isTriangle(int number);

int main()
{
    tNumbers numbers;
    tEven evens;
    int nEvens = 0;

    for (int i = 0; i < 10; i++) {
        cout << "Enter an integer " << i + 1 << ": ";
        cin >> numbers[i];
    }

    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << ", ";
    }
    cout << endl;

    cout << sum(numbers) << endl;

    for (int i = 0; i < 10; i++) {
        if (isTriangle(numbers[i])) {
            cout << i << ", ";
        }
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 == 0) 
            evens[i] = true;
        else evens[i] = false;
    }
    for (int i = 0; i < 10; i++) {
        if (evens[i] == true) {
            nEvens += 1;
        }
    }
    cout << nEvens << endl;
    return 0;
}

int sum(tNumbers nums) {
    int tot = 0;
    for (int i = 0; i < 10; i++) {
        tot += nums[i];
    }
    return tot;
}


//wrong
bool isTriangle(int number) {
    bool triangle = false;
    int total = 0, summation = 1;
        while (total <= number) {
            if (number == total) {
                triangle = true;
                break;
            }
            else {
                total += summation;
                summation++;
            }
        }
    return triangle;
}