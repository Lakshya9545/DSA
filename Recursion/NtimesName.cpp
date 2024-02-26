#include <iostream>
#include <string>
using namespace std;

void printname(int n, string name){
static int a = 0; 
    cout << name << endl;
    if (a == n) {
        return;
    }
    else {
        a++;
        printname(n, name);
    }
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    printname(n, name);

    return 0;
}
