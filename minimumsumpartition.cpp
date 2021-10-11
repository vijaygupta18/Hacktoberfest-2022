#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Partition set `S` into two subsets, `S1` and `S2`, such that the
// difference between the sum of elements in `S1` and the sum
// of elements in `S2` is minimized
int findMinAbsDiff(vector<int> const &S, int n, int S1, int S2)
{
    // Base case: if the list becomes empty, return the absolute
    // difference between both sets
    if (n < 0) {
        return abs(S1 - S2);
    }
 
    // Case 1. Include the current item in subset `S1` and recur
    // for the remaining items `n-1`
    int inc = findMinAbsDiff(S, n - 1, S1 + S[n], S2);
 
    // Case 2. Exclude the current item from subset `S1` and recur for
    // the remaining items `n-1`
    int exc = findMinAbsDiff(S, n - 1, S1, S2 + S[n]);
 
    return min(inc, exc);
}
 
int main()
{
    // Input: a set of items
    vector<int> S = { 10, 20, 15, 5, 25};
 
    // total number of items
    int n = S.size();
 
    cout << "The minimum difference is " << findMinAbsDiff(S, n - 1, 0, 0);
 
    return 0;
}
