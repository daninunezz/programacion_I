#include <iostream>
using namespace std;

enum tGrade { NoPresentado, Suspenso, Aprobado, Notable, Sobresaliente, MatriculaDeHonor};

tGrade grade(double level);
tGrade gradeToStr(tGrade);

int main()
{
    double Level1, Level2;
    cout << "Level 1: " << endl;
    cin >> Level1;
    cout << "Level 2: " << endl;
    cin >> Level2;

    
    
    return 0;
}

tGrade grade(double level){
    if (level == 0)
        grade = NoPresentado;
    else if (level < 5)
        grade = Suspenso;
    //etc.
}
