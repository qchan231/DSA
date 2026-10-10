#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int& N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
bool isMaxHeap(int A[], int N) 
{
	for (int i = 0; i <= (N - 2) / 2; i++) 
    {
		if (A[i] < A[2 * i + 1]) return false; // left child
		if (2 * i + 2 < N && A[i] < A[2 * i + 2]) return false; // right child
	}
	return true;
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    std::cout << "MaxHeap: " << std::boolalpha << isMaxHeap(a, n) << std::endl;

    return 0;
}
