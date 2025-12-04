#include <iostream>
using namespace std;

void maxHeapify(int A[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

void buildMaxHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i);
}

void heapSortIncreasing(int A[], int n) {
    buildMaxHeap(A, n);
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        maxHeapify(A, i, 0);
    }
}

void minHeapify(int A[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < n && A[l] < A[smallest])
        smallest = l;
    if (r < n && A[r] < A[smallest])
        smallest = r;

    if (smallest != i) {
        swap(A[i], A[smallest]);
        minHeapify(A, n, smallest);
    }
}

void buildMinHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(A, n, i);
}

void heapSortDecreasing(int A[], int n) {
    buildMinHeap(A, n);
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        minHeapify(A, i, 0);
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int A[] = {20, 5, 15, 22, 40, 3, 7};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original: ";
    printArray(A, n);

    heapSortIncreasing(A, n);
    cout << "Increasing Heapsort: ";
    printArray(A, n);

    int B[] = {20, 5, 15, 22, 40, 3, 7};
    heapSortDecreasing(B, n);
    cout << "Decreasing Heapsort: ";
    printArray(B, n);

    return 0;
}
