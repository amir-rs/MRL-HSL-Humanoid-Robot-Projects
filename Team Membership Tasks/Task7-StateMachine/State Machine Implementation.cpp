#include <iostream>

using namespace std;

const int m = 8;

// Function to initialize the array with a single 1 at a given position
void initializeArray(int (*arr)[m], int n, int& row, int& col) {
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           arr[i][j] = 0;
       }
   }
   arr[row][col] = 1;
}

// Function to display the array
void displayArray(int (*arr)[m], int n) {
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           cout << "[" << i << "][" << j << "]= " << arr[i][j] << "\t";
       }
       cout << endl << endl;
   }
}

// Function to move the 1 up
void moveUp(int (*arr)[m], int n, int& row, int& col) {
   int moves;
   cout << "How many moves? ";
   cin >> moves;

   if (moves > row) {
       cout << "Cannot move!!" << endl << endl;
   } else {
       arr[row][col] = 0;
       row -= moves;
       arr[row][col] = 1;
       displayArray(arr, n);
   }
}

// Function to move the 1 down
void moveDown(int (*arr)[m], int n, int& row, int& col) {
   int moves;
   cout << "How many moves? ";
   cin >> moves;

   if (row + moves >= n) {
       cout << "Cannot move!!" << endl << endl;
   } else {
       arr[row][col] = 0;
       row += moves;
       arr[row][col] = 1;
       displayArray(arr, n);
   }
}

// Function to move the 1 left
void moveLeft(int (*arr)[m], int n, int& row, int& col) {
   int moves;
   cout << "How many moves? ";
   cin >> moves;

   if (moves > col) {
       cout << "Cannot move!!" << endl << endl;
   } else {
       arr[row][col] = 0;
       col -= moves;
       arr[row][col] = 1;
       displayArray(arr, n);
   }
}

// Function to move the 1 right
void moveRight(int (*arr)[m], int n, int& row, int& col) {
   int moves;
   cout << "How many moves? ";
   cin >> moves;

   if (col + moves >= n) {
       cout << "Cannot move!!" << endl << endl;
   } else {
       arr[row][col] = 0;
       col += moves;
       arr[row][col] = 1;
       displayArray(arr, n);
   }
}

int main() {
   int arr[m][m];
   int n = sizeof(arr) / sizeof(arr[0]);
   int row = 7, col = 0;
   char choice;

   initializeArray(arr, n, row, col);
   displayArray(arr, n);

   while (true) {
       cout << "U(Up) | D(Down) | L(Left) | R(Right) | UL(UpperLeft) | UR(UpperRight) | DL(DownLeft) | DR(DownRight) | E(Exit)" << endl;
       cin >> choice;

       switch (toupper(choice)) {
           case 'U':
               moveUp(arr, n, row, col);
               break;
           case 'D':
               moveDown(arr, n, row, col);
               break;
           case 'L':
               moveLeft(arr, n, row, col);
               break;
           case 'R':
               moveRight(arr, n, row, col);
               break;
           case 'E':
               return 0;
           default:
               cout << "Invalid choice! Please try again." << endl;
               break;
       }
   }

   return 0;
}
