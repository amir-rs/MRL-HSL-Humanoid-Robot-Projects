#include <iostream>
using namespace std;

class Matrix {
private:
   int Row;
   int Column;
   float** mat;

public:
   int temp;
   int Identity(int num);
   void init();
   void print();
   void reverseMatrix3();
   void reverseMatrix2();
   void operator+(Matrix x);
   void operator-(Matrix x);
   void operator*(Matrix x);
   Matrix(int a, int b);
   Matrix();
   ~Matrix();
};

Matrix::Matrix(int a, int b) {
   Row = a;
   Column = b;
   mat = new float*[Row];
   for (int i = 0; i < Column; ++i)
       mat[i] = new float[Column];
}

void Matrix::init() {
   float number;
   for (int i = 0; i < Row; i++) {
       for (int j = 0; j < Column; j++) {
           cout << "Matrix [" << i << "][" << j << "]: ";
           cin >> number;
           mat[i][j] = number;
       }
   }
   print();
}

void Matrix::reverseMatrix3() {
   int i, j;
   float determinant = 0;
   
   // Finding determinant
   for (i = 0; i < 3; i++)
       determinant += (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
   
   cout << "\n\nDeterminant: " << determinant << endl;
   
   for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++)
           cout << ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";
       cout << "\n";
   }
}

void Matrix::reverseMatrix2() {
   float temp[2][2];
   float determinant;
   temp[0][0] = mat[1][1];
   temp[0][1] = -mat[0][1];
   temp[1][0] = -mat[1][0];
   temp[1][1] = mat[0][0];

   determinant = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

   for (int i = 0; i < Row; i++)
       for (int j = 0; j < Column; j++) {
           temp[i][j] *= (1 / determinant);
       }

   for (int i = 0; i < Row; i++) {
       for (int j = 0; j < Column; j++)
           cout << " " << temp[i][j] << " ";
       cout << endl;
   }
}

int Matrix::Identity(int num) {
   int row, col;

   for (row = 0; row < num; row++) {
       for (col = 0; col < num; col++) {
           if (row == col)
               cout << 1 << " ";
           else
               cout << 0 << " ";
       }
       cout << endl;
   }
   return 0;
}

void Matrix::operator+(Matrix x) {
   Matrix result(Row, Column);

   for (int i = 0; i < Row; i++) {
       for (int j = 0; j < Column; j++) {
           result.mat[i][j] = mat[i][j] + x.mat[i][j];
       }
   }

   result.print();
}

void Matrix::operator-(Matrix x) {
   Matrix result(Row, Column);

   for (int i = 0; i < Row; i++) {
       for (int j = 0; j < Column; j++) {
           result.mat[i][j] = mat[i][j] - x.mat[i][j];
       }
   }

   result.print();
}

void Matrix::operator*(Matrix x) {
   Matrix result(Row, Column);

   for (int i = 0; i < Row; i++) {
       for (int j = 0; j < Column; j++) {
           result.mat[i][j] = 0;

           for (int k = 0; k < Column; k++) {
               result.mat[i][j] += mat[i][k] * x.mat[k][j];
           }
       }
   }
   result.print();
}

void Matrix::print() {
   for (int i = 0; i < Row; i++) {
       for (int j = 0; j < Column; j++)
           cout << " " << mat[i][j] << " ";
       cout << endl;
   }
}

Matrix::~Matrix() {
   // Deallocate dynamically allocated memory
   for (int i = 0; i < Row; ++i)
       delete[] mat[i];
   delete[] mat;
}

int main() {
   int number;
   char choice;
   cout << "Enter the number of rows and columns: ";
   cin >> number;

   while (true) {
       Matrix matrix1(number, number);
       matrix1.init();
       Matrix matrix2(number, number);
       matrix2.init();

       cout << "Addition of two given matrices: \n";
       matrix1 + matrix2;

       cout << "Subtraction of two given matrices: \n";
       matrix1 - matrix2;

       cout << "Multiplication of two given matrices: \n";
       matrix1 * matrix2;

       cout << "\n\nReverse of Matrix 1 (3x3):\n\n";
       matrix1.reverseMatrix3();

       cout << "\n\nReverse of Matrix 2 (2x2):\n\n";
       matrix2.reverseMatrix2();

       cout << "\nDo you want to continue? (y/n): ";
       cin >> choice;
       if (choice == 'n' || choice == 'N')
           break;
   }

   return 0;
}
