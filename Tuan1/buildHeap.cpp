#include <iostream>
#define MAXN 150000
using namespace std;
void NhapMang(int A[], int& N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}	
void Heapify(int a[], int heapSize, int i) 
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < heapSize && a[max]<a[left])
		max = left;
	if (right < heapSize && a[max]<a[right])
		max = right;
	if (max != i) {
		swap(a[i], a[max]);
		Heapify(a, heapSize, max);
	}
}

void BuildHeap(int a[], int n) 
{
	int heapSize = n;   
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        Heapify(a, heapSize, i);
    }
}
void XuatMang(int A[], int N) 
{
	cout << N << endl;
	for (int i = 0; i < N; i++)
	cout << A[i] << " ";
	cout << endl;
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    BuildHeap(a, n);

    XuatMang(a, n);

    return 0;
}
