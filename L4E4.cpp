#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    for (int i = 100; i <= 999; i++) {
        int d1 = i % 10;
        int d2 = (i / 10) % 10;
        int d3 = (i / 100) % 10;

        if (pow(d1, 3) + pow(d2, 3) + pow(d3, 3) == i) {
            cout << i << endl;
        }
    }
    
    return 0;
}