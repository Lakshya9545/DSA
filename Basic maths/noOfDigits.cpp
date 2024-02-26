#include <bits/stdc++.h>
using namespace std;

int countDigits(int n){
	int count=0;
	while(n>0){
		// int lastDigit = n%10;
		n = n/10;
		count++;
	}	
	return count;
}

/*
another solution 
int countDigits(int n){
	int count = (int)log10(n)+1;
	return count;
}

*/

int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<"Number of digits in "<<n<<" is "<<countDigits(n)<<endl;
    return 0;
}

/*
output 

Enter a number: 2345
Number of digits in 2345 is 4
*/
