#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A'+i; ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}