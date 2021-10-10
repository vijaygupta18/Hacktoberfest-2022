//Time Complexity: O(n^2)
//Space Complexity: O(n)

class GoodPair {
    public int numIdenticalPairs(int[] nums) {
        int freq[]=new int[nums.length];
        int count=0;
        for(int i=0; i<nums.length; i++)
        {
            for(int j=i+1;j<nums.length; j++)
            {
                if(nums[i]==nums[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
}
