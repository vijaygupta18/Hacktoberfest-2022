import java.util.*;
class Node{
    int data;
    Node left;
    Node right;
    Node(int d){
        data = d;
    }
}
public class Main
{
	public static void main(String[] args) {
	    Node root = new Node(1);
	    root.left = new Node(3);
	    root.right = new Node(2);
	    root.right.left = new Node(5);
	    root.right.right = new Node(4);
		mirror(root);
		inorder(root);
	}
	public static void mirror(Node root){
	    if(root == null) return ;
	    mirror(root.left);
	    mirror(root.right);
	    Node temp = root.left;
	    root.left = root.right;
	    root.right = temp;
	 
	}
	public static void inorder(Node root){
	    if(root == null) return;
	    inorder(root.left);
	    System.out.print(root.data + " ");
	    inorder(root.right);
	}
}
