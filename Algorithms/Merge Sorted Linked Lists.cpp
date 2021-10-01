/*  Merge two sorted Linked List
    head1: 5->7->9
    head2: 4->6->8
    final Output : 4->5->6->7->8->9

*/

#include<iostream>
using namespace std;
#include<stdlib.h>
#include<unistd.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *createLLFromInput(){
    struct Node *Head=NULL,*cur=NULL,*prev=NULL;
    
    int temp,n;
    cout<<"No of elements:";
    cin>>n;
    while(n--){
        cin>>temp;
        cur = (struct Node *)malloc(sizeof(struct Node));
        cur->val = temp;
        cur->next = NULL;
        if(prev)
            prev->next = cur;
        prev=cur;
        if(!Head)
            Head = cur;    
    }
    return Head;
}

void traverseLL(struct Node *Head){
    while(Head){
        cout<<Head->val<<" ";
        Head = Head->next;
    }
    cout<<"\n";
}

struct Node *merge(struct Node *LL1,struct Node *LL2){
    struct Node *Head = NULL;
    if(!LL1)
        return LL2;
    else if(!LL2)
        return LL1;
    else{
        if(LL1->val<=LL2->val){
            Head = LL1;
            Head->next = merge(Head->next,LL2);
        }else{
            Head = LL2;
            Head->next = merge(Head->next,LL1);
        }
    }     
    return Head;
}

int main(){

    struct Node *LL1,*LL2,*merged;
    LL1 = createLLFromInput();
    LL2 = createLLFromInput();
    cout<<"\nLinked list 1 : ";
    traverseLL(LL1);
    cout<<"\nLinked list 2 : ";
    traverseLL(LL2);
    cout<<"\nMerged Linked list : ";
    merged  = merge(LL1,LL2);
    traverseLL(merged);
}
