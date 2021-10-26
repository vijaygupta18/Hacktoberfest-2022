#include<bits/stdc++.h>
using namespace std;
bool isOperand(char ch)
{
    if(ch=='+'||ch=='-'|| ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')')
        return false;
    return true;
}
int pre_outstack(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*'|| ch=='/')
        return 3;
    else if(ch=='^')
        return 6;
    else if(ch=='(')
        return 7;
    else
        return 0;
}
int pre_instack(char ch)
{
    if(ch=='+' || ch=='-')
        return 2;
    else if(ch=='*'|| ch=='/')
        return 4;
    else if(ch=='^')
        return 5;
    else
        return 0;
}
char* convert(char infix[])
{
    int i=0,j=0;
    char *postfix=new char[strlen(infix)+2];
    stack<char> st;
    st.push('#');
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(infix[i]==')')
            {
                while(st.top()!='(')
                {
                    postfix[j++]=st.top();
                    st.pop();
                }
                st.pop();
                i++;
            }
            else if(pre_outstack(infix[i])>pre_instack(st.top()))
                st.push(infix[i++]);
            else
            {
                postfix[j++]=st.top();
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        postfix[j++]=st.top();
        st.pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char infix[30];
    cout<<"Enter infix\n";
    cin>>infix;
    char *result=convert(infix);
    result[strlen(result)-1]=0;
    cout<<result<<endl;
    return 0;
}
