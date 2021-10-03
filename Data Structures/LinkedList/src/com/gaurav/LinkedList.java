package com.gaurav;

public class LinkedList {
    Node head;
    Node temp;
    public void insert(int data) {
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = null;
        if (head == null) {
            head = newNode;
            temp = newNode;
        } else {
            temp.next=newNode;
            temp=newNode;
        }
    }

    public void insertAtStart(int data)
    {
        Node newNode = new Node();
        newNode.data=data;
        newNode.next=null;
        if (head != null) {
            newNode.next = head;
        }
        head=newNode;
    }
    public void insertAt(int pos, int data)
    {
        if(pos==0)
        {
            insertAtStart(data);
            return;
        }
        Node newNode = new Node();
        newNode.data=data;
        int i=0;
        Node temp = head;
        while(i<pos-1)
        {
            temp=temp.next;
            i++;
        }
        newNode.next=temp.next;
        temp.next=newNode;

    }

    public void show() {
        Node temp = head;
        while (temp.next != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
        System.out.println(temp.data);
    }
}
