#include<iostream>
#include<stdio.h>
using namespace std;
void TSP(int C[][4], int A[][4], int path[], int fpath[][3], int& sum, int& fsum, int
flag, int n, int b, int a, int& sc) {
 int k;
 flag++;
 for (k = 0; k < n; k++)
 if (C[flag][k] == 0) { //Check vertex is visited or not
 C[flag][k] = k + 1;
 sum = sum + A[b][k]; //total covered distance.
 path[flag - 1] = k;
 //Update the reached vertex
 if (flag < n) {
 for (int i = flag + 1; i < n; i++)
 C[i][k] = k + 1;
 }
 if (flag < n - 1)
 TSP(C, A, path, fpath, sum, fsum, flag, n, k, a, sc);
 if (flag == n - 1) {
 sum = sum + A[k][a];
 if (sum == fsum) {
 sc = sc + 1;
 for (int i = 0; i < n - 1; i++)
 fpath[sc][i] = path[i]; //Updating final path direction.
 }
 else if (sum < fsum) {
 fsum = sum;
 sc = 0;
 for (int i = 0; i < n - 1; i++)
 fpath[i][0] = path[i]; //Updating final path direction.
 }
 sum = sum - A[k][a];
 }
 for (int i = flag; i < n; i++)
 C[i][k] = 0;
 sum = sum - A[b][k]; //Substructing last added path distance.
 }
}
int main() {
 int n, a, sc = 0;
 cout << "Enter the number of cities:";
 cin >> n;
 int A[4][4], C[4][4], sum = 0, fsum = 9999, path[3], fpath[1000][3];
 cout << "\nEnter all the costs of cities:\n";
 for (int i = 0; i < n; i++)
 {
 for (int j = 0; j < n; j++)
 cin >> A[i][j];
 }
 cout << "Enter the Starting city : " << endl;
 cin >> a;
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 C[i][j] = 0;
 for (int i = 0; i < n; i++)
 C[i][a - 1] = a;
 TSP(C, A, path, fpath, sum, fsum, 0, n, a - 1, a - 1, sc);
 cout << "\nMinimum traveled distance = " << fsum;
}
