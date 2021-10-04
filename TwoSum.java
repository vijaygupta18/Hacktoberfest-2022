class Solution {
    public int binarySearch(int arr[], int target, int skip)
    {
        //System.out.println(target);
        int low=0;
        int high=arr.length-1;
        int mid=0;
        
        while(low<=high)
        {
           mid=(low+high)/2;
            if(mid==skip)
                if(mid+1<=high)
                    mid++;
                else
                    mid--;
                
           
           if(target>arr[mid])
           {
               low=mid+1;
           }
            else if(target<arr[mid])
            {
                high=mid-1;
            }
            else if(target==arr[mid])
            {
                return mid;
            }
        }
        return -1;
    }
    
    public int[] twoSum(int[] nums, int target) {
        
        int res[]=new int[2];
        int temp;
        
        for(int i=0; i<nums.length && nums[i]<=target; i++)
        {
            temp=binarySearch(nums,target-nums[i],i);
            if(temp!=-1)
            {
                res[0]=i+1;
                res[1]=temp+1;
                return res;
            }
        }
        return res;
    }
}
