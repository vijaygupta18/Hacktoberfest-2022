#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int PartitionHelper(int *a, int s, int e) {
	int i = s - 1;
	int x = a[e];

	for (int j = s ; j < e; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[e]);
	return i + 1;
}

int Partition(int *a, int s, int e) {

	srand(time(0));
	int ri = s + (rand()) % (e - s);
	swap(a[ri], a[e]);
	return PartitionHelper(a, s, e);
}

void QuickSort(int *a, int s, int e) {
	if (s >= e) {
		return;
	}

	int p = Partition(a, s, e);
	QuickSort(a, s, p - 1);
	QuickSort(a, p + 1, e);
}

int main() {

	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}

	cout << "Before Sorting: ";
	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	QuickSort(a, 0, n - 1);

	cout << "After Sorting: ";
	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}