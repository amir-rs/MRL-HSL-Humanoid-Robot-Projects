#include <iostream>
using namespace std;

class Matrix
{
private:
	int Row;
	int Column;
	float** mat;
public:
	int temp;
	int Identity(int num);
	void init();
	void print();
	void reverser3();
	void reverser2();
	void operator+(Matrix x);
	void operator-(Matrix x);
	void operator*(Matrix x);
	Matrix(int a, int b);
	Matrix();
	~Matrix();

};
///////////////////////////////////////////////////////////
Matrix::Matrix(int a, int b)
{
	Row = a;
	Column = b;
	mat = new float* [Row];
	for (int i = 0; i < Column; ++i)
		mat[i] = new float[Column];
}
//////////////////////////////////////////////////////////
void Matrix::init()
{
	float number;
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++) {
			cout << "Matrix " << "[" << i << "]" << "[" << j << "] : ";
			cin >> number;
			mat[i][j] = number;
		}

	}
	print();
}
//////////////////////////////////////////////////////////
void Matrix::reverser3()
{
   int  i, j;
   float determinant = 0;
   //finding determinant
    for(i = 0; i < 3; i++)
       determinant =+ (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
       cout<<"\n\ndeterminant: "<<determinant<<endl;
    for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++)
        cout<<((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant<<"\t";
            cout<<"\n";
    }    
}
//////////////////////////////////////////////////////////
void  Matrix::reverser2() {
	float Test3[2][2];
	float determinant;
	Test3[0][0] = mat[1][1];
	Test3[0][1] = -mat[0][1];
	Test3[1][0] = -mat[1][0];
	Test3[1][1] = mat[0][0];

	determinant = ((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));

	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Column; j++) {
			Test3[i][j] *= (1 / determinant);
		}

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++)
			cout << " " << Test3[i][j] << " ";
		cout << endl;
	}
}

//////////////////////////////////////////////////////////
int Matrix::Identity(int num)
{
	int row, col;

	for (row = 0; row < num; row++)
	{
		for (col = 0; col < num; col++)
		{

			if (row == col)
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
	return 0;
}

//////////////////////////////////////////////////////////
void Matrix::operator+(Matrix x)
{
	Matrix Test3(Row, Column);


	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++) {


			Test3.mat[i][j] = mat[i][j]
				+ x.mat[i][j];
		}
	}

	Test3.print();
}
//////////////////////////////////////////////////////////
void Matrix::operator-(Matrix x)
{
	Matrix Test3(Row, Column);

	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < Column; j++) {

			Test3.mat[i][j] = mat[i][j]
				- x.mat[i][j];
		}
	}

	Test3.print();
}
//////////////////////////////////////////////////////////
void Matrix::operator*(Matrix x)
{
	Matrix Test3(Row, Column);




	for (int i = 0; i < Row; i++) {

		for (int j = 0; j < Column; j++) {

			Test3.mat[i][j] = 0;

			for (int k = 0; k < Column; k++) {
				Test3.mat[i][j] += mat[i][k]
					* (x.mat[k][j]);
			}
		}
	}
	Test3.print();

}
//////////////////////////////////////////////////////////
void Matrix::print() {

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++)
			cout << " " << mat[i][j] << " ";
		cout << endl;
	}
}
//////////////////////////////////////////////////////////
Matrix::~Matrix()
{
}
//////////////////////////////////////////////////////////
int main()
{
    int number;
    char c;
    cout<<"enter the number row and column \n";
    cin>> number;
    while (true)
    {
        
                Matrix Test(number,number);
	            Test.init();
                Matrix Test1(number, number);
	            Test1.init();
                cout << "Addition of two given"
		        << " Matrices is : \n";
                Test + Test1;
                cout << "Subtraction of two given"
		        << " Matrices is : \n";
	            Test - Test1;
            	cout << "Multiplication of two"
		        << " given Matrices is : \n";
	            Test* Test1;
                cout << "\n\nReversed Matrix 1\n\n";
                Test.reverser3();
                cout << "\n\nReversed Matrix 2\n\n";
                Test1.reverser2();
                cout<<"\n do you want continue\n";
                cin>>c;
                if (c=='n'|| c=='N')
                 break;
            
    }
    



}
  // Persian Language (Farsi)

	// // ماتریس کهاد :
	// matrix3[0][0] = (matrix[1][1]*matrix[2][2])-(matrix[2][1]*matrix[1][2]);
	// matrix3[1][0] = (matrix[0][1]*matrix[2][2])-(matrix[2][1]*matrix[0][2]);
	// matrix3[2][0] = (matrix[0][1]*matrix[1][2])-(matrix[1][1]*matrix[0][2]);
	// matrix3[0][1] = (matrix[1][0]*matrix[2][2])-(matrix[2][0]*matrix[1][2]);
	// matrix3[1][1] = (matrix[0][0]*matrix[2][2])-(matrix[2][0]*matrix[0][2]);
	// matrix3[2][1] = (matrix[0][0]*matrix[1][2])-(matrix[1][0]*matrix[0][2]);
	// matrix3[0][2] = (matrix[1][0]*matrix[2][1])-(matrix[2][0]*matrix[1][1]);
	// matrix3[1][2] = (matrix[0][0]*matrix[2][1])-(matrix[2][0]*matrix[0][1]);
	// matrix3[2][2] = (matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]);
	// //ماتریس همساز :
	// matrix3[0][1] *= -1;
	// matrix3[1][0] *= -1;
	// matrix3[1][2] *= -1;
	// matrix3[2][1] *= -1;
	// // ماتریس الحاقی :
	// tmp = matrix3[0][1];
	// matrix3[0][1] = matrix3[1][0];
	// matrix3[1][0] = tmp;
	
	// tmp = matrix3[0][2];
	// matrix3[0][2] = matrix3[2][0];
	// matrix3[2][0] = tmp;
	
	// tmp = matrix3[1][2];
	// matrix3[1][2] = matrix3[2][1];
	// matrix3[2][1] = tmp;
	// //  دترمینان :
	// determinant = (
	// (matrix[0][0]*(matrix[1][1]*matrix1[2][2] - matrix[2][1]*matrix[1][2]))-
	// (matrix[0][1]*(matrix[1][0]*matrix1[2][2] - matrix[1][2]*matrix[2][0]))+
	// (matrix[0][2]*(matrix[1][0]*matrix1[2][1] - matrix[2][0]*matrix[1][1]))
	// );
	// // حاصل‌ضرب ماتریس الحاقی در معکوس دترمینان :
	// for(int i=0;i<row;i++)
	// 	for(int j=0;j<column;j++){
	// 		matrix3[i][j] *= (1/determinant);
	// 	}