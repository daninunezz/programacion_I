#include <iostream>
using namespace std;

int main(){

    int seconds;
    int minutes;
    int hours;
    int left_seconds;

    cout << "TIME CALCULATOR" << endl;

    cout << "Introduce an elapsed time in seconds: ";
    cin >> seconds;
    
    hours = seconds / 3600;
    minutes = (seconds - hours * 3600) / 60;
    left_seconds = seconds - hours * 3600 - minutes * 60;

    cout << seconds << " seconds are equal to " << hours << " hour/s, " << minutes << " minute/s and " << left_seconds << " second/s" << endl;

    return 0;

}