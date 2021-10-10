// To find there is a zero sum subarray
//Print Yes if zero sum subarray exist 
//Print No if zero sum subarray does not exist.

#include <bits/stdc++.h>
using namespace std;

//To check if zero sum subarray exist or not.
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;

    // Store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += arr[i];

        // If prefix sum is 0 or it is already present then return true
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;

        sumSet.insert(sum);
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    string ans;
    if(subArrayExists(arr, n)){
        ans= "Yes";
    }
    else{
        ans= "No";
    }
    
    cout<<ans<<endl;
}

//Time Complexity- O(n)
