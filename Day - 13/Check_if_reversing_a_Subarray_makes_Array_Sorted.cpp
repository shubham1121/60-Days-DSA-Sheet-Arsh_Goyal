// T.C -: O(N) & S.C -: O(1)
#include <bits/stdc++.h>
using namespace std;

bool checkReverse(int a[],int n)
{
    if(n==1)
     return true;
     
    int i=1;
    while(i<n)
    {
        if(a[i-1]<a[i]) i++;
        else
        break;
    }
    if(i==n)
     return true;
    
    int j = i;
    while(j<n && a[j]<a[j-1])
    {
        if(i>1 && a[j]<a[i-2])
         return false;
      j++;
    }
    if(j==n)
     return true;
    int k=j;
    
    if(a[k]<a[i-1])
     return false;
    
    while(k>1 && k<n)
    {
        if(a[k]<a[k-1])
         return false;
      k++;
    }
    return true;
}

int main()
{
    int arr[] = {10,20,30,40,4,3,2,50,60,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    checkReverse(arr, n)? cout << "Yes" : cout << "No";
    return 0;
}
