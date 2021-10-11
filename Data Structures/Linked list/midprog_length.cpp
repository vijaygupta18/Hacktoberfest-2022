#include<iostream>
#include"nodeclass.cpp"

using namespace std;

    node *input(){

    node *head=NULL;
    node *tail=NULL;
    
    int data;
    cin>>data;

    while(data !=-1){
        node *newnode=new node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }

    return head;
    
}

void midpos(node *head){
    node *trav=head;
    node *temp=head;
    int count=0,i=0;
    while(trav!=NULL){
        trav=trav->next;
        count++;
    }
    int mid=(count%2==0)?(count/2)-1:count/2;
    while(i<mid && temp!=NULL){
        temp=temp->next;
        i++;
    }
    cout<<temp->data;
}

int main(){
    node *head=input();
    midpos(head);
}