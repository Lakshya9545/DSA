#include <bits/stdc++.h>
using namespace std;

bool countDigits(int n){
    int originalNumber = n;
	int count=0;
	while(n>0){
		int lastDigit = n%10;
        count = count + (lastDigit*lastDigit*lastDigit);
		n = n/10;
	}	
if (count == originalNumber) return true;
else return false;

}

int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<countDigits(n)<<endl;
    return 0;
}

