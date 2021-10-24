#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n){
    int currentsum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentsum += arr[i];
        if (currentsum <0)
        {
           currentsum=0;
        }
        maxSum = max(maxSum, currentsum);   
    }
    return maxSum;
}

int main(){

    int n;
    cout<<"Enter the Length of Array :";
    cin>>n;

    int arr[n];
    cout<<"Enter the Elements of Array :";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int wrapsum, nonwrapsum ;

    wrapsum = kadane(arr,n);

    int totalsum=0;
    for (int i = 0; i < n ; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    nonwrapsum = totalsum + kadane(arr, n);

    cout<<"Sum of Maximum Subarray :"<<max(wrapsum, nonwrapsum)<<endl;
  
}
