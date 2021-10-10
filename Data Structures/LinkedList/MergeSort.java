/*

    Following is the Node class already written for the Linked List

    class LinkedListNode<T> {
        T data;
        LinkedListNode<T> next;
    
        public LinkedListNode(T data) {
            this.data = data;
        }
    }

*/

public class Solution {
	public static LinkedListNode<Integer> merge(LinkedListNode<Integer> head1,LinkedListNode<Integer> head2) {
		//Your code goes here
         if(head1==null){
            return head2;
        }
        if(head2==null){
            return head1;
        }
      
         LinkedListNode<Integer> head3=null;
        if(head1.data<head2.data){
            head3=head1;
            head1=head1.next;
        }
        else{
             head3=head2;
            head2=head2.next;
        }
      LinkedListNode<Integer> current=head3;
        while(head1!=null && head2!=null){
            if(head1.data<=head2.data){
               current.next= head1;
                 head1=head1.next;
            }else {
                current.next= head2;
                 head2=head2.next;
            }
          current=current.next;
        }
        if(head1==null){
            current.next=head2;
        }else{
            current.next=head1;
        }
        return head3;
	}

    public static LinkedListNode<Integer> mergee(LinkedListNode<Integer> h) {
          if (h == null || h.next == null) {
            return h;
        }
 
        // get the middle of the list
        LinkedListNode<Integer> middle = middle(h);
        LinkedListNode<Integer> nextofmiddle = middle.next;
 
        // set the next of middle LinkedListNode<Integer> to null
        middle.next = null;
 
        // Apply mergeSort on left list
        LinkedListNode<Integer> left = mergee(h);
 
        // Apply mergeSort on right list
        LinkedListNode<Integer> right = mergee(nextofmiddle);
 
        // Merge the left and right lists
        LinkedListNode<Integer> sortedlist = merge(left, right);
        return sortedlist;
    }
    public static LinkedListNode<Integer> middle(LinkedListNode<Integer> head) {
	if (head == null)
            return head;
 
        LinkedListNode<Integer> slow = head, fast = head;
 
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
	}
  
	public static LinkedListNode<Integer> mergeSort(LinkedListNode<Integer> head) {
		if(head==null || head.next==null){
            return head;
        }
       LinkedListNode<Integer> ans = mergee(head);
        return ans;
	}

}
