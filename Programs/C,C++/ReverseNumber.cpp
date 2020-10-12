#include<iostream>
using namespace std;

int main() {
	int n;
    cin >> n;
    
    int revnum = 0;
    while(n != 0)
    {
        int remainder = n % 10;
        
        revnum = revnum*10 + remainder;
        n /= 10;
    }
    
    cout << revnum;
    
    return 0;
    

}
