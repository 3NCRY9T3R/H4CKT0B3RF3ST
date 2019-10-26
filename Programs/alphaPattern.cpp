#include<iostream>
using namespace std;


int main(){

    int n;
    char i,j;
    cin >> n;
    for(i='A';i<='A'+(n-1);i++)
    {
        for(j='A';j<=i;j++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}

