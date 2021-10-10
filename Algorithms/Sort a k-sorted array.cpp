/*
Input:
 
arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9]
k = 2
 
Output:[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Function to sort a k–sorted array
void sortKSortedArray(vector<int> &nums, int k)
{
    // create an empty min-heap using `std::priority_queue`
    // use `std::greater` as a comparison function for min-heap
    priority_queue<int, vector<int>, greater<int>> pq;
 
    // insert the first `k+1` elements into a heap
    for (int i = 0; i <= k; i++) {
        pq.push(nums[i]);
    }
 
    int index = 0;
 
    // do for remaining elements in the array
    for (int i = k + 1; i < nums.size(); i++)
    {
        // pop the top element from the min-heap and assign them to the
        // next available array index
        nums[index++] = pq.top();
        pq.pop();
 
        // push the next array element into min-heap
        pq.push(nums[i]);
    }
 
    // pop all remaining elements from the min-heap and assign them to the
    // next available array index
    while (!pq.empty())
    {
        nums[index++] = pq.top();
        pq.pop();
    }
}
 
int main()
{
    vector<int> nums = { 1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;
 
    sortKSortedArray(nums, k);
 
    // print the sorted array
    for (int i: nums) {
        cout << i << " ";
    }
 
    return 0;
}


