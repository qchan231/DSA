#include <iostream>
using namespace std;

// Print all elements of array A with n elements
void Output(int* A, int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}

/*
 * SelectionSort — Find the minimum and place it at the front
 *
 * Idea:
 *   Divide the array into two parts:
 *     - Sorted   : A[0 .. i-1]  — already in final position
 *     - Unsorted : A[i .. n-1]  — still needs to be sorted
 *
 *   Each pass: scan the unsorted part to find the minimum element,
 *   then swap it into position i (the front of the unsorted part).
 *   After n-1 passes the entire array is sorted.
 *
 * Example with {3, 0, 8, 2}:
 *   Pass 0: min is 0 at index 1 → swap A[0] & A[1] → {0, 3, 8, 2}
 *   Pass 1: min is 2 at index 3 → swap A[1] & A[3] → {0, 2, 8, 3}
 *   Pass 2: min is 3 at index 3 → swap A[2] & A[3] → {0, 2, 3, 8}
 */
void SelectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "i = " << i << endl;
        cout << "Mang truoc khi swap:";
        Output(A, n);
        // Assume the first element of the unsorted part is the minimum
        int maxIndex = i;
        // Scan the rest of the unsorted part to find the true minimum
        for (int j = i + 1; j < n; j++) {
            if (A[j] > A[maxIndex])
                maxIndex = j;  // Found a new maximum, update index
        }
        cout << "Phan tu lon nhat trong doan [" << i + 1 << ", " << n - 1 << "]: " << A[maxIndex] << endl;
		cout << "Swap " << A[i] << " va " << A[maxIndex] << endl;
        // Place the maximum at position i (front of unsorted part)
        swap(A[i], A[maxIndex]);
		cout << "Mang sau khi swap:";
		Output(A, n);
		cout << endl;   
    }   
}

int main() {
    int n;
    cin >> n;
    int A[200];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Mang truoc khi sap xep:\n";
    Output(A, n);
    cout << endl;
    cout << "Sap xep:\n";
    SelectionSort(A, n);
    cout << "Mang sau khi sap xep:\n";
    Output(A, n);

    return 0;
}
