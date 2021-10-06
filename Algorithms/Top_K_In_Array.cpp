#include <iostream>
#include <queue>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

}