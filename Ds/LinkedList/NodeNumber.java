public class NodeNumber {
 class Node{
	 Node next;
	 int data;
	 
	 Node(int d){
		 this.data=d;
		 this.next=null;
	 }
 }
 
 public Node head=null;
 public Node tail=null;
 
 public void addNode(int data) {
	 Node newNode= new Node(data);
	 
	 if(head==null) {
		 head=newNode;
		 tail=newNode;
	 }
	 else {
		 tail.next=newNode;
		 tail=newNode;}
	 }
 

public int NodeNumber() {
int count=0;
//NOde current will point to head

Node current=head;

while(current!=null) {
	//increment count by 1
count++;
current=current.next;
}

return count;

}

public void Display() {
	Node current=head;
	if(head==null) {
		System.out.print("List is empty");
		return ;
		}
	System.out.print("Nodes in Linked LIst are as follows:");
	while(current!=null) {
		//prints each node by incrementing pointer
		System.out.print(current.data+" ");
		current=current.next;
	}
	}

public static void main(String args[]) {
	NodeNumber list=new NodeNumber();
	list.addNode(12);
	list.addNode(34);
	list.addNode(45);
	list.addNode(23);
	
	list.Display();
	System.out.println();
	System.out.print("Number of nodes are "+ list.NodeNumber());
}
}
