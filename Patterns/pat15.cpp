#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int i = n; i >= 1; i--)
    {
        for (char ch = 'A'; ch < 'A'+i; ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}

//pattern result
/*
A B C D E
A B C D
A B C
A B
A
*/
