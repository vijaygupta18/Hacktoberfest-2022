#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int>& arr) {
    int ans=0;
    for(int i=1; i<arr.size()-1; i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            int left= i-1;
            int right=i+1;

            while(left-1>=0 && arr[left]>arr[left-1]){
                 left--;
            }
            while(right+1<arr.size() && arr[right+1]<arr[right]){
                 right++;
            }
            int temp= right-left+1;
            ans= max(ans, temp);
            i=right;
        }
    }
    return ans;
}

int main()
{
    int N; //size of array
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    
    int res= longestMountain(arr);
  
    cout<<res<<endl;
}  

