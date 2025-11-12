#include <iostream>
using namespace std;

int main()
{
    int n = 0, a;
    cout << "Enter a sequence of numbers (end with 0): " << endl;
    cin >> a;
    
    while (a != 0) {
        n = a;
        cin >> a;
        if (a == 0) {
            cout << "It is a growing sequence" << endl;
        }
        else if (a - n < 0) {
            a = 0;
            cout << "It is not a growing sequence" << endl;
        }
        
    }
    return 0;
}