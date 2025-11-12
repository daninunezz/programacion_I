// NOT FINISHED


#include <iostream>
using namespace std;

int square(int num);
int main() {
    int number;

        cout << "Enter a positive number:";
        cin >> number;

    
    return 0;
}

int square(int num) {
    int sqr = 0, odd = 1;

    for (int i = 1; i <= num; i++) {
        sqr += odd;
        odd += 2;


    }
    return sqr;
    
}