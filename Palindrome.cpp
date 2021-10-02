// WAP to check whether given no is palindrome or not.
#include<iostream>
using namespace std;
void pal(int n){
    int rev=0,num,rem;
    num=n;
    while(n!=0){
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    if(num==rev){
        cout<<"The number is Palindrome."<<"\n";
    }
    else{
        cout<<"The number is not a Palindrome."<<"\n";
    }
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    pal(num);
    return 0;
}