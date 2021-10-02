/* Java program to merge two
sorted linked lists */
import java.util.*;
class Node
{
	int data;
	Node next;
	Node(int d) {data = d;
				next = null;}
}
	
class MergeLists
{
Node head;
public void addToTheLast(Node node)
{
	if (head == null)
	{
		head = node;
	}
	else
	{
		Node temp = head;
		while (temp.next != null)
			temp = temp.next;
		temp.next = node;
	}
}

void printList()
{
	Node temp = head;
	while (temp != null)
	{
		System.out.print(temp.data + " ");
		temp = temp.next;
	}
	System.out.println();
}

public static void main(String args[])
{

	MergeLists llist1 = new MergeLists();
	MergeLists llist2 = new MergeLists();
	
	
	llist1.addToTheLast(new Node(5));
	llist1.addToTheLast(new Node(10));
	llist1.addToTheLast(new Node(15));
	
	llist2.addToTheLast(new Node(2));
	llist2.addToTheLast(new Node(3));
	llist2.addToTheLast(new Node(20));
	
	
	llist1.head = new Merge().sortedMerge(llist1.head,
										llist2.head);
	llist1.printList();	
	
}
}

class Merge
{

Node sortedMerge(Node headA, Node headB)
{
	
	Node dummyNode = new Node(0);
	
	Node tail = dummyNode;
	while(true)
	{
	
		if(headA == null)
		{
			tail.next = headB;
			break;
		}
		if(headB == null)
		{
			tail.next = headA;
			break;
		}
		
		if(headA.data <= headB.data)
		{
			tail.next = headA;
			headA = headA.next;
		}
		else
		{
			tail.next = headB;
			headB = headB.next;
		}
		
		tail = tail.next;
	}
	return dummyNode.next;
}
}

