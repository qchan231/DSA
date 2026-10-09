#include <iostream>
using namespace std;

// Print all elements of array A with n elements
void Output(int* A, int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}

/*
 * InsertionSort — Insert each new element into its correct position
 *
 * Idea:
 *   Think of how you sort playing cards in your hand:
 *     - Pick up a new card (A[i]).
 *     - Slide it left past all cards that are larger, until it finds its spot.
 *     - Insert it there.
 *
 *   After processing index i, the subarray A[0..i] is sorted.
 *
 * Example with {3, 0, 8, 2}:
 *   i=1: insert 0 → scan left past 3 → insert at 0 → {0, 3, 8, 2}
 *   i=2: insert 8 → 8 > 3, no movement needed → {0, 3, 8, 2}
 *   i=3: insert 2 → scan left past 8, past 3 → insert at 1 → {0, 2, 3, 8}
 */
void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        cout << "i = " << i << endl;
        cout << "Mang truoc khi xu ly: ";
        Output(A, n);
        // Save the element to be inserted
        int toInsert = A[i];
		cout << "Phan tu dang xet A[" << i << "] = " << toInsert << endl;
        // Start scanning backwards from just before position i
        int scanPos = i - 1;

        // Find the correct position: stop when we hit an element <= toInsert,
        // or when we've reached the beginning of the array.
        // Note: we use A[scanPos] < toInsert (NOT > A[i]),
        //       because A[i] may have already been overwritten during shifting.
        for (; scanPos >= 0 && A[scanPos] < toInsert; scanPos--);

        // scanPos now points to the last element that is <= toInsert.
        // So toInsert belongs at scanPos + 1.
        int insertPos = scanPos + 1;

        // Shift all elements in [insertPos .. i-1] one step to the right
        // to make room for toInsert
        for (int j = i; j > insertPos; j--)
            A[j] = A[j - 1];

        // Place toInsert in its correct position
        A[insertPos] = toInsert;
		cout << "Chen " << toInsert << " vao vi tri k = " << insertPos << endl;
		cout << "Mang sau khi xu ly: ";
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
    InsertionSort(A, n);

    cout << "Mang sau khi sap xep:\n";
    Output(A, n);

    return 0;
}
