#include <bits/stdc++.h>
using namespace std;

int reverserDigit(int n){
    int lastDigit;
    int reverseNumber = 0;
    while(n>0){
        lastDigit = n%10;
        n = n/10;
        reverseNumber = reverseNumber*10 + lastDigit;
    }
    return reverseNumber;
}

int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<"Reversed number is "<<reverserDigit(n)<<endl;
    return 0;
}