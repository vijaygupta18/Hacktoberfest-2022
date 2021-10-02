#include<iostream>
#include"nodestatclass.cpp"

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
    node *slow=head;
    node *fast=head->next;
    int mid;
    while(fast!=NULL){
        if(fast->next == NULL)
        break;

        else
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data;
}



int main(){
    // int i=0;
    node *head=input();
    midpos(head);
}