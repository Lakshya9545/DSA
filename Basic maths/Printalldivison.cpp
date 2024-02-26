#include <bits/stdc++.h>
using namespace std;

void Divisions(int n){
   
    for ( int i = 1; i <= n; i++)
    {
        if(n%i==0) {
            cout<<i<<endl;
        }
        else{
            continue;
            }
    }

}

int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    Divisions(n);
    return 0;
}