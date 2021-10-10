#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d): data(d), next(NULL) {}
};

void InsertAtEnd(node* &head, int data) {
    node* n = new node(data);
    if (head == NULL) {
        head = n;
    }
    else {
        node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

bool isCyclic(node* head) {
    node* fast = head, *slow = head;
    while (fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
}

void CreateCycle(node* head) {
    node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head->next->next;
}

int main() {

    node* head = NULL, *head1 = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    InsertAtEnd(head, 6);
    InsertAtEnd(head, 7);
    InsertAtEnd(head, 8);
    InsertAtEnd(head, 9);
    InsertAtEnd(head, 10);
    InsertAtEnd(head, 11);
    CreateCycle(head);

    if (isCyclic(head)) {
        cout << "Yes cyclic" << endl;
    }
    else {
        cout << "Not cyclic" << endl;
    }

    return 0;
}