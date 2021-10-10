class Solution {
    int rowWithMax1s(int arr[][], int n, int m) {
        
   
        int r=-1;
        int max=0;
        for(int i=0;i<n;i++){
            int onescount=binarysearch(arr,i);
            if(onescount>max){
                max=onescount;
                r=i;
            }
        }
        return r;
    }
    
    int binarysearch(int m[][],int r){
        int low=0;
        int high=m[0].length-1;
        int fil=m[0].length;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(m[r][mid]==1){
                fil=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        int ans=m[0].length-fil;
        return ans;
    }
}
