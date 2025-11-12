#include <iostream>
using namespace std;
#include <iomanip>

int main() {
    int num;
    bool loop = true;
    int counter = 0;
    int i = 1;


    while (loop){
        cout << "Enter a number (1 - 100): ";
        cin >> num;

        if (num >= 1 && num <= 100) {
                for (int i = 1; i <= 10; i++) {
                    cout << setw(3) << i << " x " << setw(4) << num << " = " << setw(5) << num * i << endl;
                }
                i = 1;
                counter = 0;
        }
    }
    return 0;
}