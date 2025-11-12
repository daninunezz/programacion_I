#include <iostream>
using namespace std;

const int N = 10;
typedef double tGrades[N];
tGrades grades;
int grade;
double average(tGrades grades);
int failed(tGrades grades);

int main()
{
    for (int i = 0; i < N; i++) {
        cout << "Enter the grade: ";
        cin >> grade;
        grades[i] = grade;
    }


    
    return 0;
}

double average(tGrades grades) {
    double avg = 0;

    for (int i = 0; i < NumGrades; i++)
}
