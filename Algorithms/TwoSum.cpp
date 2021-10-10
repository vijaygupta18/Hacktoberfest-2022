//Two sum problem using two pointers.

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        while( left!=right )
        {
            if(numbers[left]+numbers[right] == target)
            {
                break;
            }
            else if(numbers[left]+numbers[right] > target) right--;
            else if(numbers[left]+numbers[right] < target) left++;
        }
        vector<int> ans;
        ans.push_back(left+1);
        ans.push_back(right+1);
        return ans;
    }

int main()
{
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> numbers(n);
    for(int i=0; i<n; i++) cin>>numbers[i];
    vector<int> result;
    result = twoSum( numbers, target);
    for(auto it= result.begin(); it!=result.end(); it++)
    {
        cout<<(*it)<< " ";
    }
}

//Done using two pointers in O(n)
