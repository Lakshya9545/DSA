#include <bits/stdc++.h>
using namespace std;
bool Palindrome(int n){
    int lastDigit;
    int reverseNumber = 0;
    int original = n;
    while(n>0){
        lastDigit = n%10;
        n = n/10;
        reverseNumber = reverseNumber*10 + lastDigit;
    }
    if (original == reverseNumber)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main(){
     cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<Palindrome(n)<<endl;
    return 0;
}