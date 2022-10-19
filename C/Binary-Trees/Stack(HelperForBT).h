// Integer Stack Implementation in c
#define SIZE 15
int stack[SIZE];
int top = -1;

int stackIsFull() {
    return top >= SIZE-1;
}

void stackPush(int val) {
    if (stackIsFull()) {
        printf("Make stack bigger \n");
        return;
    }
    top++;
    stack[top] = val; 
}

int stackIsEmpty() {
    return (top == -1);
}

int stackPop() {
    if (stackIsEmpty()) {
        printf("Stack is empty \n");
        return -1;
    }
    top--;
    return stack[top+1];
}

int stackPeek() {
    if (stackIsEmpty()) {
        printf("Stack is empty \n");
        return -1;
    }
    printf("peek -> %d", stack[top]);
    return stack[top];
}

void stackPrint() {
    if (stackIsEmpty()) {
        printf("Nothing to print \n");
        return;
    }
    int i = top; 
    printf("\n");
    while(i >= 0) {
        printf(" | %d |\n", stack[i]);
        i--;
    }
    printf(" '''''\n");
}
