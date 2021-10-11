#include <bits/stdc++.h>

using namespace std;

/* 
Slowsort function implementation   
*/
void SlowSort(int a[], int i, int j) {
    if (i >= j){ // If base case, return
        return;
    }
    int mid = (i + j) / 2; // Find midpoint
    SlowSort(a, i, mid); // Find maximum element on left side
    SlowSort(a, mid + 1, j); // Find maximum element on right side
    if (a[j] < a[mid]) { // Force maximum value to end of array
        swap(a[j], a[mid]); // Swap if neccesary
    }
    SlowSort(a, i, j - 1); // Slowsorts everything except the max element
}

/*
Main function to test the slow sort algorithm
*/
int main() {
    // Get input values
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // SLowsort the array
    SlowSort(arr, 0, n);
    // Print out the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}
