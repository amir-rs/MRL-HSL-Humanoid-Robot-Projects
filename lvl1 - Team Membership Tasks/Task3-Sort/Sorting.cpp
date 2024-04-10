#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to merge two subarrays of the given array
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
   int i = 0, j = 0, k = 0;
   
   // Merge the temporary arrays back into arr[left...right]
   while (i < leftSize && j < rightSize) {
       if (left[i] <= right[j]) {
           arr[k++] = left[i++];
       } else {
           arr[k++] = right[j++];
       }
   }
   
   // Copy the remaining elements of left[], if there are any
   while (i < leftSize) {
       arr[k++] = left[i++];
   }
   
   // Copy the remaining elements of right[], if there are any
   while (j < rightSize) {
       arr[k++] = right[j++];
   }
}

// Mergesort function
void mergeSort(int arr[], int left, int right) {
   if (left >= right) {
       return; // Returns recursively
   }
   
   int mid = left + (right - left) / 2;
   
   // Temporary subarrays
   int leftArray[mid - left + 1], rightArray[right - mid];
   
   // Copy data to temporary subarrays
   for (int i = 0; i < mid - left + 1; i++) {
       leftArray[i] = arr[left + i];
   }
   for (int j = 0; j < right - mid; j++) {
       rightArray[j] = arr[mid + 1 + j];
   }
   
   // Recursively sort the subarrays
   mergeSort(leftArray, 0, mid - left);
   mergeSort(rightArray, 0, right - mid - 1);
   
   // Merge the sorted subarrays back into arr[]
   merge(arr, leftArray, mid - left + 1, rightArray, right - mid);
}

// Selection Sort function
void selectionSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
       int minIndex = i;
       
       // Find the minimum element in the unsorted part of the array
       for (int j = i + 1; j < n; j++) {
           if (arr[j] < arr[minIndex]) {
               minIndex = j;
           }
       }
       
       // Swap the minimum element with the first element of the unsorted part
       int temp = arr[i];
       arr[i] = arr[minIndex];
       arr[minIndex] = temp;
   }
}

int main() {
   int arr[20];
   int n = sizeof(arr) / sizeof(arr[0]);
   int max = 100, min = 0, choice;
   srand(time(0));  // Seed the random number generator

   // Generate random array elements
   for (int i = 0; i < 20; i++) {
       arr[i] = (rand() % (max - min)) + min;
   }

   cout << "Your array is:" << endl;
   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   }

   cout << endl << endl << "1 (Selection Sort) or 2 (Merge Sort)" << endl;
   cin >> choice;

   if (choice == 1) {
       selectionSort(arr, n);
   } else if (choice == 2) {
       mergeSort(arr, 0, n - 1);
   }

   cout << "\nYour array after sorting: \n";
   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   }

   return 0;
}
