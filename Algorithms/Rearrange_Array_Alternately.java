                      Rearrange Array Alternately
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.

BRUTE FORCE:- Keep two pointers at left and right. And alternately               add the elements to the new array
Time:-0(n)
Space:-0(n)

SPACE AND TIME OPTIMISED APPROACH:-

1. Maintain two pointers max and min. Keep max at last element and min at first element
2. MAINTAIN a variable as max_ele=arr[n-1]+1. This is variable containing maxelement+1 
3.Traverse the loop if index is even we have to work on max element 
    3.1 Since we have to integrate both the max         and min values at single ith position.So 
        arr[i]=arr[i]+(arr[max]%max_ele)*max_ele
    3.2 We have kept the max element at ith index so         decrement max
4. if index is odd 
    4.1 Since we have to integrate both the max                and min values at single ith position.So 
        arr[i]=arr[i]+(arr[min]%max_ele)*max_ele
    4.2 We have kept the min element at ith index so         increment min
5. If you keep dividing the element with max_ele you will get alternate pairs as your required ans.
6.If u want to fetch original array from this then do mod with max_ele, you will get original array

CODE:=
  public static void rearrange(int arr[], int n){
        
       int max_ele=arr[n-1] +1;
       int max=n-1;
       int min=0;
       for(int i=0;i<n;i++){
          if(i%2==0){
              arr[i]=arr[i]+(arr[max]%max_ele)*max_ele;
              max--;
          }
          else{
              arr[i]=arr[i]+(arr[min]%max_ele)*max_ele;
              min++;
          }
       }
       
       for(int i=0;i<n;i++){
           arr[i]=arr[i]/max_ele;
       }
        
    }
    
}


