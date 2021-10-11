//Time Complexity: O(n log n)
//Space Complexity: O(n)

class Solution {
    public int heightChecker(int[] heights) {
        
        int expectedHeight[]=heights.clone();
        
        /*for(int i=0; i<heights.length; i++)
            System.out.println(expectedHeight[i]);
        */
        
        Arrays.sort(expectedHeight);
       
        /* for(int i=0; i<heights.length; i++)
            System.out.println("* "+expectedHeight[i]+" -- "+heights[i]);
        */
        
        int count=0;
        for(int i=0; i<heights.length; i++)
            if(expectedHeight[i]!=heights[i])
                count++;
        
        //System.out.println(expectedHeight);
        return count;
    }
}
