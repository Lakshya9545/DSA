#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}

//pattern result
/*
1 2 3 4
1 2 3
1 2
1
*/