// T.C -: O(NLogN) S.C -: O(1) Binary Search
#include <bits/stdc++.h>
using namespace std;
 
bool checkMinDist(int a[],int n, int maxiD,int c)
{ int currPos = a[0], cntC=1;
  for(int i=1;i<n;i++)
  {
  	if(a[i]-currPos>=maxiD)
  	{
  		cntC++;
  		currPos = a[i];
  	}
  	if(cntC==c)
  	{
  		return true;
  	}
  }
	return false;
}
 
int main() {
	int t; cin>>t;
	while(t--)
	{ int n,c;
	  cin>>n>>c;
	  int a[n];
	  for(int i=0;i<n;i++)
	  {
	  	cin>>a[i];
	  }
	  sort(a,a+n);
	  int low = 1, high = a[n-1]-a[0];
	  int ans=0;
	  while(low<high)
	  {
	  	int mid = (high+low)/2;
	  	if(checkMinDist(a,n,mid,c))
	  	{
	  		ans=max(ans,mid);
	  		low=mid+1;
	  	}
	  	else
	  	{
	  		high=mid-1;
	  	}
	  }
	  cout<<ans+1<<endl;
		
	}
	return 0;
} 