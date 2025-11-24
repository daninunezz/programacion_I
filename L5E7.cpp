#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // For random numbers
using namespace std;

const int MAX = 10;
const int DIM = 6;
typedef int tMatrix[DIM][DIM];

void generate(tMatrix matrix);
void display(const tMatrix matrix, string label);
void sum(const tMatrix matrix1, const tMatrix matrix2, tMatrix matrixRes);
void subtract(const tMatrix matrix1, const tMatrix matrix2, tMatrix matrixRes);
void product(const tMatrix matrix1, const tMatrix matrix2, tMatrix matrixRes);
void transpose(const tMatrix matrix, tMatrix matrixRes);
void saddlePoints(const tMatrix matrix);
int menu();

int main() {
   tMatrix matrix1, matrix2, matrixRes;
   int option = -1;

   srand(time(NULL));
   generate(matrix1);
   display(matrix1, "Matrix1");
   generate(matrix2);
   display(matrix2, "Matrix2");
   while (option != 0) {
      option = menu();
      switch (option) {
      case 1:
         sum(matrix1, matrix2, matrixRes);
         display(matrix1, "Matrix1");
         display(matrix2, "Matrix2");
         display(matrixRes, "Matrix1 + Matrix2");
         break;
      case 2:
         subtract(matrix1, matrix2, matrixRes);
         display(matrix1, "Matrix1");
         display(matrix2, "Matrix2");
         display(matrixRes, "Matrix1 - Matrix2");
         break;
      case 3:
         product(matrix1, matrix2, matrixRes);
         display(matrix1, "Matrix1");
         display(matrix2, "Matrix2");
         display(matrixRes, "Matrix1 x Matrix2");
         break;
      case 4:
         transpose(matrix1, matrixRes);
         display(matrix1, "Matrix1");
         display(matrixRes, "Transpose of Matrix1");
         break;
      case 5:
         display(matrix1, "Matrix1");
         cout << "Saddle points in Matrix1 (marked with an asterisk)" << endl;
         saddlePoints(matrix1);
         break;
      }
   }

   return 0;
}

void generate(tMatrix matrix) {
   for (int row = 0; row < DIM; row++)
      for (int col = 0; col < DIM; col++)
         matrix[row][col] = rand() % MAX;
}

void display(const tMatrix matrix, string label) {
   cout << label << endl;
   for (int row = 0; row < DIM; row++) {
      for (int col = 0; col < DIM; col++)
         cout << setw(4) << matrix[row][col];
      cout << endl;
   }
   cout << endl;
}

void sum(const tMatrix matrix1, const tMatrix matrix2, tMatrix matrixRes) {
    for (int row = 0; row < DIM; row++) {
        for (int col = 0; col < DIM; col++) {
             cout << matrix1[row][col] + matrix2[row][col];
        }
    }
}

void subtract(const tMatrix matrix1, const tMatrix matrix2, tMatrix matrixRes) {

}

void product(const tMatrix matrix1, const tMatrix matrix2, tMatrix matrixRes) {
    for (int row = 0; row < DIM; row++) {
        for (int col = 0; col < DIM; col++) {
            matrixRes[row][col] = 0;
            for (int i = 0; i < DIM; i++) {
                
            }
        }
    }
}

void transpose(const tMatrix matrix, tMatrix matrixRes) {

}

void saddlePoints(const tMatrix matrix) {

}

int menu() {
   int op = -1;

   while (op < 0 || op > 5) {
      cout << "Working with matrixes..." << endl;
      cout << "1 - Add" << endl;
      cout << "2 - Subtract" << endl;
      cout << "3 - Multiply" << endl;
      cout << "4 - Transpose" << endl;
      cout << "5 - Saddle points" << endl;
      cout << "0 - Exit" << endl;
      cout << "Your option: ";
      cin >> op;
      if (op < 0 || op > 5)
         cout << "Invalid option! Try again..." << endl;
   }
   cout << endl;

   return op;
}
