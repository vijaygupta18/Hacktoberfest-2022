                   EQUILBRIUM ELEMENT IN ARRAY
ALGORITHM
1.Calculate total sum
2.Keep Rightsum=total sum
3.For each element
  3.1 Rightsum=rightsum-arr[i]{Subtract element from right sum}
  3.2 Comapre{ If equal left sum==right sum ,return the idx}
  3.2 Update leftsum=leftsum+arr[i]

CODE
 public static int equilibriumPoint(long arr[], int n) {

      long left=0,right=0;
      long ts=0;
      for(int i=0;i<arr.length;i++){
          ts+=arr[i];
      }
      int ans=-1;
      right=ts;
      for(int i=0;i<arr.length;i++){
          right=right-arr[i];
          if(right==left){
            ans= i+1;
            break;
          }
          left=left+arr[i];
      }
      return ans;
    }
}
