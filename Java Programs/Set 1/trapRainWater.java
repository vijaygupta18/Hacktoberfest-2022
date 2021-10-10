import java.util.*;
public class HelloWorld{

     public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("enter elemnts of array/ height of buildings: ");
        for(int i=0 ; i<n ; i++){
            arr[i] = sc.nextInt();
        }
        int water = trap(arr);
        System.out.println("The amount of water trapped is "+ water);
        sc.close();
        
     }
    public static int trap(int[] height) {
        int water = 0; 
        int n= height.length;
        int dist =0;
        int curr = 0;
        Stack<Integer> st = new Stack<>(); //stores indices
        while(curr < n){
            while(!st.isEmpty() && height[curr] > height[st.peek()]){
                int top = st.pop();
                if(st.isEmpty()) break;
                dist = curr - st.peek() -1;
                int fill = dist * (Math.min(height[st.peek()] , height[curr])-height[top]);
                water += fill;
            }
            st.push(curr++);
        }
        return water;    
    }
}
