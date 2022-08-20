// Greedy 
#include <bits/stdc++.h>
using namespace std;

int main() 
{  int t; cin>>t;
   while(t--)
   { int m,n;
     cin>>m>>n;
     m--;n--;
     int x[m],y[n];
     for(int i=0;i<m;i++)
     cin>>x[i];
     
     for(int i=0;i<n;i++)
     cin>>y[i];
     
     sort(x,x+m,greater<int>()); //vertical
     sort(y,y+n,greater<int>()); //horizontal
     
     int hcnt=1, vcnt=1;
     int ans=0;
     
     int i=0,j=0;
     while(i<m && j<n)
     {
     	if(x[i]>y[j])
     	{ 
     		ans+= vcnt*x[i];
     		hcnt++;
     		i++;
     	}
     	else
     	{
     		ans+=hcnt*y[j];
     		vcnt++;
     		j++;
     	}
     }
     while(i<m)
     {
     	ans+=x[i]*vcnt;
     	i++;
     }
     
     while(j<n)
     {
     	ans+=y[j]*hcnt;
     	j++;
     }
     
     cout<<ans<<endl;
     
   }
	
	return 0;
}