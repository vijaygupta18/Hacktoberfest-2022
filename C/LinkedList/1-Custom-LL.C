/* 
	To use Linked List:
	 1) Create Head using createHead(valueForHead)
	 2) InsertNode using addNode(valueForNode)
	 or 
	 See E.g in main

	See Function Prototypes for more (no Docs they're self explanotory)
	-[Note] head pointer is the LinkedList Identifier & that's why you 
	  have to PASS it in every function Modifying the LL.
*/ 

#include <stdio.h>
#include <stdlib.h>

// Node -> Value & Next node pointer 
struct node
{
	int val;
	struct node *next;
};

// Function Prototypes ----------
struct node* reverseList(struct node *head, struct node **memAddressOfHead); 

void printList(struct node *head);
void addNode(struct node *head, int val);

void removeFirst(struct node *head, struct node **memAddressOfHead);
void removeNode(struct node *head, struct node **memAddressOfHead, int val);

struct node* createHead(int val);
struct node* getNode (int val);
void freeMemory(struct node *);

// Main Function ----------
int main () {
	// E.g
	int i;
	struct node *head = createHead(1);
	struct node *head2 = createHead(10);

	for (i = 2; i <= 5; i++)
	{
		addNode(head, i);	
		addNode(head2, i*10);
	}
	printList(head);
	// removeNode(head, &head, 5);
	// printList(head);
	printList(head2);
	freeMemory(head); freeMemory(head2);
	return 0;
}

struct node *reverseList(struct node *node, struct node **memAddressOfHead) {
    if(node == NULL) return  NULL;
	struct node *retNode;
	if (node->next == NULL) {
		// Now *head is pointing->last node (as reversing, so it'll become first now)
	    *memAddressOfHead = node;
		return node;
	}
	retNode = reverseList(node->next, memAddressOfHead);
	retNode->next = node;
	node->next = NULL;
	return node;
}

void printList(struct node *head) {
    if (head == NULL) return;
	// Changing Value of *head will not affect anything as it's a copy of original *head
	printf("Head->");
	while(head->next != NULL) {
		printf("%d->", head->val);
		head = head->next;
	}
	printf("%d->", head->val);
	printf("end \n");
}

void addNode(struct node *head, int val) {
	struct node *newNode = getNode(val);
	while(head->next != NULL) {
		head = head->next;	
	}
	head->next = newNode;	
}

void removeFirst(struct node *head, struct node **memAddressOfHead) {
    if (head == NULL) {
        printf("Empty List... \n");
        return;
    }
    struct node *temp = head;
    head = head->next; 
    *memAddressOfHead = head; 
    printf("%d is removed \n", temp->val);
    free(temp);
}

void removeNode(struct node *head,struct node **memAddressOfHead, int val) {
    if(head == NULL) return;
    if(head->val == val) {
        removeFirst(head, memAddressOfHead);
        return;
    }
    struct node *temp = NULL;
	while(head != NULL && head->next != NULL) {
	    if (head->next->val == val) {
	        temp = head->next;
            head->next = temp->next; 
            printf("%d is removed \n", temp->val);
            free(temp);
	    }
		head = head->next;	
	}
}

struct node* createHead(int val) {
	struct node *head = getNode(val);
	return head;
}

struct node* getNode (int val) {
	struct node *temp = (struct node*)(malloc(sizeof(struct node)));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

void freeMemory(struct node *head) {
	struct node *tmp = NULL;
	while(head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
	printf("\nMemory freed");
}

/*
	Why passing head & memAddressOfHead instead of getting the head from the address
	inside function (like node *head = *memAddressOfHead deferencing)?
	-> Bcoz, original *head will change bcoz of "head = head->next" expression and we
	   don't want that. 
*/