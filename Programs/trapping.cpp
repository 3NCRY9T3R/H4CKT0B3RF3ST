#include<iostream>
#include<algorithm> 
using namespace std;

int trappingWater(int arr[], int n){
    int w_unit=0;
    int *left = new int[n];
    int *right = new int[n];

    left[0]=arr[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],arr[i]);
    }

    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]= max(right[i+1],arr[i]);
    }

    for(int i=0;i<n;i++){
        w_unit += min(left[i],right[i])-arr[i];
    }

    return w_unit;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *a = new int[n];
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        cout << trappingWater(a, n) << endl; 
    }
    return 0;
} 