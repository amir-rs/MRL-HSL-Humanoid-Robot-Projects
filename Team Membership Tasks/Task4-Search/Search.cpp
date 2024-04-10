#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int m = 100;

// Function to find the element in a 2D array
void findElement(int (*arr)[m], int n, int key) {
   int i, j, position = -1;
   bool userInput = false;

   // Check if user wants to provide indices
   cout << "Do you want to provide the indices? (y/n): ";
   char choice;
   cin >> choice;
   if (choice == 'y' || choice == 'Y') {
       userInput = true;
   }

   if (userInput) {
       // User provides indices
       cout << "Enter the row index: ";
       cin >> i;
       cout << "Enter the column index: ";
       cin >> j;

       if (i >= 0 && i < n && j >= 0 && j < n) {
           if (arr[i][j] == key) {
               position = 1;
               cout << "Element Found at Position: [" << i << "][" << j << "]" << endl;
           } else {
               cout << "Element not found at the given position." << endl;
           }
       } else {
           cout << "Invalid indices!" << endl;
       }
   } else {
       // Search the entire array
       for (i = 0; i < n; i++) {
           for (j = 0; j < n; j++) {
               if (arr[i][j] == key) {
                   position = 1;
                   cout << "Element Found at Position: [" << i << "][" << j << "]" << endl;
                   return;
               }
           }
       }

       if (position == -1) {
           cout << "Element not found in the array." << endl;
       }
   }
}

// Function to initialize the 2D array
void initializeArray(int (*arr)[m], int n) {
   int row, col;

   // Initialize the array with zeros
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           arr[i][j] = 0;
       }
   }

   // Generate random indices and set the value at that position to 1
   srand(time(0));
   row = rand() % n;
   col = rand() % n;
   arr[row][col] = 1;

   cout << "Random position with value 1: [" << row << "][" << col << "]" << endl;
}

int main() {
   int arr[m][m];
   int n = m;
   int key = 1;

   initializeArray(arr, n);
   findElement(arr, n, key);

   return 0;
}
