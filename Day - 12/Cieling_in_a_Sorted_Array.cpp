// T.C -: O(N)  S.C -: O(1)

#include <bits/stdc++.h>
using namespace std;
int ceilSearch(int arr[], int low, int high, int x)
{  int idx=-1;
    for(int i=low;i<=high;i++)
    {
        if(arr[i]==x)
        {
            idx=i; break;
        }
        else if(arr[i]>x)
        {idx=i; break;}
    }
    
	return idx;
}

int main()
{
	int arr[] = {1, 2, 8, 10, 10, 12, 19};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 10;
	int index = ceilSearch(arr, 0, n-1, x);
	if(index == -1)
		cout << "Ceiling of " << x << " doesn't exist in array ";
	else
		cout << "ceiling of " << x << " is " << arr[index];
	
	return 0;
}

// T.C -: O(N)  S.C -: O(1)

#include <bits/stdc++.h>
using namespace std;

int ceilSearch(int arr[], int low, int high, int x)
{  
    while(low<=high)
    {
        int mid = low +  (high-low)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return arr[low]>x ? low : -1;
}

int main()
{
	int arr[] = {1, 2, 8, 10, 10, 12, 19};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 0;
	int index = ceilSearch(arr, 0, n-1, x);
	if(index == -1)
		cout << "Ceiling of " << x << " doesn't exist in array ";
	else
		cout << "ceiling of " << x << " is " << arr[index];
	
	return 0;
}
