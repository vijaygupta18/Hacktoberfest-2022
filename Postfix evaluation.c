#include<stdio.h>
#include<ctype.h>

#define max 100
#define Postfix 100

int stack[max];
int top=-1;

void push(int n)
{
    if(top>max-1)
    {
        printf("Stack overflow");
        return;
    
    }
    else
   {
       top=top+1;
    stack[top]=n;
}
}

int pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack Underflow");
       
    }
    else
    {
        item=stack[top];
        top=top-1;
        
    }
    return item;
}

void EvalPostfix(char postfix[])
{
     int i;
    char ch;
    int val;
    int A, B;
    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch== '^') 
        {
            A=pop();
            B=pop();
            switch (ch)
            {
            case '^':
                val = B ^ A;
                break;

            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }
            push(val);
        }
    }
    printf("Result is %d\n",pop());
}


int main()
{
   int i;
   char postfix[Postfix];
   printf("Enter postfix expression");
   for (i = 0; i <= Postfix - 1; i++) {
        scanf("%c", &postfix[i]);
if(postfix[i]=='\0')
{
    break;
}
}
EvalPostfix(postfix);
return 0;
}
