/*

Given an array A of N integers. The task is to find a peak element in A in O( log N ) .
An array element is peak if it is not smaller than its neighbours. For corner elements, consider only one neighbour.

Example 1:

Input:
N = 3
A[] = {1,2,3}
Output: 2 
Explanation: In the given array, 
3 is the peak element as it is 
greater than its neighbour.
Example 2:

Input:
N = 2
A[] = {3,4}
Output: 1
Explanation: 4 is the peak element 
as it is greater than its neighbour 
elements.
Your Task:
You don't have to read input or print anything. Just complete the provided function peakElement() and return a valid index with respect to 0 based indexing.
Note 1: Multiple peak element may be possible, in that case return any of the valid index .
Note 2: If you click on Compile and Test the output will be 1 if the index that you return is correct. Otherwise output will be 0. 

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 105
1 <= A[] <= 106

*/

/* Example:

Input: array[]= {5, 10, 20, 15}
Output: 20
The element 20 has neighbours 10 and 15,
both of them are less than 20.

Input: array[] = {10, 20, 15, 2, 23, 90, 67}
Output: 20 or 90
The element 20 has neighbours 10 and 15, 
both of them are less than 20, similarly 90 has neighbous 23 and 67.
*/



#include<iostream>
using namespace std;

int findPeakUtil(int arr[], int low, int high, int n){ 
    int mid = low + (high - low) / 2; 
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) 
        return mid; 
    else if (mid > 0 && arr[mid - 1] > arr[mid]) 
        return findPeakUtil(arr, low, (mid - 1), n); 
    else
        return findPeakUtil( 
            arr, (mid + 1), high, n); 
} 


/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int arr[], int n)
{
   // Your code here
   return findPeakUtil(arr, 0, n-1,n);
}

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        int *a = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 && a[0]>=a[1])
		f=1;
		else if(A==n-1 && a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] && a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}  // } Driver Code Ends
