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

	public static LinkedListNode<Integer> appendLastNToFirst(LinkedListNode<Integer> head, int n) {
		//Your code goes here
        LinkedListNode<Integer> temp = head;
        LinkedListNode<Integer> temp2 = head;
        LinkedListNode<Integer> newNode = head;
        if(head==null)
            return head;
        
        int j=0;
        while(temp2.next!=null)
        {
            temp2=temp2.next;
            
            j++;
        }
        temp2.next=newNode;
        j++;
        int i=0;
        while(i<j-n-1)
        {
            head=head.next;
            i++;
        }
        temp=head.next;
        head.next=null;
        return temp;
	}

}
