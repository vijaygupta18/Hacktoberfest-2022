// Single BT threading for easy inorder iterative traversal without aux stack 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
    int isRightThreaded;
};

// Get a new node
struct node *getNode(int val) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct node *getRightestNode(struct node *node) {
    while(node != NULL && node->right != NULL) {
       node = node->right; 
    }
    return node;
}

struct node *parentOf(struct node *root, struct node *node) {
    struct node *tmp = NULL;
    struct node *tmp2 = NULL;
    if (root == NULL || node == NULL) return NULL;
    
    if (root->left == node || root->right == node) {
        return root;
    }
    
    tmp = parentOf(root->left, node);
    tmp2 = parentOf(root->right, node);
    if (tmp == NULL && tmp2 == NULL) {
        return tmp; 
    } else if (tmp != NULL) {
        return tmp;
    } else {
        return tmp2;
    }
}

// This method works without threading
struct node *findInorderSuccesor(struct node* root, struct node* node) {
    struct node *x = NULL;
    struct node *p = NULL;
    if (node == NULL || node == getRightestNode(root)) return NULL;
    
    if (node->right != NULL) {
        return node->right;
    } else {
        x = node; 
        p = parentOf(root, x);
        if (p->left == x) {
            return p;
        } else {
            x = p;   
            p = parentOf(root, x);
            return p;
        }
    }
}

void inorder(struct node *node) {
    if (node == NULL) return;
    while(node->left != NULL) {
        node = node->left;
    }
    while(node != NULL) {
        printf("%d, ", node->val);
        if (node->isRightThreaded == 1) {
            node = node->right;
            if (node != NULL) {
                printf("%d, ", node->val);
                node = node->right;
            }
        }else {
            node = node->right;
        }
    }
}

int main() {
    struct node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    
    // Leaf node -> 4, 5, 6
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->right = getNode(6);
    // Threading Manually 4, 5, 6
    root->left->left->right = findInorderSuccesor(root,root->left->left);
    root->left->right->right = findInorderSuccesor(root,root->left->right);
    root->right->right->right = findInorderSuccesor(root,root->right->right);
    
    inorder(root);
    return 0;
}
