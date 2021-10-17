class Node:    
    def __init__(self,data):    
        self.data = data    
        self.previous = None   
        self.next = None  

class DLL:
    def __init__(self):
        self.head=None
        self.tail=None
        self.size=0
        
    def addNode(self,data):
        new=Node(data)
        if self.head==None:
            self.head=new
            self.tail=new
            self.head.previous=None
            self.tail.next=None
        else:
            self.tail.next=new
            new.previous=self.tail
            self.tail=new
            self.tail.next=None
        self.size+=1
            
    def printll(self):
        curr=self.head
        while curr is not None:
            print(curr.data,end =" ")
            curr = curr.next 
            
    def rll(self,n):
        if n==0 or n>=self.size:
            return
        if self.head==None:
            return
        curr=self.head
        for i in range(1,n):
            curr=curr.next
        self.tail.next=self.head
        self.head=curr.next
        self.head.previous=None
        self.tail=curr
        self.tail.next=None

a=DLL()
print("ENTER THE ELEMENTS TO BE ADDED IN THE DOUBLY LINKED LIST : ")
l=[int(x) for x in input().split(" ")]
for i in l:
    a.addNode(i)
n=int(input("ENTER HOW MUCH YOU WANT TO ROTATE THE DOUBLY LINKED LIST : "))
a.rll(n)
a.printll()