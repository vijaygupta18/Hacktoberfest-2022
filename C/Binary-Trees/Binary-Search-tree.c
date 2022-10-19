// Binary Search Tree implementation in c
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct node {
    int val;
    struct node *left;
    struct node *right;
};

// Get a new node
struct node *getNode(int val) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct node *addNode(struct node* node, int val) {
    if (node == NULL) {
        node = getNode(val);
        return node;
    }
    
    if (val <= node->val) {
        node->left = addNode(node->left, val);
    } else {
        node->right = addNode(node->right, val);
    }
    return node;
}

struct node *findNode(struct node* node, int val) {
    while(node != NULL) {
        if (val < node->val) {
            node = node->left;
        } else if (val > node->val) {
            node = node->right;
        } else {
            return node;
        }
    } 

    return NULL;
}

// Helper for Print function
void helper(struct node *node, int level, int isLeft) {
    int i;
    if (node == NULL) return;
    for (i = 0; i < level; i++) {
        printf("  ");
        printf("|"); 
    }
    printf("\n");
    for (i = 0; i < level; i++) {
        printf("  ");
        printf("|"); 
    }
    printf("--%d", node->val);
    isLeft ? printf("(L)\n") : printf("(R)\n");

    helper(node->left, level+1, 1);
    helper(node->right, level+1, 0);
}

void printTree(struct node *root) {
    helper(root, 0, 0);
}

void deleteNode(struct node *node, int val) {
    // Already implemented in java so many times
}

// Recursive
void inorder (struct node *node) {
    if (node == NULL) return; 
    inorder(node->left);
    printf("%d, ", node->val);
    inorder(node->right);
}
// Ith-re-ti-vuh 
// TODO: should've used struct node* stack[SIZE]
void inorderStack (struct node *node) {
    if (node == NULL) return; 
    struct node *root = node;
    struct node *tmp = node;
    int poppedEle;
    while(!stackIsEmpty() || node != NULL) {
        while (node != NULL) {
            stackPush(node->val);
            node = node->left;
        }
        poppedEle = stackPop();
        
        tmp = findNode(root, poppedEle);
        printf("%d, ", poppedEle);
        node = tmp->right;
   }
   printf("\n");
}
void preorderStack (struct node *node) {
    if (node == NULL) return; 
    struct node *root = node;
    struct node *tmp = node;
    int poppedEle;
    while(!stackIsEmpty() || node != NULL) {
        while (node != NULL) {
            printf("%d, ", node->val);
            stackPush(node->val);
            node = node->left;
        }
        poppedEle = stackPop();
        
        tmp = findNode(root, poppedEle);
        node = tmp->right;
   }
   printf("\n");
}

int main()
{
    struct node *root = getNode(45);
    addNode(root, 25);
    addNode(root, 35);
    addNode(root, 15);
    addNode(root, 75);
    inorderStack(root);
    preorderStack(root);
    printTree(root);
    return 0;
}
